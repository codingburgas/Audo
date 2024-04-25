#include "tests.hpp"

returnType SubmitTest(CppHttp::Net::Request& req) {
	soci::session* db = Database::GetInstance()->GetSession();
	std::string token = CppHttp::Utils::GetHeader(req.m_info.original, "Authorization");

	// Remove Bearer
	token.erase(0, 7);

	if (token == "") {
		return std::make_tuple(CppHttp::Net::ResponseType::NOT_AUTHORIZED, "Missing token", std::nullopt);
	}

	jwt::verifier<jwt::default_clock, jwt::traits::nlohmann_json> verifier = jwt::verify<jwt::traits::nlohmann_json>().allow_algorithm(jwt::algorithm::rs512{ "", rsaSecret, "", "" }).with_issuer("auth0");
	auto decodedToken = jwt::decode<jwt::traits::nlohmann_json>(token);

	std::error_code ec;
	verifier.verify(decodedToken, ec);

	if (ec) {
		std::cout << "\033[1;31m[-] Error: " << ec.message() << "\033[0m\n";
		return std::make_tuple(CppHttp::Net::ResponseType::INTERNAL_ERROR, ec.message(), std::nullopt);
	}

	json tokenJson = decodedToken.get_payload_json();
	std::string userId = tokenJson["id"];

	*db << "SELECT id FROM users WHERE id = :id", soci::use(std::stoi(userId));

	if (!db->got_data()) {
		return std::make_tuple(CppHttp::Net::ResponseType::NOT_AUTHORIZED, "Unathorized", std::nullopt);
	}

	json body;

	try {
		body = json::parse(req.m_info.body);
	}
	catch (json::exception& e) {
		return std::make_tuple(CppHttp::Net::ResponseType::BAD_REQUEST, e.what(), std::nullopt);
	}
	std::string subject = body["subject"];

	/*
		body structure:
		{
			"subject": "math" || "history" || "physics",
			"answers": [
				{
					"question": "What is 5+35+3?",
					"answer": "43"
				},
				{
					"question": "Solve for x in the equation 2x + 4 = 10.",
					"answer": "3"
				},
				...
			]
		}
	*/

	int questionsAnswered = 0;

	if (subject == "math") {
		for (auto& answer : body["answers"]) {
			std::string question = answer["question"];
			std::string correctAnswer = mathQA.at(question);
			std::string userAnswer = answer["answer"];
			std::cout << (correctAnswer == userAnswer) << std::endl;

			if (correctAnswer == userAnswer) {
				questionsAnswered++;
			}
		}

	}
	else if (subject == "physics") {
		for (auto& answer : body["answers"]) {
			std::string question = answer["question"];
			std::string correctAnswer = physicsQA.at(question);
			std::string userAnswer = answer["answer"];

			if (correctAnswer == userAnswer) {
				questionsAnswered++;
			}
		}
	}
	else if (subject == "history") {
		for (auto& answer : body["answers"]) {
			std::string question = answer["question"];
			std::string correctAnswer = historyQA.at(question);
			std::string userAnswer = answer["answer"];

			if (correctAnswer == userAnswer) {
				questionsAnswered++;
			}
		}
	}
	else {
		return std::make_tuple(CppHttp::Net::ResponseType::BAD_REQUEST, "Invalid subject", std::nullopt);
	}
	double score = ((float)questionsAnswered / 11.f) * 100;

	// truncate to 2 decimal places
	score = std::floor(score * 100) / 100;
	Test test;

	*db << "SELECT * FROM tests WHERE user_id = :user_id", use(std::stoi(userId)), into(test);
	std::cout << "hdisydias\n";

	if (db->got_data()) {
		*db << "UPDATE tests SET score = :score WHERE user_id = :user_id AND subject = :subject RETURNING *", use(score), use(std::stoi(userId)), use(subject), into(test);
	}
	else {
		*db << "INSERT INTO tests (id, user_id, score, subject) VALUES (DEFAULT, :user_id, :score, :subject) RETURNING *", use(std::stoi(userId)), use(score), use(subject), into(test);
	}

	json response;
	response["score"] = test.score;
	response["subject"] = test.subject;
	response["user_id"] = test.user_id;
	response["id"] = test.id;

	return std::make_tuple(CppHttp::Net::ResponseType::JSON, response.dump(4), std::nullopt);
}

returnType GetTests(CppHttp::Net::Request& req) {
	soci::session* db = Database::GetInstance()->GetSession();
	std::string token = CppHttp::Utils::GetHeader(req.m_info.original, "Authorization");

	// Remove Bearer
	token.erase(0, 7);

	if (token == "") {
		return std::make_tuple(CppHttp::Net::ResponseType::NOT_AUTHORIZED, "Missing token", std::nullopt);
	}

	jwt::verifier<jwt::default_clock, jwt::traits::nlohmann_json> verifier = jwt::verify<jwt::traits::nlohmann_json>().allow_algorithm(jwt::algorithm::rs512{ "", rsaSecret, "", "" }).with_issuer("auth0");
	auto decodedToken = jwt::decode<jwt::traits::nlohmann_json>(token);

	std::error_code ec;
	verifier.verify(decodedToken, ec);

	if (ec) {
		std::cout << "\033[1;31m[-] Error: " << ec.message() << "\033[0m\n";
		return std::make_tuple(CppHttp::Net::ResponseType::INTERNAL_ERROR, ec.message(), std::nullopt);
	}

	json tokenJson = decodedToken.get_payload_json();
	std::string userId = tokenJson["id"];

	*db << "SELECT id FROM users WHERE id = :id", soci::use(std::stoi(userId));

	if (!db->got_data()) {
		return std::make_tuple(CppHttp::Net::ResponseType::NOT_AUTHORIZED, "Unathorized", std::nullopt);
	}

	std::vector<Test> tests;
	soci::rowset<Test> rsClassrooms = (db->prepare << "SELECT * FROM tests WHERE user_id = :user_id", use(std::stoi(userId)));
	for (rowset<Test>::const_iterator it = rsClassrooms.begin(); it != rsClassrooms.end(); ++it) {
		tests.push_back(*it);
	}

	json response;
	for (auto& test : tests) {
		json testJson;
		testJson["score"] = test.score;
		testJson["subject"] = test.subject;
		testJson["user_id"] = test.user_id;
		testJson["id"] = test.id;
		response["tests"].push_back(testJson);
	}

	return std::make_tuple(CppHttp::Net::ResponseType::JSON, response.dump(4), std::nullopt);
}

returnType GetRankings(CppHttp::Net::Request& req) {
	soci::session* db = Database::GetInstance()->GetSession();
	std::string token = CppHttp::Utils::GetHeader(req.m_info.original, "Authorization");

	// Remove Bearer
	token.erase(0, 7);

	if (token == "") {
		return std::make_tuple(CppHttp::Net::ResponseType::NOT_AUTHORIZED, "Missing token", std::nullopt);
	}

	jwt::verifier<jwt::default_clock, jwt::traits::nlohmann_json> verifier = jwt::verify<jwt::traits::nlohmann_json>().allow_algorithm(jwt::algorithm::rs512{ "", rsaSecret, "", "" }).with_issuer("auth0");
	auto decodedToken = jwt::decode<jwt::traits::nlohmann_json>(token);

	std::error_code ec;
	verifier.verify(decodedToken, ec);

	if (ec) {
		std::cout << "\033[1;31m[-] Error: " << ec.message() << "\033[0m\n";
		return std::make_tuple(CppHttp::Net::ResponseType::INTERNAL_ERROR, ec.message(), std::nullopt);
	}

	json tokenJson = decodedToken.get_payload_json();
	std::string userId = tokenJson["id"];

	*db << "SELECT id FROM users WHERE id = :id", soci::use(std::stoi(userId));

	if (!db->got_data()) {
		return std::make_tuple(CppHttp::Net::ResponseType::NOT_AUTHORIZED, "Unathorized", std::nullopt);
	}

	std::vector<UserScore> userScores;
	soci::rowset<UserScore> rsUserScores = (db->prepare << "SELECT tests.user_id, CONCAT(users.fname, ' ', users.lname) AS full_name, SUM(score) AS total_score FROM tests INNER JOIN users ON users.id=tests.user_id GROUP BY tests.user_id, users.fname, users.lname ORDER BY total_score DESC");
	for (rowset<UserScore>::const_iterator it = rsUserScores.begin(); it != rsUserScores.end(); ++it) {
		userScores.push_back(*it);
	}

	json response;
	for (auto& userScore : userScores) {
		json userScoreJson;
		userScoreJson["user_id"] = userScore.user_id;
		userScoreJson["total_score"] = userScore.score;
		response["rankings"].push_back(userScoreJson);
	}

	return std::make_tuple(CppHttp::Net::ResponseType::JSON, response.dump(4), std::nullopt);
}
#include "grades.hpp"

returnType GetGrades(CppHttp::Net::Request& req) {
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

	json body;

	try {
		body = json::parse(req.m_info.body);
	}
	catch (json::exception& e) {
		return std::make_tuple(CppHttp::Net::ResponseType::BAD_REQUEST, e.what(), std::nullopt);
	}

	int roomId = body["room_id"];

	std::vector<Grade> grades;
	soci::rowset<Grade> rsClassrooms = (db->prepare << "SELECT * FROM grades WHERE student_id = :student_id AND room_id = :room_id", use(std::stoi(userId)), use(roomId));
	for (rowset<Grade>::const_iterator it = rsClassrooms.begin(); it != rsClassrooms.end(); ++it) {
		grades.push_back(*it);
	}

	json response;

	for (auto& grade : grades) {
		char timeString[std::size("yyyy-mm-ddThh:mm:ssZ")];
		std::strftime(timeString, std::size(timeString), "%FT%TZ", &grade.date);
		json gradeJson;
		gradeJson["id"] = grade.id;
		gradeJson["score"] = grade.score;
		gradeJson["subject"] = grade.subject;

		response.push_back(gradeJson);
	}

	return std::make_tuple(CppHttp::Net::ResponseType::JSON, response.dump(4), std::nullopt);
}

returnType AddGrade(CppHttp::Net::Request& req) {
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
	std::string ownerId = tokenJson["id"];
	std::string status;
	int roomOwnerId = 0;

	json body;

	try {
		body = json::parse(req.m_info.body);
	}
	catch (json::exception& e) {
		return std::make_tuple(CppHttp::Net::ResponseType::BAD_REQUEST, e.what(), std::nullopt);
	}

	std::string subject = body["subject"];
	int score = body["score"];
	std::string description = body["description"];
	int studentId = body["student_id"];
	int roomId = body["room_id"];

	*db << "SELECT users.status, classrooms.owner_id FROM users INNER JOIN classrooms ON users.id=classrooms.owner_id WHERE classrooms.id = :room_id", soci::use(roomId), into(status), into(roomOwnerId);

	if (!db->got_data() || (status != "teacher" || roomOwnerId != std::stoi(ownerId))) {
		return std::make_tuple(CppHttp::Net::ResponseType::NOT_AUTHORIZED, "Unathorized", std::nullopt);
	}

	if (subject == "" || description == "" || studentId == 0) {
		return std::make_tuple(CppHttp::Net::ResponseType::BAD_REQUEST, "Missing required fields", std::nullopt);
	}

	Grade grade;
	*db << "INSERT INTO grades (id, student_id, subject, date_of_creation, description, score, room_id) VALUES (DEFAULT, :student_id, :subject, DEFAULT, :description, :score, :room_id) RETURNING *", use(studentId), use(subject), use(description), use(score), use(roomId), into(grade);

	char timeString[std::size("yyyy-mm-ddThh:mm:ssZ")];
	std::strftime(timeString, std::size(timeString), "%FT%TZ", &grade.date);
	
	json response;

	response["id"] = grade.id;
	response["student_id"] = grade.student_id;
	response["subject"] = grade.subject;
	response["date_of_creation"] = timeString;
	response["description"] = grade.description;
	response["score"] = grade.score;
	response["room_id"] = grade.room_id;

	return std::make_tuple(CppHttp::Net::ResponseType::JSON, response.dump(4), std::nullopt);
}

returnType GetGrade(CppHttp::Net::Request& req) {
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
	std::string ownerId = tokenJson["id"];

	json body;

	try {
		body = json::parse(req.m_info.body);
	}
	catch (json::exception& e) {
		return std::make_tuple(CppHttp::Net::ResponseType::BAD_REQUEST, e.what(), std::nullopt);
	}
	
	int gradeId = body["grade_id"];
	std::string teacher, subject, description;
	int score;
	std::tm date;
	*db << R"(SELECT CONCAT(users.fname, ' ', users.lname) AS teacher, grades.subject, grades.date_of_creation, grades.description, grades.score 
FROM grades 
INNER JOIN classrooms ON classrooms.id = grades.room_id 
INNER JOIN users ON users.id = classrooms.owner_id 
WHERE grades.id = :grade_id)", use(gradeId), into(teacher), into(subject), into(date), into(description), into(score);

	if (!db->got_data()) {
		return std::make_tuple(CppHttp::Net::ResponseType::NOT_FOUND, "Grade not found", std::nullopt);
	}

	char timeString[std::size("yyyy-mm-ddThh:mm:ssZ")];
	std::strftime(timeString, std::size(timeString), "%FT%TZ", &date);

	json response;
	response["teacher"] = teacher;
	response["subject"] = subject;
	response["date_of_creation"] = timeString;
	response["description"] = description;
	response["score"] = score;

	return std::make_tuple(CppHttp::Net::ResponseType::JSON, response.dump(4), std::nullopt);
}

returnType DeleteGrade(CppHttp::Net::Request& req) {
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

	json body;

	try {
		body = json::parse(req.m_info.body);
	}
	catch (json::exception& e) {
		return std::make_tuple(CppHttp::Net::ResponseType::BAD_REQUEST, e.what(), std::nullopt);
	}

	int gradeId = body["grade_id"];
	std::string status;
	int ownerId;

	*db << R"(SELECT users.status, classrooms.owner_id
FROM grades
INNER JOIN classrooms
ON classrooms.id = grades.room_id
INNER JOIN users
ON classrooms.owner_id = users.id
WHERE grades.id = :grade_id)", use(gradeId), into(status), into(ownerId);

	if (!db->got_data() || (status != "teacher" || ownerId != std::stoi(userId))) {
		return std::make_tuple(CppHttp::Net::ResponseType::NOT_AUTHORIZED, "Unauthorized", std::nullopt);
	}

	Grade grade;

	*db << "DELETE FROM grades WHERE id = :grade_id RETURNING *", use(gradeId), into(grade);

	if (!db->got_data()) {
		return std::make_tuple(CppHttp::Net::ResponseType::NOT_FOUND, "Grade not found", std::nullopt);
	}

	char timeString[std::size("yyyy-mm-ddThh:mm:ssZ")];
	std::strftime(timeString, std::size(timeString), "%FT%TZ", &grade.date);

	json gradeJson;
	gradeJson["id"] = gradeId;
	gradeJson["student_id"] = grade.student_id;
	gradeJson["subject"] = grade.subject;
	gradeJson["date_of_creation"] = timeString;
	gradeJson["description"] = grade.description;
	gradeJson["score"] = grade.score;
	gradeJson["room_id"] = grade.room_id;

	return std::make_tuple(CppHttp::Net::ResponseType::JSON, gradeJson.dump(4), std::nullopt);
}

returnType GetStudentGrades(CppHttp::Net::Request& req) {
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

	json body;

	try {
		body = json::parse(req.m_info.body);
	}
	catch (json::exception& e) {
		return std::make_tuple(CppHttp::Net::ResponseType::BAD_REQUEST, e.what(), std::nullopt);
	}

	int studentId = body["student_id"];
	int roomId = body["room_id"];
	std::string status;
	int ownerId;

	*db << "SELECT users.status, classrooms.owner_id FROM users INNER JOIN classrooms ON users.id=classrooms.owner_id WHERE classrooms.id = :room_id", soci::use(roomId), into(status), into(ownerId);

	if (!db->got_data()) {
		return std::make_tuple(CppHttp::Net::ResponseType::NOT_FOUND, "Room not found", std::nullopt);
	}

	if (status != "teacher" || ownerId != std::stoi(userId)) {
		return std::make_tuple(CppHttp::Net::ResponseType::NOT_AUTHORIZED, "Unauthorized", std::nullopt);
	}

	std::vector<Grade> grades;
	soci::rowset<Grade> rsClassrooms = (db->prepare << "SELECT * FROM grades WHERE student_id = :student_id AND room_id = :room_id", use(studentId), use(roomId));
	for (rowset<Grade>::const_iterator it = rsClassrooms.begin(); it != rsClassrooms.end(); ++it) {
		grades.push_back(*it);
	}

	json response;
	for (auto& grade : grades) {
		char timeString[std::size("yyyy-mm-ddThh:mm:ssZ")];
		std::strftime(timeString, std::size(timeString), "%FT%TZ", &grade.date);
		json gradeJson;
		gradeJson["id"] = grade.id;
		gradeJson["score"] = grade.score;

		response.push_back(gradeJson);
	}

	return std::make_tuple(CppHttp::Net::ResponseType::JSON, response.dump(4), std::nullopt);
}
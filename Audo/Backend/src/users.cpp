#include "users.hpp"

returnType Register(CppHttp::Net::Request& req) {
	soci::session* db = Database::GetInstance()->GetSession();

	json body;
	try {
		body = json::parse(req.m_info.body);
	}
	catch (json::parse_error& e) {
		return std::make_tuple(CppHttp::Net::ResponseType::BAD_REQUEST, e.what(), std::nullopt);
	}

	std::string fName = body["first_name"];
	std::string lName = body["last_name"];
	std::string password = body["password"];
	std::string email = body["email"];
	std::string status = body["status"];
	std::string school = body["school"];

	//Validate data
	if (fName == "" || lName == "" || password == "" || email == "" || status == "" || school == "") {
		return std::make_tuple(CppHttp::Net::ResponseType::BAD_REQUEST, "Missing required fields", std::nullopt);
	}

	if (fName.length() < 3 || lName.length() < 3 || password.length() < 3 || email.length() < 3 || school.length() < 3 || status.length() < 3) {
		return std::make_tuple(CppHttp::Net::ResponseType::BAD_REQUEST, "Fields must be more than 3 characters", std::nullopt);
	}

	if (fName.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") != std::string::npos) {
		return std::make_tuple(CppHttp::Net::ResponseType::BAD_REQUEST, "First name must only contain letters", std::nullopt);
	}

	if (lName.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") != std::string::npos) {
		return std::make_tuple(CppHttp::Net::ResponseType::BAD_REQUEST, "Last name must only contain letters", std::nullopt);
	}

	if (email.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789@.") != std::string::npos) {
		return std::make_tuple(CppHttp::Net::ResponseType::BAD_REQUEST, "Email must only contain letters, numbers, @ and .", std::nullopt);
	}

	if (email.find_first_of("@") == std::string::npos) {
		return std::make_tuple(CppHttp::Net::ResponseType::BAD_REQUEST, "Email must contain @", std::nullopt);
	}

	if (email.find_first_of(".") == std::string::npos) {
		return std::make_tuple(CppHttp::Net::ResponseType::BAD_REQUEST, "Email must contain .", std::nullopt);
	}

	if (password.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!#$%^&*") != std::string::npos) {
		return std::make_tuple(CppHttp::Net::ResponseType::BAD_REQUEST, "Password must only contain letters, numbers, !, #, $, %, ^, & and *", std::nullopt);
	}

	if (status != "student" && status != "teacher") {
		return std::make_tuple(CppHttp::Net::ResponseType::BAD_REQUEST, "Status must be student or teacher", std::nullopt);
	}

	if (school.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789") != std::string::npos) {
		return std::make_tuple(CppHttp::Net::ResponseType::BAD_REQUEST, "School must only contain letters and numbers", std::nullopt);
	}

	User user;
	indicator ind;

	*db << "SELECT * FROM users WHERE email = :email", into(user, ind), use(email);

	//std::cout << "User: " << user.email << std::endl;

	if (db->got_data()) {

		return std::make_tuple(CppHttp::Net::ResponseType::ALREADY_EXISTS, "User with email " + email + " already exists", std::nullopt);
	}

	*db << "SELECT last_value FROM users_id_seq", into(user.id);

	//std::cout << "\033[1;34m[*] User id: " << user.id << "\033[0m\n";

	long long int id = (user.id + 1) * 52834;

	password = email + password + std::to_string(id) + secret;

	std::string hashedSalted = Hash(password);

	//std::cout << "Hashed: " << hashedSalted << std::endl;

	*db << "INSERT INTO users (id, fname, lname, email, password, status, school) VALUES (DEFAULT, :fname, :lname, :email, :password, :status, :school)", use(fName), use(lName), use(email), use(hashedSalted), use(status), use(school);

	// get the register email html template from ../templates/register.html
	std::ifstream file("./templates/register.html");
	std::stringstream buffer;
	buffer << file.rdbuf();
	std::string html;

	// replace the placeholders in the html template with the user's data
	html = std::regex_replace(buffer.str(), std::regex("\\{\\{first_name\\}\\}"), fName);
	html = std::regex_replace(html, std::regex("\\{\\{last_name\\}\\}"), lName);

	// send the email
	cpr::Response r = cpr::Post(cpr::Url{ "https://api.eu.mailgun.net/v3/audovscpi.live/messages" },
		cpr::Authentication{ mailgunUsername, mailgunPassword, cpr::AuthMode::BASIC },
		cpr::Multipart{
			{"from", "noreply@audovscpi.live"},
			{"to", email},
			{"subject", "Welcome to Audo"},
			{"html", html}
		}
	);

	json userOutput;
	userOutput["fname"] = fName;
	userOutput["lname"] = lName;
	userOutput["email"] = email;
	userOutput["status"] = status;
	userOutput["school"] = school;

	return std::make_tuple(CppHttp::Net::ResponseType::JSON, userOutput.dump(4), std::nullopt);
}

returnType Login(CppHttp::Net::Request& req) {
	soci::session* db = Database::GetInstance()->GetSession();

	json body;
	try {
		body = json::parse(req.m_info.body);
	}
	catch (json::parse_error& e) {
		return std::make_tuple(CppHttp::Net::ResponseType::BAD_REQUEST, e.what(), std::nullopt);
	}

	std::string email = body["email"];
	std::string password = body["password"];


	if (email == "" || password == "") {
		return std::make_tuple(CppHttp::Net::ResponseType::BAD_REQUEST, "Missing required fields", std::nullopt);
	}

	User user;
	indicator ind;

	*db << "SELECT * FROM users WHERE email = :email", into(user, ind), use(email);

	if (!db->got_data()) {
		return std::make_tuple(CppHttp::Net::ResponseType::NOT_FOUND, "User with email " + email + " not found", std::nullopt);
	}

	std::string hashedSalted = Hash(email + password + std::to_string((user.id) * 52834) + secret);

	if (hashedSalted != user.password) {
		return std::make_tuple(CppHttp::Net::ResponseType::BAD_REQUEST, "Incorrect password", std::nullopt);
	}

	auto jwtToken = jwt::create<jwt::traits::nlohmann_json>()
		.set_issuer("auth0")
		.set_type("JWT")
		.set_payload_claim("id", std::to_string(user.id))
		.set_payload_claim("email", email)
		.set_expires_at(std::chrono::system_clock::now() + std::chrono::hours{ 24 })
		.set_issued_at(std::chrono::system_clock::now());

	std::string signedToken = jwtToken.sign(jwt::algorithm::rs512{ "", rsaSecret, "", "" });

	json token;
	token["token"] = signedToken;

	return std::make_tuple(CppHttp::Net::ResponseType::JSON, token.dump(4), std::nullopt);
}

returnType GetUser(CppHttp::Net::Request& req) {
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
	std::string id = tokenJson["id"];

	User user;
	indicator ind;

	*db << "SELECT * FROM users WHERE id = :id", into(user, ind), use(id);

	if (ind == indicator::i_null) {
		return std::make_tuple(CppHttp::Net::ResponseType::NOT_FOUND, "User with id " + id + " not found", std::nullopt);
	}

	json userOutput;
	userOutput["fname"] = user.fname;
	userOutput["lname"] = user.lname;
	userOutput["email"] = user.email;
	userOutput["status"] = user.status;
	userOutput["school"] = user.school;

	return std::make_tuple(CppHttp::Net::ResponseType::JSON, userOutput.dump(4), std::nullopt);
}

returnType DeleteUser(CppHttp::Net::Request& req) {
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
	std::string id = tokenJson["id"];

	User user;
	indicator ind;

	*db << "SELECT * FROM users WHERE id = :id", into(user, ind), use(id);

	if (ind == indicator::i_null) {
		return std::make_tuple(CppHttp::Net::ResponseType::NOT_FOUND, "User with id " + id + " not found", std::nullopt);
	}

	*db << "DELETE FROM users WHERE id = :id", use(id);

	if (ind == indicator::i_null) {
		return std::make_tuple(CppHttp::Net::ResponseType::INTERNAL_ERROR, "Failed to delete user. Please try again", std::nullopt);
	}

	json userOutput;
	userOutput["fname"] = user.fname;
	userOutput["lname"] = user.lname;
	userOutput["email"] = user.email;
	userOutput["status"] = user.status;
	userOutput["school"] = user.school;

	return std::make_tuple(CppHttp::Net::ResponseType::JSON, userOutput.dump(4), std::nullopt);
}

returnType UpdateUser(CppHttp::Net::Request& req) {
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

	std::string fName = body["first_name"];
	std::string lName = body["last_name"];
	std::string email = body["email"];
	std::string password = body["password"];

	if (fName == "" || lName == "" || email == "" || password == "") {
		return std::make_tuple(CppHttp::Net::ResponseType::BAD_REQUEST, "Missing required fields", std::nullopt);
	}

	if (fName.length() < 3 || lName.length() < 3 || email.length() < 3 || password.length() < 3) {
		return std::make_tuple(CppHttp::Net::ResponseType::BAD_REQUEST, "Fields must be more than 3 characters", std::nullopt);
	}

	if (fName.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") != std::string::npos) {
		return std::make_tuple(CppHttp::Net::ResponseType::BAD_REQUEST, "First name must only contain letters", std::nullopt);
	}

	if (lName.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") != std::string::npos) {
		return std::make_tuple(CppHttp::Net::ResponseType::BAD_REQUEST, "Last name must only contain letters", std::nullopt);
	}

	if (email.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789@.") != std::string::npos) {
		return std::make_tuple(CppHttp::Net::ResponseType::BAD_REQUEST, "Email must only contain letters, numbers, @ and .", std::nullopt);
	}

	if (email.find_first_of("@") == std::string::npos) {
		return std::make_tuple(CppHttp::Net::ResponseType::BAD_REQUEST, "Email must contain @", std::nullopt);
	}

	if (email.find_first_of(".") == std::string::npos) {
		return std::make_tuple(CppHttp::Net::ResponseType::BAD_REQUEST, "Email must contain .", std::nullopt);
	}

	if (password.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!#$%^&*") != std::string::npos) {
		return std::make_tuple(CppHttp::Net::ResponseType::BAD_REQUEST, "Password must only contain letters, numbers, !, #, $, %, ^, & and *", std::nullopt);
	}

	User user;

	*db << "SELECT * FROM users WHERE id = :id", into(user), use(userId);

	if (!db->got_data()) {
		return std::make_tuple(CppHttp::Net::ResponseType::NOT_FOUND, "User with id " + userId + " not found", std::nullopt);
	}

	std::string hashedSalted = Hash(email + password + std::to_string((user.id) * 52834) + secret);

	*db << "UPDATE users SET fname = :fname, lname = :lname, email = :email, password = :password WHERE id = :id RETURNING *", use(fName), use(lName), use(email), use(hashedSalted), use(userId), into(user);

	json userJson;
	userJson["fname"] = user.fname;
	userJson["lname"] = user.lname;
	userJson["email"] = user.email;
	userJson["status"] = user.status;
	userJson["school"] = user.school;

	return std::make_tuple(CppHttp::Net::ResponseType::JSON, userJson.dump(4), std::nullopt);
}
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

	std::cout << "User: " << user.email << std::endl;

	if (ind == indicator::i_ok) {
		return std::make_tuple(CppHttp::Net::ResponseType::ALREADY_EXISTS, "User with email " + email + " already exists", std::nullopt);
	}

	*db << "SELECT last_value FROM users_id_seq", into(user.id);

	long long int id = (user.id + 1) * 52834;

	password = email + password + std::to_string(id) + secret;

	std::string hashedSalted = Hash(password);

	std::cout << "Hashed: " << hashedSalted << std::endl;

	*db << "INSERT INTO users (id, fname, lname, email, password, status, school) VALUES (DEFAULT, :fname, :lname, :email, :password, :status, :school)", use(fName), use(lName), use(email), use(hashedSalted), use(status), use(school);

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

	if (ind == indicator::i_null) {
		return std::make_tuple(CppHttp::Net::ResponseType::NOT_FOUND, "User with email " + email + " not found", std::nullopt);
	}

	std::string hashedSalted = Hash(email + password + std::to_string((user.id + 1) * 52834) + secret);

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
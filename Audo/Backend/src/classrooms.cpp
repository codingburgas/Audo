#include "classrooms.hpp"

returnType CreateClassroom(CppHttp::Net::Request& req) {
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

	*db << "SELECT id FROM users WHERE id = :id", soci::use(ownerId);

	if (!db->got_data()) {
		return std::make_tuple(CppHttp::Net::ResponseType::NOT_AUTHORIZED, "Unathorized", std::nullopt);
	}

	json body;

	try {
		body = json::parse(req.m_info.body);
	} catch (json::exception& e) {
		return std::make_tuple(CppHttp::Net::ResponseType::BAD_REQUEST, e.what(), std::nullopt);
	}

	std::string name = body["name"];

	if (name.empty()) {
		return std::make_tuple(CppHttp::Net::ResponseType::BAD_REQUEST, "Name is required", std::nullopt);
	}

	if (name.size() > 255) {
		return std::make_tuple(CppHttp::Net::ResponseType::BAD_REQUEST, "Name is too long", std::nullopt);
	}

	if (name.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_ '") != std::string::npos) {
		return std::make_tuple(CppHttp::Net::ResponseType::BAD_REQUEST, "Name contains invalid characters", std::nullopt);
	}

	std::string code = RandomCode(8);
	
	int id;
	*db << "INSERT INTO classrooms (id, name, owner_id, unique_code) VALUES (DEFAULT, :name, :owner_id, :code) RETURNING id", soci::use(name), soci::use(ownerId), soci::use(code), into(id);

	if (!db->got_data()) {
		return std::make_tuple(CppHttp::Net::ResponseType::INTERNAL_ERROR, "Failed to create classroom", std::nullopt);
	}

	json response;

	response["name"] = name;
	response["code"] = code;
	response["id"] = id;
	response["owner_id"] = ownerId;

	return std::make_tuple(CppHttp::Net::ResponseType::JSON, response.dump(4), std::nullopt);
}

returnType GetClassroom(CppHttp::Net::Request& req) {
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

	Classroom classroom;
	int classroomId = body["classroom_id"];
	bool isOwner = true;

	*db << "SELECT * FROM classrooms WHERE id = :id", use(classroomId), into(classroom);

	if (!db->got_data()) {
		return std::make_tuple(CppHttp::Net::ResponseType::NOT_FOUND, "Classroom not found", std::nullopt);
	}

	if (classroom.ownerId != std::stoi(userId)) {
		isOwner = false;
	}

	std::string teacherFname, teacherLname;

	*db << "SELECT fname, lname FROM users WHERE id = :id", use(classroom.ownerId), into(teacherFname), into(teacherLname);

	*db << "SELECT * FROM uc_bridge WHERE classroom_id = :classroomId AND user_id = :user_id", use(classroomId), use(std::stoi(userId));

	if (!db->got_data() && !isOwner) {
		return std::make_tuple(CppHttp::Net::ResponseType::NOT_AUTHORIZED, "Unauthorized", std::nullopt);
	}

	std::vector<UClassroom> rooms;
	soci::rowset<UClassroom> rsClassrooms = (db->prepare << "SELECT uc_bridge.id, uc_bridge.classroom_id, uc_bridge.user_id, users.fname, users.lname FROM uc_bridge INNER JOIN users ON uc_bridge.user_id=users.id WHERE uc_bridge.classroom_id=:room_id", use(classroomId));
	for (rowset<UClassroom>::const_iterator it = rsClassrooms.begin(); it != rsClassrooms.end(); ++it) {
		rooms.push_back(*it);
	}

	json response;
	response["id"] = classroom.id;
	response["name"] = classroom.name;
	response["owner_id"] = classroom.ownerId;
	response["unique_code"] = classroom.code;

	json owner;
	owner["fname"] = teacherFname;
	owner["lname"] = teacherLname;
	owner["user_id"] = classroom.ownerId;
	owner["room_id"] = classroom.id;

	response["users"].push_back(owner);

	for (auto& room : rooms) {
		json ucBridge;
		ucBridge["room_id"] = room.room_id;
		ucBridge["user_id"] = room.user_id;
		ucBridge["fname"] = room.fname;
		ucBridge["lname"] = room.lname;

		response["users"].push_back(ucBridge);
	}

	return std::make_tuple(CppHttp::Net::ResponseType::JSON, response.dump(4), std::nullopt);
}

returnType DeleteClassroom(CppHttp::Net::Request& req) {
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

	Classroom classroom;
	int classroomId = body["classroom_id"];
	bool isOwner = true;

	*db << "SELECT * FROM classrooms WHERE id = :id", use(classroomId), into(classroom);

	if (!db->got_data()) {
		return std::make_tuple(CppHttp::Net::ResponseType::NOT_FOUND, "Classroom not found", std::nullopt);
	}

	if (classroom.ownerId != std::stoi(userId)) {
		return std::make_tuple(CppHttp::Net::ResponseType::NOT_AUTHORIZED, "Unauthorized", std::nullopt);
	}

	soci::statement statement = (db->prepare << "DELETE FROM classrooms WHERE id = :id", use(classroomId));

	statement.execute(true);

	if (!statement.get_affected_rows()) {
		return std::make_tuple(CppHttp::Net::ResponseType::INTERNAL_ERROR, "Failed to delete classroom", std::nullopt);
	}

	json response;
	response["id"] = classroom.id;
	response["name"] = classroom.name;
	response["owner_id"] = classroom.ownerId;
	response["unique_code"] = classroom.code;

	return std::make_tuple(CppHttp::Net::ResponseType::JSON, response.dump(4), std::nullopt);
}

returnType GetClassrooms(CppHttp::Net::Request& req) {
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

	std::vector<Classroom> classrooms;

	soci::rowset<Classroom> rsClassrooms = (db->prepare << "SELECT * FROM classrooms WHERE owner_id = :id OR id = (SELECT classroom_id FROM uc_bridge WHERE user_id = :id);", use(std::stoi(userId)), use(std::stoi(userId)));
	for (rowset<Classroom>::const_iterator it = rsClassrooms.begin(); it != rsClassrooms.end(); ++it) {
		classrooms.push_back(*it);
	}

	json response;

	for (auto& classroom : classrooms) {
		json classroomJson;
		classroomJson["id"] = classroom.id;
		classroomJson["name"] = classroom.name;
		classroomJson["owner_id"] = classroom.ownerId;
		classroomJson["unique_code"] = classroom.code;

		response.push_back(classroomJson);
	}

	return std::make_tuple(CppHttp::Net::ResponseType::JSON, response.dump(4), std::nullopt);
}

returnType JoinClassroom(CppHttp::Net::Request& req) {
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

	std::string code = body["room_code"];

	if (code.empty()) {
		return std::make_tuple(CppHttp::Net::ResponseType::BAD_REQUEST, "Code is required", std::nullopt);
	}

	if (code.size() != 8) {
		return std::make_tuple(CppHttp::Net::ResponseType::BAD_REQUEST, "Invalid code", std::nullopt);
	}

	if (code.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789") != std::string::npos) {
		return std::make_tuple(CppHttp::Net::ResponseType::BAD_REQUEST, "Invalid code", std::nullopt);
	}

	Classroom classroom;

	*db << "SELECT * FROM classrooms WHERE unique_code = :code", use(code), into(classroom);

	if (!db->got_data()) {
		return std::make_tuple(CppHttp::Net::ResponseType::NOT_FOUND, "Classroom not found", std::nullopt);
	}

	*db << "SELECT * FROM uc_bridge WHERE classroom_id = :classroomId AND user_id = :userId", use(classroom.id), use(std::stoi(userId));

	if (db->got_data() || classroom.ownerId == std::stoi(userId)) {
		return std::make_tuple(CppHttp::Net::ResponseType::BAD_REQUEST, "Already joined", std::nullopt);
	}

	*db << "INSERT INTO uc_bridge (id, classroom_id, user_id) VALUES (DEFAULT, :classroomId, :userId)", use(classroom.id), use(std::stoi(userId));

	json response;
	response["id"] = classroom.id;
	response["name"] = classroom.name;
	response["owner_id"] = classroom.ownerId;
	response["unique_code"] = classroom.code;

	return std::make_tuple(CppHttp::Net::ResponseType::JSON, response.dump(4), std::nullopt);
}
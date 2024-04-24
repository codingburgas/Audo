#include "requests.hpp"

returnType AddRequest(CppHttp::Net::Request& req) {
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
    catch (json::parse_error& e) {
        return std::make_tuple(CppHttp::Net::ResponseType::BAD_REQUEST, e.what(), std::nullopt);
    }

    std::string roomCode = body["room_code"];

    int ownerId;
	int roomId;
    int selectedUserId;
	std::string ownerEmail;
	std::string senderFname;
	std::string senderLname;

    *db << "SELECT users.email, classrooms.owner_id, classrooms.id FROM classrooms INNER JOIN users ON users.id=classrooms.owner_id WHERE classrooms.unique_code=:room_code", use(roomCode), into(ownerEmail), into(ownerId), into(roomId);

    if (!db->got_data()) {
        return std::make_tuple(CppHttp::Net::ResponseType::BAD_REQUEST, "Room does not exist", std::nullopt);
    }

    if (ownerId == std::stoi(userId)) {
        return std::make_tuple(CppHttp::Net::ResponseType::BAD_REQUEST, "You can't request access to your own room", std::nullopt);
    }

    *db << "SELECT * FROM requests WHERE user_id=:user_id AND room_id=:room_id", use(std::stoi(userId)), use(roomId);

    if (db->got_data()) {
		return std::make_tuple(CppHttp::Net::ResponseType::BAD_REQUEST, "Request already exists", std::nullopt);
	}

	*db << "SELECT * FROM uc_bridge WHERE user_id=:user_id AND classroom_id=:room_id", use(std::stoi(userId)), use(roomId);

	if (db->got_data()) {
		return std::make_tuple(CppHttp::Net::ResponseType::BAD_REQUEST, "You already have access to this room", std::nullopt);
	}

	*db << "SELECT fname, lname FROM users WHERE id=:user_id", use(std::stoi(userId)), into(senderFname), into(senderLname);

    Request request;
    *db << "INSERT INTO requests(id, user_id, room_id) VALUES (DEFAULT, :user_id, :room_id) RETURNING *", use(std::stoi(userId)), use(roomId), into(request);

	// get the register email html template from ../templates/register.html
	std::ifstream file("./templates/email.html");
	std::stringstream buffer;
	buffer << file.rdbuf();
	std::string html;

	// replace the placeholders in the html template with the user's data
	html = std::regex_replace(buffer.str(), std::regex("\\{\\{first_name\\}\\}"), senderFname);
	html = std::regex_replace(html, std::regex("\\{\\{last_name\\}\\}"), senderLname);

	// send the email
	cpr::Response r = cpr::Post(cpr::Url{ "https://api.eu.mailgun.net/v3/audovscpi.live/messages" },
		cpr::Authentication{ mailgunUsername, mailgunPassword, cpr::AuthMode::BASIC },
		cpr::Multipart{
			{"from", "noreply@audovscpi.live"},
			{"to", ownerEmail},
			{"subject", "New join request"},
			{"html", html}
		}
	);

    json requestJson;
    requestJson["id"] = request.id;
    requestJson["room_id"] = request.room_id;
    requestJson["user_id"] = request.user_id;

    return std::make_tuple(CppHttp::Net::ResponseType::JSON, requestJson.dump(4), std::nullopt);
}

returnType GetRequests(CppHttp::Net::Request& req) {
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
    catch (json::parse_error& e) {
        return std::make_tuple(CppHttp::Net::ResponseType::BAD_REQUEST, e.what(), std::nullopt);
    }

    int roomId = body["room_id"];

	int ownerId;
	*db << "SELECT classrooms.owner_id FROM requests INNER JOIN classrooms ON classrooms.id=requests.room_id WHERE requests.room_id=:room_id", use(roomId), into(ownerId);

	if (ownerId != std::stoi(userId)) {
		return std::make_tuple(CppHttp::Net::ResponseType::NOT_AUTHORIZED, "Unauthorized", std::nullopt);
	}
    
	*db << "SELECT requests.* FROM requests WHERE room_id=:room_id", use(roomId);

    if (!db->got_data()) {
		return std::make_tuple(CppHttp::Net::ResponseType::NOT_FOUND, "No requests found", std::nullopt);
	}

    std::vector<Request> requests;
    soci::rowset<Request> rsClassrooms = (db->prepare << "SELECT * FROM requests WHERE room_id = :room_id", use(roomId));
    for (rowset<Request>::const_iterator it = rsClassrooms.begin(); it != rsClassrooms.end(); ++it) {
        requests.push_back(*it);
    }

	json requestsJson;
	for (Request& request : requests) {
		json requestJson;
		requestJson["id"] = request.id;
		requestJson["room_id"] = request.room_id;
		requestJson["user_id"] = request.user_id;

		requestsJson.push_back(requestJson);
	}

	return std::make_tuple(CppHttp::Net::ResponseType::JSON, requestsJson.dump(4), std::nullopt);
}

returnType DeleteRequest(CppHttp::Net::Request& req) {
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
	catch (json::parse_error& e) {
		return std::make_tuple(CppHttp::Net::ResponseType::BAD_REQUEST, e.what(), std::nullopt);
	}

	int requestId = body["request_id"];

	Request request;
	*db << "SELECT * FROM requests WHERE id=:request_id", use(requestId), into(request);

	if (!db->got_data()) {
		return std::make_tuple(CppHttp::Net::ResponseType::NOT_FOUND, "Request not found", std::nullopt);
	}

	if (request.user_id != std::stoi(userId)) {
		return std::make_tuple(CppHttp::Net::ResponseType::NOT_AUTHORIZED, "You can't delete this request", std::nullopt);
	}

	*db << "DELETE FROM requests WHERE id=:request_id", use(requestId);

	json requestJson;
	requestJson["id"] = request.id;
	requestJson["room_id"] = request.room_id;
	requestJson["user_id"] = request.user_id;

	return std::make_tuple(CppHttp::Net::ResponseType::JSON, requestJson.dump(4), std::nullopt);
}

returnType AcceptRequest(CppHttp::Net::Request& req) {
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
	catch (json::parse_error& e) {
		return std::make_tuple(CppHttp::Net::ResponseType::BAD_REQUEST, e.what(), std::nullopt);
	}

	int requestId = body["request_id"];

	Request request;

	int ownerId;

	*db << "SELECT requests.id, requests.user_id, requests.room_id, classrooms.owner_id FROM requests INNER JOIN classrooms ON classrooms.id=requests.room_id WHERE requests.id=:request_id", use(requestId), into(request.id), into(request.user_id), into(request.room_id), into(ownerId);

	if (!db->got_data()) {
		return std::make_tuple(CppHttp::Net::ResponseType::NOT_FOUND, "Request not found", std::nullopt);
	}

	if (ownerId != std::stoi(userId)) {
		return std::make_tuple(CppHttp::Net::ResponseType::NOT_AUTHORIZED, "Unathorized", std::nullopt);
	}

	*db << "DELETE FROM requests WHERE id = :request_id", use(requestId);
	*db << "INSERT INTO uc_bridge (id, classroom_id, user_id) VALUES (DEFAULT, :classroomId, :userId)", use(request.room_id), use(request.user_id);

	// get the register email html template from ../templates/register.html
	std::ifstream file("./templates/email.html");
	std::stringstream buffer;
	buffer << file.rdbuf();
	std::string html;

	// replace the placeholders in the html template with the user's data
	html = std::regex_replace(buffer.str(), std::regex("\\{\\{first_name\\}\\}"), senderFname);
	html = std::regex_replace(html, std::regex("\\{\\{last_name\\}\\}"), senderLname);

	json response;
	response["id"] = request.id;
	response["room_id"] = request.room_id;
	response["user_id"] = request.user_id;

	return std::make_tuple(CppHttp::Net::ResponseType::JSON, response.dump(4), std::nullopt);
}

returnType DeclineRequest(CppHttp::Net::Request& req) {
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
	catch (json::parse_error& e) {
		return std::make_tuple(CppHttp::Net::ResponseType::BAD_REQUEST, e.what(), std::nullopt);
	}

	int requestId = body["request_id"];

	Request request;

	int ownerId;

	*db << "SELECT requests.id, requests.user_id, requests.room_id, classrooms.owner_id FROM requests INNER JOIN classrooms ON classrooms.id=requests.room_id WHERE requests.id=:request_id", use(requestId), into(request.id), into(request.user_id), into(request.room_id), into(ownerId);

	if (!db->got_data()) {
		return std::make_tuple(CppHttp::Net::ResponseType::NOT_FOUND, "Request not found", std::nullopt);
	}

	if (ownerId != std::stoi(userId)) {
		return std::make_tuple(CppHttp::Net::ResponseType::NOT_AUTHORIZED, "Unathorized", std::nullopt);
	}

	*db << "DELETE FROM requests WHERE id = :request_id", use(requestId);

	json response;
	response["id"] = request.id;
	response["room_id"] = request.room_id;
	response["user_id"] = request.user_id;

	return std::make_tuple(CppHttp::Net::ResponseType::JSON, response.dump(4), std::nullopt);
}
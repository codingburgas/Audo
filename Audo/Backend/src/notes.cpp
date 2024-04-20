#include "notes.hpp"

returnType AddNote(CppHttp::Net::Request& req) {
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

	std::string subject = body["subject"];
	std::string topic = body["topic"];
	int roomId = body["room_id"];
	std::string content = body["content"];

	*db << "SELECT * FROM uc_bridge WHERE user_id=:user_id", use(std::stoi(userId));

	if (!db->got_data()) {
		return std::make_tuple(CppHttp::Net::ResponseType::NOT_AUTHORIZED, "User not in classroom members", std::nullopt);
	}

	Note note;
	*db << "INSERT INTO notes(id, subject, topic, classroom_id, content) VALUES (DEFAULT, :subject, :topic, :room_id, :content) RETURNING *", use(subject), use(topic), use(roomId), use(content), into(note);

	json noteJson;
	noteJson["id"] = note.id;
	noteJson["subject"] = note.subject;
	noteJson["topic"] = note.topic;
	noteJson["room_id"] = note.room_id;
	noteJson["content"] = note.content;

	return std::make_tuple(CppHttp::Net::ResponseType::JSON, noteJson.dump(4), std::nullopt);
}
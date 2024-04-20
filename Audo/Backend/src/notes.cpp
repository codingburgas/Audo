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
	*db << "INSERT INTO notes(id, subject, topic, classroom_id, content, owner_id) VALUES (DEFAULT, :subject, :topic, :room_id, :content, :owner_id) RETURNING *", use(subject), use(topic), use(roomId), use(content), use(userId), into(note);

	json noteJson;
	noteJson["id"] = note.id;
	noteJson["subject"] = note.subject;
	noteJson["topic"] = note.topic;
	noteJson["room_id"] = note.room_id;
	noteJson["content"] = note.content;
	noteJson["owner_id"] = note.owner_id;

	return std::make_tuple(CppHttp::Net::ResponseType::JSON, noteJson.dump(4), std::nullopt);
}

returnType GetNotes(CppHttp::Net::Request& req) {
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

	*db << "SELECT * FROM uc_bridge WHERE user_id=:user_id", use(std::stoi(userId));

	if (!db->got_data()) {
		return std::make_tuple(CppHttp::Net::ResponseType::NOT_AUTHORIZED, "User not in classroom members", std::nullopt);
	}

	std::vector<Note> notes;
	soci::rowset<Note> rsClassrooms = (db->prepare << "SELECT * FROM notes WHERE room_id = :room_id", use(roomId));
	for (rowset<Note>::const_iterator it = rsClassrooms.begin(); it != rsClassrooms.end(); ++it) {
		notes.push_back(*it);
	}

	json notesJson;
	for (Note note : notes) {
		json noteJson;
		noteJson["id"] = note.id;
		noteJson["subject"] = note.subject;
		noteJson["topic"] = note.topic;
		noteJson["owner_id"] = note.owner_id;
		noteJson["room_id"] = note.room_id;
		notesJson.push_back(noteJson);
	}

	return std::make_tuple(CppHttp::Net::ResponseType::JSON, notesJson.dump(4), std::nullopt);
}

returnType GetNote(CppHttp::Net::Request& req) {
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

	int noteId = body["note_id"];

	*db << "SELECT * FROM uc_bridge WHERE user_id=:user_id", use(std::stoi(userId));

	if (!db->got_data()) {
		return std::make_tuple(CppHttp::Net::ResponseType::NOT_AUTHORIZED, "User not in classroom members", std::nullopt);
	}

	Note note;
	*db << "SELECT * FROM notes WHERE id = :note_id", use(noteId), into(note);

	json noteJson;
	noteJson["id"] = note.id;
	noteJson["subject"] = note.subject;
	noteJson["topic"] = note.topic;
	noteJson["room_id"] = note.room_id;
	noteJson["content"] = note.content;
	noteJson["owner_id"] = note.owner_id;

	return std::make_tuple(CppHttp::Net::ResponseType::JSON, noteJson.dump(4), std::nullopt);
}

returnType DeleteNote(CppHttp::Net::Request& req) {
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

	int noteId = body["note_id"];
	int ownerId;
	int classroomOwnerId;

	*db << "SELECT notes.owner_id AS note_owner_id, classrooms.owner_id AS classroom_owner_id FROM notes INNER JOIN classrooms ON classrooms.id=classroom_id WHERE notes.id=:note_id", use(noteId), into(ownerId), into(classroomOwnerId);

	if (!db->got_data()) {
		return std::make_tuple(CppHttp::Net::ResponseType::NOT_FOUND, "Note not found", std::nullopt);
	}

	if (ownerId != noteId && std::stoi(userId) != classroomOwnerId) {
		return std::make_tuple(CppHttp::Net::ResponseType::NOT_AUTHORIZED, "User not owner of note", std::nullopt);
	}

	Note note;
	*db << "DELETE FROM notes WHERE id = :note_id RETURNING *", use(noteId), into(note);

	json noteJson;
	noteJson["id"] = note.id;
	noteJson["subject"] = note.subject;
	noteJson["topic"] = note.topic;
	noteJson["room_id"] = note.room_id;
	noteJson["content"] = note.content;
	noteJson["owner_id"] = note.owner_id;

	return std::make_tuple(CppHttp::Net::ResponseType::JSON, noteJson.dump(4), std::nullopt);
}

returnType UpdateNote(CppHttp::Net::Request& req) {
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

	int noteId = body["note_id"];
	std::string subject = body["subject"];
	std::string topic = body["topic"];
	std::string content = body["content"];

	int ownerId;
	int classroomOwnerId;

	*db << "SELECT notes.owner_id AS note_owner_id, classrooms.owner_id AS classroom_owner_id FROM notes INNER JOIN classrooms ON classrooms.id=classroom_id WHERE notes.id=:note_id", use(noteId), into(ownerId), into(classroomOwnerId);

	if (!db->got_data()) {
		return std::make_tuple(CppHttp::Net::ResponseType::NOT_FOUND, "Note not found", std::nullopt);
	}

	if (ownerId != noteId && std::stoi(userId) != classroomOwnerId) {
		return std::make_tuple(CppHttp::Net::ResponseType::NOT_AUTHORIZED, "User not owner of note", std::nullopt);
	}

	Note note;
	*db << "UPDATE notes SET subject = :subject, topic = :topic, content = :content WHERE id = :note_id RETURNING *", use(subject), use(topic), use(content), use(noteId), into(note);

	json noteJson;
	noteJson["id"] = note.id;
	noteJson["subject"] = note.subject;
	noteJson["topic"] = note.topic;
	noteJson["room_id"] = note.room_id;
	noteJson["content"] = note.content;
	noteJson["owner_id"] = note.owner_id;

	return std::make_tuple(CppHttp::Net::ResponseType::JSON, noteJson.dump(4), std::nullopt);
}
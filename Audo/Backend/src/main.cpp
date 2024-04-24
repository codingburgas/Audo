#include "main.hpp"

int main(int argc, char* argv[]) {
	CppHttp::Net::Router router;
	CppHttp::Net::TcpListener server;
	server.CreateSocket();

	server.SetOnReceive([&router](CppHttp::Net::Request& req) {
		router.Handle(req);
	});

	router.AddRoute("POST",   "/api/register",             Register);
	router.AddRoute("POST",   "/api/login",                Login);
	router.AddRoute("GET",    "/api/get/user",             GetUser);
	router.AddRoute("DELETE", "/api/delete/user",          DeleteUser);
	router.AddRoute("PUT",    "/api/update/user",          UpdateUser);
	router.AddRoute("POST",   "/api/create/room",          CreateClassroom);
	router.AddRoute("POST",   "/api/get/room",             GetClassroom);
	router.AddRoute("DELETE", "/api/delete/room",          DeleteClassroom);
	router.AddRoute("GET",    "/api/get/user/rooms",       GetClassrooms);
	router.AddRoute("POST",   "/api/join/room",            JoinClassroom);
	router.AddRoute("POST",   "/api/create/grade",         AddGrade);
	router.AddRoute("POST",   "/api/get/grades",           GetGrades);
	router.AddRoute("POST",   "/api/get/grade",            GetGrade);
	router.AddRoute("DELETE", "/api/delete/grade",         DeleteGrade);
	router.AddRoute("POST",   "/api/get/student/grades",   GetStudentGrades);
	router.AddRoute("POST",   "/api/create/note",          AddNote);
	router.AddRoute("POST",   "/api/get/notes",            GetNotes);
	router.AddRoute("POST",   "/api/get/note",             GetNote);
	router.AddRoute("DELETE", "/api/delete/note",          DeleteNote);
	router.AddRoute("PUT",    "/api/update/note",          UpdateNote);
	router.AddRoute("POST",   "/api/create/request",	   AddRequest);
	router.AddRoute("POST",   "/api/get/requests",         GetRequests);
	router.AddRoute("DELETE", "/api/delete/request",       DeleteRequest);
	router.AddRoute("POST",   "/api/accept/request",	   AcceptRequest);
	router.AddRoute("POST",   "/api/decline/request",      DeclineRequest);
	router.AddRoute("POST",   "/api/submit/test",          SubmitTest);
	router.AddRoute("GET",    "/api/get/tests",            GetTests);
	router.AddRoute("GET",    "/api/get/rankings",         GetRankings);

	std::string ip;

	if (argc > 1) {
		ip = argv[1];
	}
	else {
		ip = "";
	}

	server.Listen("127.0.0.1", 45098, 255);
}
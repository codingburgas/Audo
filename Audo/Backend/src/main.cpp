#include "main.hpp"

int main() {
	CppHttp::Net::Router router;
	CppHttp::Net::TcpListener server;
	server.CreateSocket();

	server.SetOnReceive([&router](CppHttp::Net::Request& req) {
		//std::cout << "received request\n";
		router.Handle(req);
	});

	router.AddRoute("POST",   "/api/register",             Register);
	router.AddRoute("POST",   "/api/login",                Login);
	router.AddRoute("GET",    "/api/get/user",             GetUser);
	router.AddRoute("DELETE", "/api/delete/user",          DeleteUser);
	router.AddRoute("POST",   "/api/create/room",          CreateClassroom);
	router.AddRoute("PUT",    "/api/get/room",             GetClassroom);
	router.AddRoute("DELETE", "/api/delete/room",          DeleteClassroom);
	router.AddRoute("GET",    "/api/get/user/rooms",       GetClassrooms);
	router.AddRoute("POST",   "/api/join/room",            JoinClassroom);
	router.AddRoute("POST",   "/api/create/grade",         AddGrade);
	router.AddRoute("POST",   "/api/get/grades",           GetGrades);
	router.AddRoute("POST",   "/api/get/grade",            GetGrade);
	router.AddRoute("DELETE", "/api/delete/grade",         DeleteGrade);
	router.AddRoute("POST",   "/api/get/student/grades",   GetStudentGrades);
	router.AddRoute("POST",   "/api/create/note",          AddNote);

	server.Listen("127.0.0.1", 45098, 255);
}
#include "main.hpp"

int main() {
	CppHttp::Net::Router router;
	CppHttp::Net::TcpListener server;
	server.CreateSocket();

	server.SetOnReceive([&router](CppHttp::Net::Request& req) {
		router.Handle(req);
	});

	router.AddRoute("POST", "/api/register", Register);
	router.AddRoute("POST", "/api/login", Login);
	router.AddRoute("GET", "/api/user", GetUser);
	router.AddRoute("DELETE", "/api/user", DeleteUser);
	router.AddRoute("POST", "/api/create/room", CreateClassroom);
	router.AddRoute("PUT", "/api/get/room", GetClassroom);
	router.AddRoute("DELETE", "/api/delete/room", DeleteClassroom);
	router.AddRoute("GET", "/api/user/rooms", GetClassrooms);
	router.AddRoute("POST", "/api/join/room", JoinClassroom);

	server.Listen("127.0.0.1", 45098, 255);
}
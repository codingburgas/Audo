#include "main.hpp"

int main() {
	CppHttp::Net::Router router;
	CppHttp::Net::TcpListener server;

	server.SetOnReceive([&router](CppHttp::Net::Request& req) {
		router.Handle(req);
	});

	router.AddRoute("POST", "/api/register", Register);
	router.AddRoute("POST", "/api/login", Login);

	server.Listen("127.0.0.1", 8080, 255);
}
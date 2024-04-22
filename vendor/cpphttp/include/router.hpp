#pragma once

#include "debug.hpp"
#include <functional>
#include <iostream>
#include <sstream>
#include <regex>
#include <string>
#include <optional>
#include <unordered_map>
#include "event.hpp"
#include "request.hpp"
#include "responsetype.hpp"
#include "nlohmann/json.hpp"

using json = nlohmann::json;

namespace CppHttp {
	namespace Net {
		class Router {
			using returnType = std::tuple<ResponseType, std::string, std::optional<std::vector<std::string>>>;

			public:
				void Handle(Request& req) {
					std::cout << "\033[1;32m[+] Requested path: " << req.m_info.route << "\033[0m\n";

					#ifdef API_DEBUG
						std::cout << "\033[1;34m[*] Handling request...\033[0m\n";
						std::cout << "\033[1;34m	[*] Method: " << req.m_info.method << "\033[0m\n";
						std::cout << "\033[1;34m	[*] Route: " << req.m_info.route << "\033[0m\n";
						std::cout << "\033[1;34m	[*] Parameters size: " << req.m_info.parameters.size() << "\033[0m\n";
						for (auto& [key, value] : req.m_info.parameters) {
							std::cout << "\033[1;34m		[*] Parameter: " << key << " = " << value << "\033[0m\n";
						}
						std::cout << "\033[1;34m	[*] Headers size: " << req.m_info.headers.size() << "\033[0m\n";
						for (auto& [key, value] : req.m_info.headers) {
							std::cout << "\033[1;34m		[*] Header: " << key << " = " << value << "\033[0m\n";
						}
						std::cout << "\033[1;34m[*] Body:\n";
						// split body into lines
						std::vector<std::string> lines = CppHttp::Utils::Split(req.m_info.body, '\n');
						for (auto& line : lines) {
							std::cout << "	" << line << '\n';
						}
						std::cout << "\033[0m";
					#endif

					std::string method = req.m_info.method;

					std::vector<returnType> responses;
					returnType response = std::make_tuple(ResponseType::OK, "", std::optional<std::vector<std::string>>(false));
					try {
						if (method == "GET") {
							responses = this->get[req.m_info.route].Invoke(req);
						}
						else if (method == "POST") {
							responses = this->post[req.m_info.route].Invoke(req);
						}
						else if (method == "PUT") {
							responses = this->put[req.m_info.route].Invoke(req);
						}
						else if (method == "DELETE") {
							responses = this->del[req.m_info.route].Invoke(req);
						}
					}
					catch (std::exception& e) {
						responses = { std::make_tuple(ResponseType::INTERNAL_ERROR, e.what(), std::optional<std::vector<std::string>>(false)) };
					}

					//std::cout << "\033[1;34m[*] Responses size: " << responses.size() << "\033[0m\n";
					for (const auto& res : responses) {
						response = res;
					}
					this->Respond(req, response);
				}

				void AddRoute(std::string method, std::string path, std::function<returnType(Request&)> callback) {
					for (auto& c : method) {
						c = toupper(c);
					}

					if (method == "GET") {
						this->get[path].Attach(callback);
					}
					else if (method == "POST") {
						this->post[path].Attach(callback);
					}
					else if (method == "PUT") {
						this->put[path].Attach(callback);
					}
					else if (method == "DELETE") {
						this->del[path].Attach(callback);
					}
				}

			private:
				std::unordered_map<std::string, Event<returnType, CppHttp::Net::Request&>> get;
				std::unordered_map<std::string, Event<returnType, CppHttp::Net::Request&>> post;
				std::unordered_map<std::string, Event<returnType, CppHttp::Net::Request&>> put;
				std::unordered_map<std::string, Event<returnType, CppHttp::Net::Request&>> del;

				void Respond(Request& req, returnType response) {
					ResponseType type = std::get<0>(response);
					std::string data = std::get<1>(response);
					json j;

					std::string header = "HTTP/1.1 ";

					if (type == ResponseType::OK || type == ResponseType::CREATED || type == ResponseType::JSON || type == ResponseType::HTML || type == ResponseType::TEXT) {
						if (type != ResponseType::CREATED) {
							header += "200 OK\r\n";
						}
						else {
							header += "201 Created\r\n";
						}

						// CORS
						header += "Access-Control-Allow-Origin: *\r\n";
						header += "Access-Control-Allow-Methods: GET, POST, PUT, DELETE\r\n";
						header += "Access-Control-Allow-Headers: X-PINGOTHER, Content-Type, Authorization\r\n";

						header += "Content-Type: ";

						if (type == ResponseType::JSON) {
							header += "application/json\r\n";
						}
						else if (type == ResponseType::HTML) {
							header += "text/html\r\n";
						}
						else if (type == ResponseType::TEXT) {
							header += "text/plain\r\n";
						}
					}
					else if (type == ResponseType::BAD_REQUEST) {
						header += "400 Bad Request\r\n";
						header += "Access-Control-Allow-Origin: *\r\n";
						header += "Access-Control-Allow-Methods: GET, POST, PUT, DELETE\r\n";
						header += "Access-Control-Allow-Headers: X-PINGOTHER, Content-Type, Authorization\r\n";
						header += "Content-Type: application/json\r\n";
						j["data"] = data;
					}
					else if (type == ResponseType::NOT_FOUND) {
						header += "404 Not Found\r\n";
						header += "Access-Control-Allow-Origin: *\r\n";
						header += "Access-Control-Allow-Methods: GET, POST, PUT, DELETE\r\n";
						header += "Access-Control-Allow-Headers: X-PINGOTHER, Content-Type, Authorization\r\n";
						header += "Content-Type: application/json\r\n";
						j["data"] = data;
					}
					else if (type == ResponseType::INTERNAL_ERROR) {
						header += "500 Internal Server Error\r\n";
						header += "Access-Control-Allow-Origin: *\r\n";
						header += "Access-Control-Allow-Methods: GET, POST, PUT, DELETE\r\n";
						header += "Access-Control-Allow-Headers: X-PINGOTHER, Content-Type, Authorization\r\n";
						header += "Content-Type: application/json\r\n";

						j["data"] = data;
					}
					else if (type == ResponseType::NOT_IMPLEMENTED) {
						header += "501 Not Implemented\r\n";
						header += "Access-Control-Allow-Origin: *\r\n";
						header += "Access-Control-Allow-Methods: GET, POST, PUT, DELETE\r\n";
						header += "Access-Control-Allow-Headers: X-PINGOTHER, Content-Type, Authorization\r\n";
						header += "Content-Type: application/json\r\n";

						j["data"] = data;
					}
					else if (type == ResponseType::NOT_AUTHORIZED) {
						header += "401 Unauthorized\r\n";
						header += "Access-Control-Allow-Origin: *\r\n";
						header += "Access-Control-Allow-Methods: GET, POST, PUT, DELETE\r\n";
						header += "Access-Control-Allow-Headers: X-PINGOTHER, Content-Type, Authorization\r\n";
						header += "Content-Type: application/json\r\n";

						j["data"] = data;
					}
					else if (type == ResponseType::REDIRECT) {
						header += "302 Found\r\n";
						header += "Access-Control-Allow-Origin: *\r\n";
						header += "Access-Control-Allow-Methods: GET, POST, PUT, DELETE\r\n";
						header += "Access-Control-Allow-Headers: X-PINGOTHER, Content-Type, Authorization\r\n";
						header += "Location: " + data + "\r\n";
					}
					else if (type == ResponseType::ALREADY_EXISTS) {
						header += "409 Conflict\r\n";
						header += "Access-Control-Allow-Origin: *\r\n";
						header += "Access-Control-Allow-Methods: GET, POST, PUT, DELETE\r\n";
						header += "Access-Control-Allow-Headers: X-PINGOTHER, Content-Type, Authorization\r\n";
						header += "Content-Type: application/json\r\n";

						j["data"] = data;
					}

					header += "Connection: Keep-Alive\r\n";

					if (j["data"].is_null()) {
						header += "Content-Length: " + std::to_string(data.length()) + "\r\n\r\n";
						header += data;
					}
					else {
						header += "Content-Length: " + std::to_string(j.dump().length()) + "\r\n\r\n";
						header += j.dump();
					}

					//std::cout << header << '\n';

					int bytesSent = 0;
					int totalBytesSent = 0;
					while (totalBytesSent < header.size()) {
						bytesSent = send(req.m_info.sender, header.data(), header.size(), 0);
						if (bytesSent < 0) {
							std::cout << "\033[31mFailed to send message...\033[0m\n";
							#if defined(_WIN32) || defined(_WIN64) || defined(_MSC_VER)
								std::cout << "\033[31mError code: " << WSAGetLastError() << "\033[0m\n";
							#else
								perror("Error ");
							#endif
						}

						totalBytesSent += bytesSent;
					}
				}
		};
	}
}

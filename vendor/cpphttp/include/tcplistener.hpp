
#pragma once

#include "debug.hpp"
#include "event.hpp"
#include "router.hpp"
#include <iostream>
#include <functional>
#include <thread>
#include <stdexcept>
#include <string>

#if defined(_WIN32) || defined(_WIN64) || defined(_MSC_VER)
    #define WIN32_LEAN_AND_MEAN
    #define _WINSOCK_DEPRECATED_NO_WARNINGS
    #include <Windows.h>
    #include <WinSock2.h>
    #include <WS2tcpip.h>
    #pragma comment (lib, "Ws2_32.lib")
#else
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <unistd.h>
    #include <fcntl.h>
#endif

namespace CppHttp {
    namespace Net {
        // Server class
        class TcpListener {
            public:
                TcpListener() {
                    #if defined(_WIN32) || defined(_WIN64) || defined(_MSC_VER)
                        this->InitWSA();
                    #endif
                }
                ~TcpListener() {
                    this->Close();
                }

                void CreateSocket() {
                    this->listener = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

		#if defined(_WIN32) || defined(_WIN64) || defined(_MSC_VER)
                    if (this->listener == INVALID_SOCKET) {
		#elif defined(__linux__) || defined(__APPLE__)
		    if (this->listener == -1) {
		#endif
                        std::cout << "\033[31m[-] Failed to create socket...\033[0m\n";
                        #if defined(_WIN32) || defined(_WIN64) || defined(_MSC_VER)
                            std::cout << "\033[31m[-] Error code: " << WSAGetLastError() << "\033[0m\n";
                        #endif
                        throw std::runtime_error("Failed to create socket");
                    }

                    std::cout << "\033[1;32m[+] Created socket\033[0m\n";
                }

                void Listen(const char* ip, uint_fast16_t port, uint_fast8_t maxConnections) {
                    this->server.sin_family = AF_INET;
                    this->server.sin_addr.s_addr = inet_addr(ip);
                    this->server.sin_port = htons(port);
                    this->serverLen = sizeof(this->server);
                    if (bind(this->listener, (struct sockaddr*)&this->server, this->serverLen) != 0) {
                        std::cout << "\033[31m[-] Failed to bind socket...\033[0m\n";
                        #if defined(_WIN32) || defined(_WIN64) || defined(_MSC_VER)
                            std::cout << "\033[31m[-] Error code: " << WSAGetLastError() << "\033[0m\n";
                        #endif
                        throw std::runtime_error("Failed to bind socket");
                    }
                    std::cout << "\033[1;32m[+] Bound socket\033[0m\n";

                    // Listen
                    if (listen(this->listener, maxConnections) != 0) {
                        std::cout << "\033[31m[-] Failed to listen...\033[0m\n";
                        #if defined(_WIN32) || defined(_WIN64) || defined(_MSC_VER)
                            std::cout << "\033[31m[-] Error code: " << WSAGetLastError() << "\033[0m\n";
                        #endif
                        throw std::runtime_error("Failed to listen");
                    }
                    std::cout << "\033[1;32m[+] Started listening on " << ip << ':' << port << " with " << (int)maxConnections << " max connections\033[0m\n";

                    // Accept
                    while (true) {
                        try {
                            this->Accept();
                        }
                        catch (std::runtime_error& e) {
                            std::cout << "\033[31m[-] Error: " << e.what() << "\033[0m\n";
                        }
                    }
                    this->Close();
                }

                void Close() {
                    #if defined(_WIN32) || defined(_WIN64) || defined(_MSC_VER)
                        closesocket(this->listener);
                        WSACleanup();
                    #else
                        close(this->listener);
                    #endif
                }

                void SetOnConnect(std::function<void(int)> callback) {
                    this->onConnect.Attach(callback);
                }

                void SetOnDisconnect(std::function<void(int)> callback) {
                    this->onDisconnect.Attach(callback);
                }
                
                void SetOnReceive(std::function<void(Request&)> callback) {
                    this->onReceive.Attach(callback);
                }
                
                void SetBlocking(bool blocking) {
                    #if defined(_WIN32) || defined(_WIN64) || defined(_MSC_VER)
                        u_long mode = blocking ? 0 : 1;
                        ioctlsocket(this->listener, FIONBIO, &mode);
                    #else
                        int flags = fcntl(this->listener, F_GETFL, 0);
                        if (blocking)
                            flags &= ~O_NONBLOCK;
                        else
                            flags |= O_NONBLOCK;
                        fcntl(this->listener, F_SETFL, flags);
                    #endif
                }


            private:
                #if defined(_WIN32) || defined(_WIN64) || defined(_MSC_VER)
                    SOCKET listener = INVALID_SOCKET;
                    SOCKET newConnection = INVALID_SOCKET;
                    WSADATA wsaData;
                #else
                    int listener = -1;
                    int newConnection = -1;
                #endif
                struct sockaddr_in server;

                int serverLen;

                Event<void, int> onConnect;
                Event<void, int> onDisconnect;
                Event<void, Request&> onReceive;

                void Accept() {
                    Request req = Request();
                    while (true) {
                        #if defined(_WIN32) || defined(_WIN64) || defined(_MSC_VER)
                            this->newConnection = accept(listener, (SOCKADDR*)&this->server, &this->serverLen);
                        #else
                            this->newConnection = accept(listener, (struct sockaddr*)&this->server, (socklen_t*)&this->serverLen);
                        #endif

		    #if defined(_WIN32) || defined(_WIN64) || defined(_MSC_VER)
                        if (this->newConnection == INVALID_SOCKET) {
	            #else
			if (this->newConnection == -1) {
		    #endif    
				std::cout << "\033[31m[-] Failed to accept new connection...\033[0m\n";
                            #if defined(_WIN32) || defined(_WIN64) || defined(_MSC_VER)
                                std::cout << "\033[31m[-] Error code: " << WSAGetLastError() << "\033[0m\n";
                            #else
                                perror("Error ");
                            #endif
                            throw std::runtime_error("Failed to accept new connection");
                        }

                        std::cout << "\033[1;32m[+] Accepted new connection...\033[0m\n";

                        this->onConnect.Invoke(this->newConnection);

                        char buffer[4096];
                        memset(buffer, 0, 4096);

                        size_t bytesReceived = recv(this->newConnection, buffer, 4096, 0);
                        if (bytesReceived < 0) {
                            std::cout << "\033[31m[-] Failed to read client request\033[0m\n";
                            #if defined(_WIN32) || defined(_WIN64) || defined(_MSC_VER)
                                std::cout << "\033[31m[-] Error code: " << WSAGetLastError() << "\033[0m\n";
                            #else
                                perror("Error ");
                            #endif
                            #if defined(_WIN32) || defined(_WIN64) || defined(_MSC_VER)
                                closesocket(this->newConnection);
                                WSACleanup();
                            #else
                                close(this->newConnection);
                            #endif
                            throw std::runtime_error("Failed to read client request");
                        } else if (bytesReceived == 0) {
                            std::cout << "\033[31m[-] Connection closed by peer\033[0m\n";
                            #if defined(_WIN32) || defined(_WIN64) || defined(_MSC_VER)
                                closesocket(this->newConnection);
                                WSACleanup();
                            #else
                                close(this->newConnection);
                            #endif
                            break;
                        }

                        std::cout << "\033[1;32m[+] Received client request\033[0m\n";

                        std::string data = std::string(buffer, bytesReceived);

                        #ifdef API_DEBUG
                            std::cout << "\033[1;34m[*] Request data:\n";
                            // split data by new line
                            std::vector<std::string> split = CppHttp::Utils::Split(data, '\n');
                            for (int i = 0; i < split.size(); ++i) {
                                std::cout << "    " << split[i] << '\n';
                            }
                            std::cout << "\033[0m";
                        #endif

                        req = Request(data, this->newConnection);
                        this->onReceive.Invoke(req);

                        this->onDisconnect.Invoke(this->newConnection);
                        #if defined(_WIN32) || defined(_WIN64) || defined(_MSC_VER)
                            closesocket(this->newConnection);
                        #else
                            close(this->newConnection);
                        #endif
                    }
                }

                #if defined(_WIN32) || defined(_WIN64) || defined(_MSC_VER)
                    void InitWSA() {
                        if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
                            std::cout << "\033[31m[-] Failed to initialise WSA...\033[0m\n";
                            std::cout << "\033[31m[-] Error code: " << WSAGetLastError() << "\033[0m\n";
                            throw std::runtime_error("Failed to initialise WSA");
                        }
                        std::cout << "\033[1;32m[+] Initialised WSA\033[0m\n";
                    }
                #endif
        };
    }
}

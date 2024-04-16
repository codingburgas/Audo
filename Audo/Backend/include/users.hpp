#pragma once
#include "cpphttp.hpp"
#include "database.hpp"

using returnType = std::tuple<CppHttp::Net::ResponseType, std::string, std::optional<std::vector<std::string>>>;

returnType Register(CppHttp::Net::Request& req) {

}
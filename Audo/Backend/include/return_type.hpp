#pragma once
#include <tuple>
#include <optional>
#include <vector>
#include "cpphttp.hpp"

using returnType = std::tuple<CppHttp::Net::ResponseType, std::string, std::optional<std::vector<std::string>>>;
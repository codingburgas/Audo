#pragma once
#include <openssl/sha.h>
#include <sstream>
#include <iomanip>

std::string Hash(const std::string& message);
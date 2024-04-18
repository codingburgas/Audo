#include "hash.hpp"

std::string Hash(const std::string& message) {
	unsigned char hash[SHA512_DIGEST_LENGTH];
	SHA512((const unsigned char*)message.c_str(), message.length(), hash);
	std::stringstream ss;
	ss << std::hex << std::setfill('0');
	for (int i = 0; i < SHA512_DIGEST_LENGTH; i++)
		ss << std::setw(2) << static_cast<int>(hash[i]);

	return ss.str();
}

std::string RandomCode(const int length) {
	srand(time(NULL));
	std::string code;
	for (int i = 0; i < length; i++) {
		// have random assortment of characters including numbers and letters
		// 0-9: 48-57
		// A-Z: 65-90

		int random = rand() % 2;
		if (random == 0) {
			code += (rand() % 10) + 48;
		}
		else {
			code += (rand() % 26) + 65;
		}
	}
	return code;
}
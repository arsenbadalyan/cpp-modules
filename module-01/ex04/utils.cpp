#include "reader.hpp"

std::string fromCharToString(char *str) {
	std::string result;

	for (int i = 0; str[i]; i++) {
		result += str[i];
	}

	return (result);
}

void catch_exception(std::string MSG) {
	std::cout << MSG << std::endl;
	exit(EXIT_FAILURE);
}

#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Enter one (and only) as a parameter" << std::endl;
		return (1);
	}

	std::string num = argv[1];
	std::cout << argv[1] << std::endl;

	ScalarConverter::convert(num);

	return (0);
}
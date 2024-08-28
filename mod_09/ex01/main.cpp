#include "RPN.hpp"

int main(int argc, char **argv) {

	if (argc != 2) {
		std::cerr << BRIGHT_RED "Error" RESET << std::endl;
		std::cout << MAGENTA "Usage:" YELLOW " ./RPN \"digits and operators\"" RESET<< std::endl;
		return (1);
	}

	std::string input = argv[1];
	int result = 0;

	try {
		RevPolNot rpn(input);
		result = rpn.calculate();
	}
	catch (std::exception &e) {
		std::cerr << BRIGHT_RED << e.what() << RESET << std::endl;
		return (1);
	}

	std::cout << BRIGHT_BLUE << result << RESET << std::endl;

	return (0);
}
#include "RPN.hpp"

int main(int argc, char **argv) {

	if (argc != 2) {
		std::cerr << BRIGHT_RED "Error" RESET << std::endl;
		std::cout << MAGENTA "Usage:" YELLOW " ./RPN \"digits and operators\"" RESET<< std::endl;
		return (1);
	}

	(void) argv;

	return (0);
}
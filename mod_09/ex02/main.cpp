#include "PmergeMe.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << BRIGHT_RED "Error" RESET << std::endl;
		std::cout << MAGENTA "Usage:" YELLOW " ./PmergeMe \"positive integer sequence\"" RESET<< std::endl;
		return (1);
	}


	return (0);
}
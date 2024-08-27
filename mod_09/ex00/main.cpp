#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {

	if (argc != 2) {
		std::cerr << BRIGHT_RED "Error: Could not open INPUT file!" RESET << std::endl;
		std::cout << MAGENTA "Usage:" YELLOW " ./btc input.txt" RESET<< std::endl;
		return (1);
	}

	std::string dbFile = "data.csv";

	try {
		BitcoinExchange btc(dbFile);
		btc.handleInputFile(argv[1]);
	}
	catch (std::exception &e) {
		return (1);
	}

	return (0);
}
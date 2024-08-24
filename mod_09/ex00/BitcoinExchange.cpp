#include "includes/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string &fileName) {
	this->loadDatabase(fileName);
}

void BitcoinExchange::handleInputFile(const std::string &filename) const {

}

BitcoinExchange::~BitcoinExchange() {

}

void BitcoinExchange::loadDatabase(const std::string &filename) {
	std::ifstream file(filename);
	if (!file.is_open()) {
		throw std::runtime_error("Error: Could not open file!");
	}

	std::string line;
	while(std::getline(file, line)) {
		std::stringstream ss(line);
		std::string date;
		std::string strRate;
		double rate;

		if(std::getline(ss, date, ',') && std::getline(ss, strRate)) {
			try {
				rate = std::stod(strRate);
				_inMemoryDB[date] = rate;
			}
			catch(const std::exception &e) {
				std::cerr << BRIGHT_RED"Error: Invalid data format in the line: "RESET << line << std::endl;
			}
		}
		else {
			std::cerr << BRIGHT_RED"Error: Could not parse the line!"RESET << line << std::endl;
		}
	}
	file.close();
}


#include "includes/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string &fileName) {
	this->loadDatabase(fileName);
}

void BitcoinExchange::handleInputFile(const std::string &filename) const {
	std::fstream file(filename);
	if (!file.is_open()) {
		std::cerr << BRIGHT_RED"Error: Could not open input file!"RESET << std::endl;
		return ;
	}

	std::string line;
	while (std::getline(file, line)) {
		if (line.empty())
			continue ;

		std::stringstream ss(line);
		std::string date;
		std::string strValue;

		if (std::getline(ss, date, '|') && std::getline(ss, strValue)) {
			date = ft_trim(date);
			strValue = ft_trim(strValue);

			if (!isValidDate(date)) {
				std::cerr << BRIGHT_RED"Error: Bad input: "RESET << line << std::endl;
				continue ;
			}

			double value;
			try {
				value = std::stod(strValue);
				if (value < 0 || value > 1000) {
					std::cerr << BRIGHT_RED"Error: Invalid value in the line: "RESET << line << std::endl;
					continue ;
				}
			}
			catch (const std::exception &e) {
				std::cerr << BRIGHT_RED"Error: Invalid number format in the line: "RESET << line << std::endl;
				continue ;
			}
			double rate = getExchangeRate(date);
			double result = value * rate;

			std::cout << CYAN << date << GREEN" => " << BLUE << value \
						<< RESET" = " << result << std::endl;
		}
		else {
			std::cerr << BRIGHT_RED"Error: Bad input: "RESET << line << std::endl;
		}
	}
	file.close();
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
			catch (const std::exception &e) {
				std::cerr << BRIGHT_RED"Error: Invalid data format in the line: "RESET << line << std::endl;
			}
		}
		else {
			std::cerr << BRIGHT_RED"Error: Could not parse the line!"RESET << line << std::endl;
		}
	}
	file.close();
}

std::string BitcoinExchange::ft_trim(std::string str) {
	size_t first = 0;
	size_t last = str.size() - 1;

	while (first < str.size() && std::isspace(str[first])) {
		++first;
	}

	while (last > first && std::isspace(str[last])) {
		--first;
	}

	return str.substr(first,last - first + 1);
}


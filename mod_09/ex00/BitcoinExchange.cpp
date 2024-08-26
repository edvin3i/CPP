#include "includes/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string &fileName) {
	this->loadDatabase(fileName);
}

void BitcoinExchange::handleInputFile(const std::string &filename) const {
	std::fstream file(filename.c_str());
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
			char *end;
			try {
				value = std::strtod(strValue.c_str(), &end);
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
	std::ifstream file(filename.c_str());
	if (!file.is_open()) {
		throw std::runtime_error("Error: Could not open file!");
	}

	std::string line;
	while(std::getline(file, line)) {
		std::stringstream ss(line);
		std::string date;
		std::string strRate;
		char *end;
		double rate;

		if(std::getline(ss, date, ',') && std::getline(ss, strRate)) {
			try {
				rate = std::strtod(strRate.c_str(), &end);
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

bool BitcoinExchange::isValidDate(const std::string &date) const {
	if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
		return (false);
	}

	for (size_t i = 0; i < date.length(); ++i) {
		if ((i != 4 && i != 7) && isdigit(date[i])) {
			return (false);
		}
	}

	int year = atoi(date.substr(0, 4).c_str());
	int	month = atoi(date.substr(5, 7).c_str());
	int day = atoi(date.substr(8, 10).c_str());

	if (month < 1 || month > 12) {
		return (false);
	}

}


#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define RESET "\033[0m"
#define BRIGHT_BLACK   "\033[90m"
#define BRIGHT_RED     "\033[91m"
#define BRIGHT_GREEN   "\033[92m"
#define BRIGHT_YELLOW  "\033[93m"
#define BRIGHT_BLUE    "\033[94m"
#define BRIGHT_MAGENTA "\033[95m"
#define BRIGHT_CYAN    "\033[96m"
#define BRIGHT_WHITE   "\033[97m"
#define BG_BRIGHT_BLACK   "\033[100m"
#define BG_BLUE "\033[44m"
#define BG_YELLOW "\033[43m"
#define BG_BRIGHT_RED "\033[101m"
#define BG_BRIGHT_YELLOW "\033[103m"
#define BG_BRIGHT_GREEN "\033[102m"

#include <string>
#include <cstdlib>
#include <cctype>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <algorithm>
#include <stdexcept>
#include <exception>

class BitcoinExchange {
public:
	explicit BitcoinExchange(std::string &fileName);
	void handleInputFile(const std::string &filename) const;
	~BitcoinExchange();

private:
	std::map<std::string, double> _inMemoryDB;

	void loadDatabase(const std::string &filename);
	double getExchangeRate(std::string &date) const;
	bool isValidDate(const std::string &date) const;
	static std::string ft_trim(std::string str);


};


#endif

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <exception>

class BitcoinExchange {
public:
	BitcoinExchange(std::string fileName);
	void handleInputFile(const std::string &filename) const;
	~BitcoinExchange();

private:
	std::map<std::string, double> _inMemoryDB;

	void loadDatabase(const std::string &filename);
	double getExchangeRate(const std::string &date) const;
	bool isValidDate(const std::string &date) const;
	bool isValidValue(const std::string &value) const;


};


#endif

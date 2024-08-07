#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <cstdlib>
#include <cerrno>
#include <iostream>
#include <stdexcept>
#include <limits>
#include <cctype>
#include <cmath>
#include <cfloat>

class ScalarConverter {
public:
	~ScalarConverter();

	static void convert(std::string &num);

private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &other);

	static void printChar(long num);
	static void printInt(long num);
	static void printFloat(float num);
	static void printDouble(double num);

};


#endif

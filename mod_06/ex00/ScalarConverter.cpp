#include "includes/ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {

}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
	(void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter() {

}

void ScalarConverter::printChar(long num) {
	if (num < std::numeric_limits<char>::min() || \
		num > std::numeric_limits<char>::max() || \
		!isprint(static_cast<char>(num))) {
		std::cout << "char: Non displayable" << std::endl;
	} else {
		std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
	}
}

void ScalarConverter::printInt(long num) {
	if (num < std::numeric_limits<int>::min() || \
		num > std::numeric_limits<int>::max()) {
		std::cout << "int: impossible" << std::endl;
	} else {
		std::cout << "int: " << static_cast<int>(num) << std::endl;
	}
}

void ScalarConverter::printFloat(float num) {
	std::cout << "float: " << num;
	if (num - static_cast<int>(num) == 0) {
		std::cout << ".0";
	}
	std::cout << "f" << std::endl;
}

void ScalarConverter::printDouble(double num) {
	std::cout << "double: " << num;
	if (num - static_cast<int>(num) == 0) {
		std::cout << ".0";
	}
	std::cout << std::endl;
}

void ScalarConverter::convert(std::string &num) {
	char *end;
	errno = 0;

	std::cout << "INPUT " << num << std::endl;
	if (num.length() == 3 && num[0] == '\'' && num[2] == '\'') {
		std::cout << "echoed" << std::endl;
		char c = num[1];
		std::cout << "CHAR: " << c << "END" << std::endl;
	}
	std::cout << num << std::endl;

	std::cout << std::strtol(num.c_str(), &end, 10) << std::endl;

	long int_val = std::strtol(num.c_str(), &end, 10);
	std::cout << int_val << std::endl;
	if (*end == '\0') {
		if (errno == ERANGE || int_val > std::numeric_limits<int>::max() || \
			int_val < std::numeric_limits<int>::min()) {
			std::cout << "int: impossible" << std::endl;
		}
	else {
			printChar(int_val);
			printInt(int_val);
			printFloat(static_cast<float>(int_val));
			printDouble(static_cast<double>(int_val));
		}
		return;
	}

	errno = 0;
	float float_val = std::strtof(num.c_str(), &end);
	if (*end == 'f' && *(end + 1) == '\0') {
		if (errno == ERANGE) {
			std::cout << "float: impossible" << std::endl;
		}
		else {
			printChar(static_cast<long>(float_val));
			printInt(static_cast<long>(float_val));
			printFloat(float_val);
			printDouble(static_cast<double>(float_val));
		}
		return;
	}

	errno = 0;
	double double_val = std::strtod(num.c_str(), &end);
	if (*end == '\0') {
		if (errno == ERANGE) {
			std::cout << "double: impossible" << std::endl;
		}
		else {
			printChar(static_cast<long>(double_val));
			printInt(static_cast<long>(double_val));
			printFloat(static_cast<float>(double_val));
			printDouble(double_val);
		}
		return;
	}

	std::cout << "Invalid input" << std::endl;
}

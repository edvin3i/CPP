#include "templates.hpp"

void swap_test_int() {
	int x = 5;
	int y = 10;

	std::cout << BG_BRIGHT_GREEN << BLUE"INT test:"RESET << std::endl;
	std::cout << BG_BRIGHT_BLACK"Check parameters before swapping."RESET << std::endl;
	std::cout << BRIGHT_CYAN"X = " << x << RESET << std::endl;
	std::cout << BRIGHT_BLUE"Y = " << y << RESET << std::endl;

	swap(x, y);

	std::cout << BG_BRIGHT_BLACK"Check parameters after swapping."RESET<< std::endl;
	std::cout << BRIGHT_CYAN"X = " << x << RESET << std::endl;
	std::cout << BRIGHT_BLUE"Y = " << y << RESET << std::endl;
	std::cout << "\n" << std::endl;

	std::cout << BRIGHT_YELLOW"min( x, y ) = " << ::min( x, y ) << RESET << std::endl;
	std::cout << BRIGHT_GREEN"max( x, y ) = " << ::max( x, y ) << RESET << std::endl;
	std::cout << "\n" << std::endl;
}

void swap_test_float() {
	float x = 42.42;
	float y = 21.21;

	std::cout << BG_BRIGHT_GREEN << BLUE"FLOAT test:"RESET << std::endl;
	std::cout << BG_BRIGHT_BLACK"Check parameters before swapping."RESET << std::endl;
	std::cout << BRIGHT_CYAN"X = " << x << RESET << std::endl;
	std::cout << BRIGHT_BLUE"Y = " << y << RESET << std::endl;

	swap(x, y);

	std::cout << BG_BRIGHT_BLACK"Check parameters after swapping."RESET<< std::endl;
	std::cout << BRIGHT_CYAN"X = " << x << RESET << std::endl;
	std::cout << BRIGHT_BLUE"Y = " << y << RESET << std::endl;
	std::cout << "\n" << std::endl;

	std::cout << BRIGHT_YELLOW"min( x, y ) = " << ::min( x, y ) << RESET << std::endl;
	std::cout << BRIGHT_GREEN"max( x, y ) = " << ::max( x, y ) << RESET << std::endl;
	std::cout << "\n" << std::endl;
}

void swap_test_string() {
	std::string a = "Alice";
	std::string b = "Bob";

	std::cout << BG_BRIGHT_GREEN << BLUE"Swap STRING test:"RESET << std::endl;
	std::cout << BG_BRIGHT_BLACK"Check parameters before swapping."RESET << std::endl;
	std::cout << BRIGHT_CYAN"A = " << a << RESET << std::endl;
	std::cout << BRIGHT_BLUE"B = " << b << RESET << std::endl;

	swap(a, b);

	std::cout << BG_BRIGHT_BLACK"Check parameters after swapping."RESET<< std::endl;
	std::cout << BRIGHT_CYAN"A = " << a << RESET << std::endl;
	std::cout << BRIGHT_BLUE"B = " << b << RESET << std::endl;
	std::cout << "\n" << std::endl;
}

void subject_tests() {
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	std::cout << "\n" << std::endl;
}

int main() {
//	My tests
	swap_test_int();

	swap_test_float();

	swap_test_string();
	std::cout << "\n" << BG_BLUE << YELLOW"Subject's tests:"RESET << "\n" << std::endl;
// Subject's tests
	subject_tests();

	return (0);
}
#include <iostream>
#include "includes/Point.hpp"

#define GREEN "\033[32m"
#define RED "\033[31m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

int main() {

	// Triangle 1
	Point const a1(-10.0f, -10.0f);
	Point const b1(10.0f, -10.0f);
	Point const c1(-10.0f, 10.0f);
	// Triangle 2
	Point const a2(0.0f, 0.0f);
	Point const b2(5.0f, 8.0f);
	Point const c2(10.0f, 0.0f);
	// Triangle 3
	Point const a3(-5.0f, -5.0f);
	Point const b3(5.0f, -5.0f);
	Point const c3(0.0f, 5.0f);
	// Set of points
	Point const outside1(-11.0f, -11.0f);
	Point const outside2(15.0f, 15.0f);
	Point const outside3(5.0f, -1.0f);
	Point const outside4(0.0f, 20.0f);
	Point const outside5(-20.0f, 0.0f);
	Point const outside6(0.0f, -11.0f);
	Point const inside1(-5.0f, -5.0f);
	Point const inside2(3.0f, 2.0f);
	Point const inside3(1.0f, -2.0f);
	Point const inside4(-5.0f, 0.0f);
	Point const inside5(2.5f, 1.0f);
	Point const inside6(0.5f, 1.0f);
	Point const onSide1(0.0f, -10.0f);
	Point const onSide2(7.5f, 4.0f);
	Point const onSide3(0.0f, -5.0f);
	// Set of tests
	std::cout << BLUE "Testing Triangle 1:" RESET << std::endl;
	std::cout << "Outside1 (expected false): " << (bsp(a1, b1, c1, outside1) ? GREEN "inside" RESET : RED "outside" RESET) << std::endl;
	std::cout << "Inside1 (expected true): " << (bsp(a1, b1, c1, inside1) ? GREEN "inside" RESET : RED "outside" RESET) << std::endl;
	std::cout << "Inside4 (expected true): " << (bsp(a1, b1, c1, inside4) ? GREEN "inside" RESET : RED "outside" RESET) << std::endl;
	std::cout << "OnSide1(expected false): " << (bsp(a1, b1, c1, onSide1) ? GREEN "inside" RESET : RED "outside" RESET) << std::endl;
	std::cout << "Outside3 (expected false): " << (bsp(a1, b1, c1, outside3) ? GREEN "inside" RESET : RED "outside" RESET) << std::endl;

	std::cout << BLUE "\nTesting Triangle 2:" RESET << std::endl;
	std::cout << "Inside2 (expected true): " << (bsp(a2, b2, c2, inside2) ? GREEN "inside" RESET : RED "outside" RESET) << std::endl;
	std::cout << "Inside5 (expected true): " << (bsp(a2, b2, c2, inside5) ? GREEN "inside" RESET : RED "outside" RESET) << std::endl;
	std::cout << "OnSide2 (expected false): " << (bsp(a2, b2, c2, onSide2) ? GREEN "inside" RESET : RED "outside" RESET) << std::endl;
	std::cout << "Outside2 (expected false): " << (bsp(a2, b2, c2, outside2) ? GREEN "inside" RESET : RED "outside" RESET) << std::endl;
	std::cout << "Outside4 (expected false): " << (bsp(a2, b2, c2, outside4) ? GREEN "inside" RESET : RED "outside" RESET) << std::endl;

	std::cout << BLUE "\nTesting Triangle 3:" RESET << std::endl;
	std::cout << "Inside3 (expected true): " << (bsp(a3, b3, c3, inside3) ? GREEN "inside" RESET : RED "outside" RESET) << std::endl;
	std::cout << "Inside6 (expected true): " << (bsp(a3, b3, c3, inside6) ? GREEN "inside" RESET : RED "outside" RESET) << std::endl;
	std::cout << "OnSide3 (expected false): " << (bsp(a3, b3, c3, onSide3) ? GREEN "inside" RESET : RED "outside" RESET) << std::endl;
	std::cout << "Outside5 (expected false): " << (bsp(a3, b3, c3, outside5) ? GREEN "inside" RESET : RED "outside" RESET) << std::endl;
	std::cout << "Outside6 (expected false): " << (bsp(a3, b3, c3, outside6) ? GREEN "inside" RESET : RED "outside" RESET) << std::endl;

	return 0;
}

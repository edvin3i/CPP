#include "includes/Point.hpp"

#define GREEN "\033[32m"
#define RED "\033[31m"
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


	Point const outside1(-11.0f, -11.0f); // Должен быть вне всех треугольников
	Point const outside2(15.0f, 15.0f);   // Должен быть вне всех треугольников
	Point const outside3(5.0f, -6.0f);    // Должен быть вне треугольников 2 и 3

	Point const inside1(-5.0f, -5.0f);    // Должен быть внутри треугольника 1
	Point const inside2(3.0f, 2.0f);      // Должен быть внутри треугольника 2
	Point const inside3(1.0f, -2.0f);     // Должен быть внутри треугольника 3

	// Точки, которые предполагается находятся вне треугольников
	Point const outside4(0.0f, 20.0f); // Должен быть вне всех треугольников
	Point const outside5(-20.0f, 0.0f); // Должен быть вне всех треугольников

	// Точки, которые могут быть внутри определенных треугольников
	Point const inside4(-5.0f, 0.0f); // Внутри треугольника 1
	Point const inside5(2.5f, 4.0f);  // Внутри треугольника 2
	Point const inside6(0.5f, 1.0f);  // Внутри треугольника 3
	Point const onEdge1(0.0f, -10.0f); // На границе треугольника 1, должен вернуть false
	Point const onEdge2(7.5f, 4.0f);  // На границе треугольника 2, должен вернуть false
	Point const onEdge3(-2.5f, -2.5f); // На границе треугольника 3, должен вернуть false

	// Тесты для треугольника 1
	std::cout << "Testing Triangle 1:" << std::endl;
	std::cout << "Outside4 (expected false): " << (bsp(a1, b1, c1, outside4) ? "inside" : "outside") << std::endl;
	std::cout << "Outside5 (expected false): " << (bsp(a1, b1, c1, outside5) ? "inside" : "outside") << std::endl;
	std::cout << "Inside4 (expected true): " << (bsp(a1, b1, c1, inside4) ? "inside" : "outside") << std::endl;
	std::cout << "OnEdge1 (expected false): " << (bsp(a1, b1, c1, onEdge1) ? "inside" : "outside") << std::endl;
	std::cout << std::endl;

// Тесты для треугольника 2
	std::cout << "Testing Triangle 2:" << std::endl;
	std::cout << "Inside5 (expected true): " << (bsp(a2, b2, c2, inside5) ? "inside" : "outside") << std::endl;
	std::cout << "OnEdge2 (expected false): " << (bsp(a2, b2, c2, onEdge2) ? "inside" : "outside") << std::endl;
	std::cout << std::endl;

// Тесты для треугольника 3
	std::cout << "Testing Triangle 3:" << std::endl;
	std::cout << "Inside6 (expected true): " << (bsp(a3, b3, c3, inside6) ? "inside" : "outside") << std::endl;
	std::cout << "OnEdge3 (expected false): " << (bsp(a3, b3, c3, onEdge3) ? "inside" : "outside") << std::endl;
	std::cout << std::endl;

// Дополнительные тесты для всех треугольников
	std::cout << "Additional Tests:" << std::endl;
	std::cout << "Outside1 for Triangle 1 (expected false): " << (bsp(a1, b1, c1, outside1) ? "inside" : "outside") << std::endl;
	std::cout << "Outside2 for Triangle 2 (expected false): " << (bsp(a2, b2, c2, outside2) ? "inside" : "outside") << std::endl;
	std::cout << "Outside3 for Triangle 3 (expected false): " << (bsp(a3, b3, c3, outside3) ? "inside" : "outside") << std::endl;
	std::cout << "Inside1 for Triangle 1 (expected true): " << (bsp(a1, b1, c1, inside1) ? "inside" : "outside") << std::endl;
	std::cout << "Inside2 for Triangle 2 (expected true): " << (bsp(a2, b2, c2, inside2) ? "inside" : "outside") << std::endl;
	std::cout << "Inside3 for Triangle 3 (expected true): " << (bsp(a3, b3, c3, inside3) ? "inside" : "outside") << std::endl;


	return 0;
}

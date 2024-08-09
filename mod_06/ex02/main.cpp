#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate();
void identify(Base *p);
void identify(Base &p);

Base *generate() {
	std::srand(std::time(NULL));

	int rand_case = std::rand() % 3;

	switch (rand_case) {
		case 0: return new A();
		case 1: return new B();
		case 2: return new C();
	}
	return (NULL);
}

void identify(Base *p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A class instance" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B class instance" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C class instance" << std::endl;
	else
		std::cout << "Unknown type." << std::endl;
}

void identify(Base &p) {
	try {
		A& a = dynamic_cast<A&>(p);
		std::cout << "Reference to A class instance" << std::endl;
		(void)a;
		return ;
	}
	catch(...) {
	}
	try {
		B& b = dynamic_cast<B&>(p);
		std::cout << "Reference to B class instance" << std::endl;
		(void)b;
		return ;
	}
	catch(...) {
	}
	try {
		C& c = dynamic_cast<C&>(p);
		std::cout << "Reference to C class instance" << std::endl;
		(void)c;
		return ;
	}
	catch(...) {
	}
}

int main() {

	std::cout << BG_BRIGHT_BLACK"Test output."RESET << std::endl;
	std::cout << "\n" << BRIGHT_BLUE"Creating a random class (A, B or C)"RESET"\n" << std::endl;
	Base *class_one = generate();

	std::cout << BRIGHT_MAGENTA"Identifying by pointer:"RESET << std::endl;
	identify(class_one);

	std::cout << "\n" << BRIGHT_YELLOW"Identifying by reference:"RESET << std::endl;
	identify(*class_one);

	std::cout << "\n" << RED"Destruct the class.\n"RESET << std::endl;
	delete class_one;

	return (0);
}
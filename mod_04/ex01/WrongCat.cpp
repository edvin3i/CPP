#include "includes/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << YELLOW <<  "[ WrongCat class ] Constructor is called with type " << RESET;
	std::cout << GREEN << this->getType() << RESET;
	std::cout << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
	std::cout << YELLOW <<  "[ WrongCat class ] Copy constructor is called" << RESET << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
	std::cout << YELLOW <<  "[ WrongCat class ] Assignment operator overload constructor is called" ;
	std::cout << RESET << std::endl;

	if (this != &other) {
	}
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << BRIGHT_WHITE <<  "[ WrongCat class ] " << RESET;
	std::cout << BRIGHT_CYAN << this->_type << RESET;
	std::cout << BRIGHT_WHITE << " destructor is called" << RESET;
	std::cout << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << BRIGHT_BLUE <<  "WrongCat says: " << RESET;
	std::cout << GREEN << "Wow! MEW! Wwwoow!" << RESET;
	std::cout << std::endl;
}

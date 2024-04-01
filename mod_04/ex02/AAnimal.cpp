#include "includes/AAnimal.hpp"

AAnimal::AAnimal() : _type("DefaultAnimal") {
	std::cout << YELLOW << "[ Abstract class ] Default constructor is called (w/o type)" << RESET << std::endl;
}

AAnimal::AAnimal(std::string type) : _type(type) {
	std::cout << YELLOW <<  "[ Abstract class ] Constructor is called with type " << RESET;
	std::cout << GREEN << this->_type << RESET;
	std::cout << std::endl;
}

AAnimal::AAnimal(const AAnimal &other) : _type(other._type) {
	std::cout << YELLOW <<  "[ Abstract class ] Copy constructor is called" << RESET << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &other) {
	std::cout << YELLOW <<  "[ Abstract class ] Assignment operator overload constructor is called" ;
	std::cout << RESET << std::endl;

	if (this != &other) {
		this->_type = other._type;
	}
	return *this;
}

AAnimal::~AAnimal() {
	std::cout << BRIGHT_WHITE <<  "[ Abstract class ] Animal " << RESET;
	std::cout << BRIGHT_CYAN << this->_type << RESET;
	std::cout << BRIGHT_WHITE << " destructor is called" << RESET;
	std::cout << std::endl;
}


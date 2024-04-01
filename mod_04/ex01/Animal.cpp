#include "includes/Animal.hpp"

Animal::Animal() : _type("DefaultAnimal") {
	std::cout << YELLOW << "[ Base class ] Default constructor is called (w/o type)" << RESET << std::endl;
}

Animal::Animal(std::string type) : _type(type) {
	std::cout << YELLOW <<  "[ Base class ] Constructor is called with type " << RESET;
	std::cout << GREEN << this->_type << RESET;
	std::cout << std::endl;
}

Animal::Animal(const Animal &other) : _type(other._type) {
	std::cout << YELLOW <<  "[ Base class ] Copy constructor is called" << RESET << std::endl;
}

Animal &Animal::operator=(const Animal &other) {
	std::cout << YELLOW <<  "[ Base class ] Assignment operator overload constructor is called" ;
	std::cout << RESET << std::endl;

	if (this != &other) {
		this->_type = other._type;
	}
	return *this;
}

Animal::~Animal() {
	std::cout << BRIGHT_WHITE <<  "[ Base class ] Animal " << RESET;
	std::cout << BRIGHT_CYAN << this->_type << RESET;
	std::cout << BRIGHT_WHITE << " destructor is called" << RESET;
	std::cout << std::endl;
}


const std::string Animal::getType(void) const {
	return this->_type;
}

void Animal::makeSound() const {
/*	std::cout << BRIGHT_BLUE <<  "Abstract sound from " << RESET;
	std::cout << GREEN << this->getType() << RESET;
	std::cout << std::endl;*/
}

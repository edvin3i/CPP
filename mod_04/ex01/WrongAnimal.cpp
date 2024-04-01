#include "includes/WrongAnimal.hpp"


WrongAnimal::WrongAnimal() : _type("WrongDefaultAnimal") {
	std::cout << YELLOW << "[ Wrong base class ] Default constructor is called (w/o type)" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type){
	std::cout << YELLOW <<  "[ Wrong base class ] Constructor is called with type " << RESET;
	std::cout << GREEN << this->_type << RESET;
	std::cout << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : _type(other._type) {
	std::cout << YELLOW <<  "[ Wrong base class ] Copy constructor is called" << RESET << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
	std::cout << YELLOW <<  "[ Wrong base class ] Assignment operator overload constructor is called" ;
	std::cout << RESET << std::endl;

	if (this != &other) {
		this->_type = other._type;
	}
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << BRIGHT_WHITE <<  "[ Wrong base class ] Animal " << RESET;
	std::cout << BRIGHT_CYAN << this->_type << RESET;
	std::cout << BRIGHT_WHITE << " destructor is called" << RESET;
	std::cout << std::endl;
}

const std::string WrongAnimal::getType(void) const {
	return this->_type;
}

void WrongAnimal::makeSound() const {
	std::cout << BRIGHT_BLUE <<  "No sound from " << RESET;
	std::cout << GREEN << this->getType() << RESET;
	std::cout << std::endl;
}

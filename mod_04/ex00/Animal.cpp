#include "includes/Animal.hpp"

Animal::Animal() : _type("DefaultAnimal") {
	std::cout << "Default constructor is called (w/o type)" << std::endl;
}

Animal::Animal(std::string type) : _type(type){
	std::cout << YELLOW <<  "Constructor is called with type " << RESET;
	std::cout << GREEN << this->_type << RESET;
	std::cout << std::endl;
}

Animal::Animal(const Animal &other) : _type(other._type) {
	std::cout << YELLOW <<  "Copy constructor is called" << RESET << std::endl;
}

Animal &Animal::operator=(const Animal &other) {
	std::cout << YELLOW <<  "Assignment operator overload constructor is called" ;
	std::cout << RESET << std::endl;

	if (this != &other) {
		this->_type = other._type
	}
	return *this;
}

Animal::~Animal() {
	std::cout << BRIGHT_WHITE <<  "Animal " << RESET;
	std::cout << BRIGHT_CYAN << this->_type << RESET;
	std::cout << BRIGHT_WHITE << " destructor is called" << RESET;
	std::cout << std::endl;
}

void Animal::setAnimalType(std::string type) {
	this->_type = type;
}

const std::string Animal::getAnimalType(void) const {
	return this->_type;
}

const void Animal::makeSound() const {
	std::cout << BRIGHT_BLUE <<  "Wrong" << RESET;
	std::cout << GREEN << this->getAnimalType() << RESET;
	std::cout << std::endl;
	return ;
}

#include "includes/Cat.hpp"

/*Cat::Cat() {
	std::cout << YELLOW << "Default constructor is called for Cat" << RESET << std::endl;
}*/

Cat::Cat() : AAnimal("Cat") {
	std::cout << YELLOW <<  "[ Cat class ] Constructor is called with type " << RESET;
	std::cout << GREEN << this->getType() << RESET;
	std::cout << std::endl;
	this->brain = new Brain;
}

Cat::Cat(const Cat &other) : AAnimal(other) {
	std::cout << YELLOW <<  "[ Cat class ] Copy constructor is called" << RESET << std::endl;
	this->brain = new Brain(*other.brain);
}

Cat &Cat::operator=(const Cat &other) {
	std::cout << YELLOW <<  "[ Cat class ] Assignment operator overload constructor is called" ;
	std::cout << RESET << std::endl;
	if (this != &other) {
		AAnimal::operator=(other);
		*brain=*other.brain;
	}
	return *this;
}

Cat::~Cat() {
	std::cout << BRIGHT_WHITE <<  "[ Cat class ] " << RESET;
	std::cout << BRIGHT_CYAN << this->_type << RESET;
	std::cout << BRIGHT_WHITE << " destructor is called" << RESET;
	std::cout << std::endl;
	delete brain;
}

const std::string Cat::getType(void) const {
	return this->_type;
}

const void Cat::makeSound() const {
	std::cout << BRIGHT_BLUE <<  "Cat says: " << RESET;
	std::cout << GREEN << "mew! mew! meeeewww..." << RESET;
	std::cout << std::endl;
}

Brain *Cat::getBrain(void) {
	return brain;
}

const void Cat::readThought(const int num) const {
	if (num < 0 || num > 4) {
		std::cout << BRIGHT_BLUE <<  "Cat says: " << RESET;
		std::cout << GREEN << "Mew, my brain has only 5 thoughts... mew!" << RESET;
		std::cout << std::endl;
	}
}

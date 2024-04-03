#include "includes/Dog.hpp"

/*Dog::Dog() {
	std::cout << YELLOW << "Default constructor is called Dog" << RESET << std::endl;
}*/

Dog::Dog() : AAnimal("Dog") {
	std::cout << YELLOW <<  "[ Dog class ] Constructor is called with type " << RESET;
	std::cout << GREEN << this->getType() << RESET;
	std::cout << std::endl;
	this->brain = new Brain;
}

Dog::Dog(const Dog &other) : AAnimal(other) {
	std::cout << YELLOW <<  "[ Dog class ] Copy constructor is called" << RESET << std::endl;
	this->brain = new Brain(*other.brain);
}

Dog &Dog::operator=(const Dog &other) {
	std::cout << YELLOW <<  "[ Dog class ] Assignment operator overload constructor is called" ;
	std::cout << RESET << std::endl;
	if (this != &other) {
		AAnimal::operator=(other);
		*brain=*other.brain;
	}
	return *this;
}

Dog::~Dog() {
	std::cout << BRIGHT_WHITE <<  "[ Dog class ] " << RESET;
	std::cout << BRIGHT_CYAN << this->_type << RESET;
	std::cout << BRIGHT_WHITE << " destructor is called" << RESET;
	std::cout << std::endl;
	delete brain;
}

const std::string Dog::getType(void) const {
	return this->_type;
}

const void Dog::makeSound() const {
	std::cout << BRIGHT_BLUE <<  "Dog says: " << RESET;
	std::cout << GREEN << "woof! woof! woof!" << RESET;
	std::cout << std::endl;
}

const void Dog::readThought(const int num) const {
	if (num < 0 || num > 4) {
		std::cout << BRIGHT_BLUE <<  "Dog says: " << RESET;
		std::cout << GREEN << "Woof, my brain has only 5 thoughts... woof!" << RESET;
		std::cout << std::endl;
	}
	else {
		std::cout << BRIGHT_BLUE <<  "Dog thinks: " << RESET;
		std::cout << GREEN << "I want to " << this->brain->ideas[num] << " ,woof..." << RESET;
		std::cout << std::endl;
	}
}
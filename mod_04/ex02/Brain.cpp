#include "includes/Brain.hpp"

Brain::Brain(void) {
	std::cout << YELLOW << "[ Brain class ] Default constructor is called" << RESET << std::endl;
}

Brain::Brain(const Brain &other) {
	std::cout << YELLOW <<  "[ Brain class ] Copy constructor is called" << RESET << std::endl;
	for (int i = 0; i < 5; ++i)
	{
		this->ideas[i] = other.ideas[i];
	}
}

Brain &Brain::operator=(const Brain &other) {
	std::cout << YELLOW <<  "[ Brain class ] Assignment operator overload constructor is called" ;
	std::cout << RESET << std::endl;

	if (this != &other) {
		for (int i = 0; i < 5; ++i)
		{
			this->ideas[i] = other.ideas[i];
		}
	}
	return *this;
}

Brain::~Brain() {
}

#include "includes/Ice.hpp"

Ice::Ice(void) : AMateria("ice"){
}

Ice::Ice(const Ice &other) : AMateria(other){
}

Ice &Ice::operator=(const Ice &other) {
	AMateria::operator=(other);
	return *this;
}

Ice::~Ice() {
}

AMateria *Ice::clone() const {
	return new Ice(*this);
}

void Ice::use(ICharacter &target) const{
	std::cout << BRIGHT_BLUE"* shoots an ice bolt at ";
	std::cout << BRIGHT_GREEN << target.getName();
	std::cout << BRIGHT_BLUE " *" RESET<< std::endl;
}

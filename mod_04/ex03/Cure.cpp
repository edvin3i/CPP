#include "includes/Cure.hpp"

Cure::Cure(void) : AMateria("cure"){
}

Cure::Cure(const Cure &other) : AMateria(other){
}

Cure &Cure::operator=(const Cure &other) {
	AMateria::operator=(other);
	return *this;
}

Cure::~Cure() {
}

AMateria *Cure::clone() const {
	return new Cure(*this);
}

void Cure::use(ICharacter &target) const {
	std::cout << BRIGHT_MAGENTA"* heals  ";
	std::cout << BRIGHT_GREEN << target.getName() << "'s";
	std::cout << BRIGHT_MAGENTA " wounds *";
	std::cout<< RESET << std::endl;
}

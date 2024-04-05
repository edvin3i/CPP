#include "includes/AMateria.hpp"

AMateria::AMateria(void) : _type("default") {
}

AMateria::AMateria(const std::string &type) : _type(type){
}

AMateria::AMateria(const AMateria &other) : _type(other._type){
}

AMateria::~AMateria() {
}

AMateria &AMateria::operator=(const AMateria &other) {
	if (this != &other) {
		this->_type = other._type;
	}
	return *this;
}

std::string const &AMateria::getType() const {
	return this->_type;
}







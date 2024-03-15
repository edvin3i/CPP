#include "includes/Weapon.hpp"

Weapon::Weapon(std::string w_type) : type(w_type) {
}

Weapon::~Weapon(void) {
}

void Weapon::setType(std::string new_type) {
	this->type = new_type;
}

const std::string &Weapon::getType() const {
	return type;
}
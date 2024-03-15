#include "includes/Weapon.hpp"

void Weapon::setType(std::string new_type) {
	type = new_type;
}

const std::string &Weapon::getType() const {
	return type;
}
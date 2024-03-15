#include "includes/HumanB.hpp"

HumanB::HumanB(std::string b_name) : name(b_name) {
}

HumanB::~HumanB() {
}

void HumanB::setWeapon(Weapon &new_weapon) {
	weapon = &new_weapon;
}

void HumanB::attack(void) {

	std::cout << name;
	std::cout << " attacks with their";
	std::cout << weapon->getType();
	std::cout << std::endl;
}

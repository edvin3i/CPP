#include "includes/HumanA.hpp"

HumanA::HumanA(std::string a_name, Weapon &new_weapon) : name(a_name), weapon(new_weapon) {
}

HumanA::~HumanA(void) {
}

void HumanA::attack(void) {

	std::cout << name;
	std::cout << " attacks with their ";
	std::cout << weapon.getType();
	std::cout << std::endl;
}

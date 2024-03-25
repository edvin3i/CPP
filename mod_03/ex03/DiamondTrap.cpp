#include "includes/DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) {

}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name) {

}

DiamondTrap::DiamondTrap(const DiamondTrap &other) {

}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {

}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << this->getName();
	std::cout << " destructor is called";
	std::cout << std::endl;

}

void DiamondTrap::whoAmI() {

}

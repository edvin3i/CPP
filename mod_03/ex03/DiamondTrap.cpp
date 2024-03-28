#include "includes/DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) {
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name+"_clap_name"), \
																													ScavTrap(name), \
																													FragTrap(name), \
																													_nickName(name) {
	this->setHitPoints(FragTrap::getHitPoints());
	this->setEnergyPoints(ScavTrap::getEnergyPoints());
	this->setAttackDamage(FragTrap::getAttackDamage());
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), \
																										ScavTrap(other), \
																										FragTrap(other) {
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout << BRIGHT_WHITE <<  "DiamondTrap " << RESET;
	std::cout << BRIGHT_CYAN << this->getName() << RESET;
	std::cout << BRIGHT_WHITE << " destructor is called" << RESET;
	std::cout << std::endl;

}

void DiamondTrap::whoAmI() {
	std::cout << BRIGHT_BLUE <<  "I am a DiamondTrap!\n";
	std::cout << "My original name is " << RESET;
	std::cout << BRIGHT_CYAN << this->_nickName << RESET;
	std::cout << BRIGHT_BLUE <<  "\nMy ClapTrap name is " << RESET;
	std::cout << BRIGHT_CYAN << ClapTrap::getName() << RESET << '\n';
	std::cout << std::endl;
}

void DiamondTrap::attack(const std::string &target) {
	ScavTrap::attack(target);
}

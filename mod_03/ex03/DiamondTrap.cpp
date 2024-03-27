#include "includes/DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) {
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name+"_clap_name"), \
												ScavTrap(name), \
													FragTrap(name), \
														_nickName(name) {

	ClapTrap::setHitPoints(FragTrap::getHitPoints());
	ClapTrap::setEnergyPoints(ScavTrap::getEnergyPoints());
	ClapTrap::setAttackDamage(FragTrap::getAttackDamage());
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
	std::cout << "DiamondTrap " << this->getName();
	std::cout << " destructor is called";
	std::cout << std::endl;

}

void DiamondTrap::whoAmI() {
	std::cout << "I am a DiamondTrap!\n";
	std::cout << "My original name is " << this->_nickName;
	std::cout << "\nMy ClapTrap name is " << ClapTrap::getName();
	std::cout << std::endl;
}

void DiamondTrap::attack(const std::string &target) {
	ScavTrap::attack(target);
}

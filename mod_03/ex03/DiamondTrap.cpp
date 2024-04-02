#include "includes/DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap("DefaultBot_clap_name"), \
														ScavTrap("DefaultBot_clap_name"), \
														FragTrap("DefaultBot_clap_name") {
	this->_nickName = "DefaultBot_clap_name";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name+"_clap_name") {
	ClapTrap::_nickName = name+"_clap_name";
	this->_nickName = name;
	this->_hitPoints = FragTrap::_hitPoints;
	std::cout << "ST EP = " << ScavTrap::_energyPoints << std::endl;
	this->_energyPoints = ScavTrap::getEnergyPoints();
	this->_attackDamage = FragTrap::_attackDamage;
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
	std::cout << BRIGHT_WHITE <<  "[ DiamondTrap ] " << RESET;
	std::cout << BRIGHT_CYAN << this->getName() << RESET;
	std::cout << BRIGHT_WHITE << " destructor is called" << RESET;
	std::cout << std::endl;

}

void DiamondTrap::whoAmI() {
	std::cout << BRIGHT_BLUE <<  "[ DiamondTrap ] I am a DiamondTrap!\n";
	std::cout << "[ DiamondTrap ] My original name is " << RESET;
	std::cout << BRIGHT_CYAN << this->_nickName << RESET;
	std::cout << BRIGHT_BLUE <<  "\n[ DiamondTrap ] My ClapTrap name is " << RESET;
	std::cout << BRIGHT_CYAN << ClapTrap::getName() << RESET << '\n';
	std::cout << std::endl;
}

void DiamondTrap::attack(const std::string &target) {
	ScavTrap::attack(target);
}

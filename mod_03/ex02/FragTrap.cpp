#include "includes/FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	setHitPoints(ClapTrap::getHitPoints());
	setEnergyPoints(100);
	setAttackDamage(30);
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << BRIGHT_WHITE <<  "FragTrap " << RESET;
	std::cout << BRIGHT_CYAN << this->getName() << RESET;
	std::cout << BRIGHT_WHITE << " destructor is called" << RESET;
	std::cout << std::endl;
}

void FragTrap::highFivesGuys() {
	std::cout << BRIGHT_BLUE <<  "FragTrap " << RESET;
	std::cout << BRIGHT_CYAN << this->getName() << RESET;
	std::cout << BRIGHT_BLUE << " request high five!" << RESET;
	std::cout << std::endl;
}
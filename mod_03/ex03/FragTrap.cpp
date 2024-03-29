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

void FragTrap::attack(const std::string &target) {
	if (this->getEnergyPoints() > 0) {
		this->setEnergyPoints(this->getEnergyPoints() - 1);
		std::cout << BRIGHT_MAGENTA << "FragTrap " << RESET;
		std::cout << BRIGHT_CYAN << this->getName() << RESET;
		std::cout << BRIGHT_MAGENTA << " attacks " << RESET;
		std::cout << CYAN <<  target << RESET;
		std::cout << BRIGHT_MAGENTA", causing ";
		std::cout << BRIGHT_YELLOW  << this->getAttackDamage() << RESET;
		std::cout << BRIGHT_MAGENTA << " points of damage!" << RESET;
		std::cout << std::endl;
	}
	else {
		std::cout << MAGENTA << "FragTrap " << RESET;
		std::cout << CYAN <<  this->getName() << RESET;
		std::cout << MAGENTA << " doesn't have any energy points!" << RESET;
		std::cout << std::endl;
	}
}

void FragTrap::takeDamage(unsigned int amount) {
	if (this->getHitPoints() > amount) {
		this->setHitPoints(this->getHitPoints() - amount) ;
		std::cout << BRIGHT_RED << "FragTrap " << RESET;
		std::cout << BRIGHT_CYAN << this->getName() << RESET;
		std::cout << BRIGHT_RED << " takes " << RESET;
		std::cout << BRIGHT_YELLOW << amount << RESET;
		std::cout << BRIGHT_RED << " points of damage!" << RESET;
		std::cout << std::endl;
	}
	else {
		this->setHitPoints(0);
		std::cout << BRIGHT_RED << "FragTrap " << RESET;
		std::cout << BRIGHT_CYAN << this->getName() << RESET;
		std::cout << BRIGHT_RED << " is destroyed!" << RESET;
		std::cout << std::endl;
	}
}

void FragTrap::highFivesGuys() {
	std::cout << BRIGHT_BLUE <<  "FragTrap " << RESET;
	std::cout << BRIGHT_CYAN << this->getName() << RESET;
	std::cout << BRIGHT_BLUE << " request high five!" << RESET;
	std::cout << std::endl;
}

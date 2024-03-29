#include "includes/ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	setHitPoints(ClapTrap::getHitPoints());
	setEnergyPoints(50);
	setAttackDamage(20);
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << BRIGHT_WHITE <<  "ScavTrap " << RESET;
	std::cout << BRIGHT_CYAN << this->getName() << RESET;
	std::cout << BRIGHT_WHITE << " destructor is called" << RESET;
	std::cout << std::endl;
}

void ScavTrap::guardGate() {
	std::cout << BRIGHT_BLUE <<  "ScavTrap " << RESET;
	std::cout << BRIGHT_CYAN << this->getName() << RESET;
	std::cout << BRIGHT_BLUE << " is now in Gate keeper mode." << RESET;
	std::cout << std::endl;
}

void ScavTrap::attack(const std::string &target) {
	if (this->getEnergyPoints() > 0) {
		this->setEnergyPoints(this->getEnergyPoints() - 1);
		std::cout << BRIGHT_CYAN << this->getName() << RESET;
		std::cout << BRIGHT_MAGENTA << " attacks " << RESET;
		std::cout << CYAN <<  target << RESET;
		std::cout << BRIGHT_MAGENTA", causing ";
		std::cout << BRIGHT_YELLOW  << this->getAttackDamage() << RESET;
		std::cout << BRIGHT_MAGENTA << " points of damage!" << RESET;
		std::cout << std::endl;
	}
	else {
		std::cout << MAGENTA << "ScavTrap " << RESET;
		std::cout << CYAN <<  this->getName() << RESET;
		std::cout << MAGENTA << " doesn't have any energy points!" << RESET;
		std::cout << std::endl;
	}
}

void ScavTrap::takeDamage(unsigned int amount) {
	if (this->getHitPoints() > amount) {
		this->setHitPoints(this->getHitPoints() - amount) ;
		std::cout << BRIGHT_RED << "ScavTrap " << RESET;
		std::cout << BRIGHT_CYAN << this->getName() << RESET;
		std::cout << BRIGHT_RED << " takes " << RESET;
		std::cout << BRIGHT_YELLOW << amount << RESET;
		std::cout << BRIGHT_RED << " points of damage!" << RESET;
		std::cout << std::endl;
	}
	else {
		this->setHitPoints(0);
		std::cout << BRIGHT_RED << "ScavTrap " << RESET;
		std::cout << BRIGHT_CYAN << this->getName() << RESET;
		std::cout << BRIGHT_RED << " is destroyed!" << RESET;
		std::cout << std::endl;
	}
}

void ScavTrap::beRepaired(unsigned int amount) {
	this->setHitPoints(this->getHitPoints() + amount);
	std::cout << BRIGHT_GREEN << "ScavTrap " << RESET;
	std::cout << BRIGHT_CYAN << this->getName() << RESET;
	std::cout << BRIGHT_GREEN << " repairs itself for " << RESET;
	std::cout << BRIGHT_YELLOW << amount << RESET;
	std::cout << BRIGHT_GREEN << " points!" << RESET;
	std::cout << std::endl;
}

void ScavTrap::setEnergyPoints(unsigned int pts) {
	this->_energyPoints = pts;
}

unsigned int ScavTrap::getEnergyPoints() const {
	return this->_energyPoints;
}
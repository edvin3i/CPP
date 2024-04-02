#include "includes/ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	this->_nickName = "DefaultBot";
	this->_hitPoints=  ClapTrap::_hitPoints;
	this->_energyPoints = 50;
	this->_attackDamage = 20;

	std::cout << YELLOW << "[ ScavTrap ] Default constructor is called (w/o name)" << RESET << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	this->_nickName = name;
	this->_hitPoints = ClapTrap::_hitPoints;
	this->_energyPoints = 50;
	this->_attackDamage = 20;

	std::cout << YELLOW <<  "[ ScavTrap ] Constructor is called with name " << RESET;
	std::cout << GREEN << this->_nickName << RESET;
	std::cout << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
	std::cout << YELLOW <<  "[ ScavTrap ] Copy constructor is called" << RESET << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
	if (this != &other) {
		this->_nickName = other._nickName;
		this->_energyPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	std::cout << YELLOW <<  "[ ScavTrap ] Assignment operator overload constructor is called" ;
	std::cout << RESET << std::endl;
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << BRIGHT_WHITE <<  "[ ScavTrap ] " << RESET;
	std::cout << BRIGHT_CYAN << this->_nickName << RESET;
	std::cout << BRIGHT_WHITE << " destructor is called" << RESET;
	std::cout << std::endl;
}

void ScavTrap::guardGate() {
	std::cout << BRIGHT_BLUE <<  "[ ScavTrap ] " << RESET;
	std::cout << BRIGHT_CYAN << this->_nickName << RESET;
	std::cout << BRIGHT_BLUE << " is now in Gate keeper mode." << RESET;
	std::cout << std::endl;
}

void ScavTrap::attack(const std::string &target) {
	if (this->_energyPoints > 0) {
		this->_energyPoints -= 1;
		std::cout << BRIGHT_MAGENTA << "[ ScavTrap ] " << RESET;
		std::cout << BRIGHT_CYAN << this->_nickName << RESET;
		std::cout << BRIGHT_MAGENTA << " attacks " << RESET;
		std::cout << CYAN <<  target << RESET;
		std::cout << BRIGHT_MAGENTA", causing ";
		std::cout << BRIGHT_YELLOW  << this->_attackDamage<< RESET;
		std::cout << BRIGHT_MAGENTA << " points of damage!" << RESET;
		std::cout << std::endl;
	}
	else {
		std::cout << MAGENTA << "[ ScavTrap ] " << RESET;
		std::cout << CYAN <<  this->_nickName << RESET;
		std::cout << MAGENTA << " doesn't have any energy points!" << RESET;
		std::cout << std::endl;
	}
}

/*void ScavTrap::setEnergyPoints(unsigned int pts) {
	this->_energyPoints = pts;
}*/

unsigned int ScavTrap::getEnergyPoints() const {
	return this->_energyPoints;
}

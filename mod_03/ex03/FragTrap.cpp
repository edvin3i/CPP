#include "includes/FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	this->_nickName = "DefaultBot";
	this->_hitPoints=  ClapTrap::_hitPoints;
	this->_energyPoints = 100;
	this->_attackDamage = 30;

	std::cout << YELLOW << "[ FragTrap ] Default constructor is called (w/o name)" << RESET << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	this->_nickName = name;
	this->_hitPoints = ClapTrap::_hitPoints;
	this->_energyPoints = 11;
	this->_attackDamage = 30;

	std::cout << YELLOW <<  "[ FragTrap ] Constructor is called with name " << RESET;
	std::cout << GREEN << this->_nickName << RESET;
	std::cout << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
	std::cout << YELLOW <<  "[ FragTrap ] Copy constructor is called" << RESET << std::endl;
}


FragTrap &FragTrap::operator=(const FragTrap &other) {
	if (this != &other) {
		this->_nickName = other._nickName;
		this->_energyPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	std::cout << YELLOW <<  "[ FragTrap ] Assignment operator overload constructor is called" ;
	std::cout << RESET << std::endl;
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << BRIGHT_WHITE <<  "[ FragTrap ] " << RESET;
	std::cout << BRIGHT_CYAN << this->_nickName << RESET;
	std::cout << BRIGHT_WHITE << " destructor is called" << RESET;
	std::cout << std::endl;
}

void FragTrap::attack(const std::string &target) {
	if (this->_energyPoints > 0) {
		this->_energyPoints -= 1;
		std::cout << BRIGHT_MAGENTA << "[ FragTrap ] " << RESET;
		std::cout << BRIGHT_CYAN << this->_nickName << RESET;
		std::cout << BRIGHT_MAGENTA << " attacks " << RESET;
		std::cout << CYAN <<  target << RESET;
		std::cout << BRIGHT_MAGENTA", causing ";
		std::cout << BRIGHT_YELLOW  << this->_attackDamage << RESET;
		std::cout << BRIGHT_MAGENTA << " points of damage!" << RESET;
		std::cout << std::endl;
	}
	else {
		std::cout << MAGENTA << "[ FragTrap ] " << RESET;
		std::cout << CYAN <<  this->_nickName << RESET;
		std::cout << MAGENTA << " doesn't have any energy points!" << RESET;
		std::cout << std::endl;
	}
}

void FragTrap::highFivesGuys() {
	std::cout << BRIGHT_BLUE <<  "[ FragTrap ] " << RESET;
	std::cout << BRIGHT_CYAN << this->_nickName << RESET;
	std::cout << BRIGHT_BLUE << " request high five!" << RESET;
	std::cout << std::endl;
}

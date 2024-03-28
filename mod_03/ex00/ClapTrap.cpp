#include "includes/ClapTrap.hpp"

ClapTrap::ClapTrap() : _nickName("DefaultBot"), \
						_hitPoints(100), \
						_energyPoints(10), \
						_attackDamage(0) {
	std::cout << "Default constructor is called (w/o name)" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _nickName(name), \
										_hitPoints(100), \
										_energyPoints(10), \
										_attackDamage(0) {
	std::cout << YELLOW <<  "Constructor is called with name " << RESET;
	std::cout << GREEN << this->_nickName << RESET;
	std::cout << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) : _nickName(other._nickName), \
											_hitPoints(other._hitPoints), \
											_energyPoints(other._energyPoints),
											_attackDamage(other._attackDamage) {
	std::cout << YELLOW <<  "Copy constructor is called" << RESET << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
	std::cout << YELLOW <<  "Assignment operator overload constructor is called" ;
	std::cout << RESET << std::endl;

	if (this != &other) {
		this->setHitPoints(other._hitPoints);
		this->setEnergyPoints(other._energyPoints);
		this->setAttackDamage(other._attackDamage);
	}
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << BRIGHT_WHITE <<  "ClapTrap " << RESET;
	std::cout << BRIGHT_CYAN << this->_nickName << RESET;
	std::cout << BRIGHT_WHITE << " destructor is called" << RESET;
	std::cout << std::endl;
}

void ClapTrap::attack(const std::string &target) {
	if (this->_energyPoints > 0) {
		this->_energyPoints -= 1;
		std::cout << BRIGHT_MAGENTA << "ClapTrap " << RESET;
		std::cout << BRIGHT_CYAN << this->_nickName << RESET;
		std::cout << BRIGHT_MAGENTA << " attacks " << RESET;
		std::cout << CYAN <<  target << RESET;
		std::cout << BRIGHT_MAGENTA", causing ";
		std::cout << BRIGHT_YELLOW  << this->_attackDamage << RESET;
		std::cout << BRIGHT_MAGENTA << " points of damage!" << RESET;
		std::cout << std::endl;
	}
	else {
		std::cout << MAGENTA << "ClapTrap " << RESET;
		std::cout << CYAN <<  this->_nickName << RESET;
		std::cout << MAGENTA << " doesn't have any energy points!" << RESET;
		std::cout << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoints > amount) {
		this->_hitPoints -= amount;
		std::cout << BRIGHT_RED << "ClapTrap " << RESET;
		std::cout << BRIGHT_CYAN << this->_nickName << RESET;
		std::cout << BRIGHT_RED << " takes " << RESET;
		std::cout << BRIGHT_YELLOW << amount << RESET;
		std::cout << BRIGHT_RED << " points of damage!" << RESET;
		std::cout << std::endl;
	}
	else {
		this->_hitPoints = 0;
		std::cout << BRIGHT_RED << "ClapTrap " << RESET;
		std::cout << BRIGHT_CYAN << this->_nickName << RESET;
		std::cout << BRIGHT_RED << " is destroyed!" << RESET;
		std::cout << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	this->_hitPoints += amount;
	std::cout << BRIGHT_GREEN << "ClapTrap " << RESET;
	std::cout << BRIGHT_CYAN << this->_nickName << RESET;
	std::cout << BRIGHT_GREEN << " repairs itself for " << RESET;
	std::cout << BRIGHT_YELLOW << amount << RESET;
	std::cout << BRIGHT_GREEN << " points!" << RESET;
	std::cout << std::endl;
}

void ClapTrap::setName(std::string name) {
	_nickName = name;
}

void ClapTrap::setHitPoints(unsigned int pts) {
	this->_hitPoints = pts;
}

void ClapTrap::setEnergyPoints(unsigned int pts) {
	this->_energyPoints = pts;
}

void ClapTrap::setAttackDamage(unsigned int pts) {
	this->_attackDamage = pts;
}

std::string ClapTrap::getName() const {
	return this->_nickName;
}

unsigned int ClapTrap::getHitPoints() const {
	return this->_hitPoints;
}

unsigned int ClapTrap::getEnergyPoints() const {
	return this->_energyPoints;
}

unsigned int ClapTrap::getAttackDamage() const {
	return this->_attackDamage;
}

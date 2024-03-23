#include "includes/ClapTrap.hpp"

ClapTrap::ClapTrap() : _nickName("DefaultBot"), \
						_hitPoints(10), \
						_energyPoints(10), \
						_attackDamage(0) {
}

ClapTrap::ClapTrap(const std::string name) : _nickName(name), \
										_hitPoints(10), \
										_energyPoints(10), \
										_attackDamage(0) {
}

ClapTrap::ClapTrap(const ClapTrap &other) : _nickName(other._nickName), \
											_hitPoints(other._hitPoints), \
											_energyPoints(other._energyPoints),
											_attackDamage(other._attackDamage) {
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
	if (this != &other) {
		this->setHitPoints(other._hitPoints);
		this->setEnergyPoints(other._energyPoints);
		this->setAttackDamage(other._attackDamage);
	}
	return *this;
}

ClapTrap::~ClapTrap() {
}

void ClapTrap::attack(const std::string &target) {
	if (this->_energyPoints > 0) {
		this->_energyPoints -= 1;
		std::cout << "ClapTrap ";
		std::cout << this->_nickName << " attacks ";
		std::cout << target << ", causing ";
		std::cout << this->_attackDamage << " points of damage!";
		std::cout << std::endl;
	}
	else {
		std::cout << "ClapTrap ";
		std::cout << this->_nickName << " doesn't have any energy points!";
		std::cout << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoints > amount) {
		this->_hitPoints -= amount;
		std::cout << "ClapTrap " << this->_nickName;
		std::cout << " takes " << amount;
		std::cout << " points of damage!";
		std::cout << std::endl;
	}
	else {
		this->_hitPoints = 0;
		std::cout << "ClapTrap " << this->_nickName;
		std::cout << " is destroyed!";
		std::cout << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	this->_hitPoints += amount;
	std::cout << "ClapTrap " << this->_nickName;
	std::cout << " repairs itself for " << amount;
	std::cout << " points!";
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

std::string ClapTrap::getName(void) const {
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

#include "includes/ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _nickName(name), \
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

}

void ClapTrap::takeDamage(unsigned int amount) {

}

void ClapTrap::beRepaired(unsigned int amount) {

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

unsigned int ClapTrap::getHitPoints() {
	return this->_hitPoints;
}


unsigned int ClapTrap::getEnergyPoints() {
	return this->_energyPoints;
}

unsigned int ClapTrap::getAttackDamage() {
	return this->_attackDamage;
}

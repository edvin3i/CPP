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
	std::cout << "FragTrap " << this->getName();
	std::cout << " destructor is called";
	std::cout << std::endl;
}

void FragTrap::highFivesGuys() {
	std::cout << "FragTrap " << this->getName();
	std::cout << " request high five!";
	std::cout << std::endl;
}

#include "includes/FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	setHitPoints(7);
	setEnergyPoints(34);
	setAttackDamage(67);
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

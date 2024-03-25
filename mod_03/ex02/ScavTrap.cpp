#include "includes/ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	setHitPoints(100);
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
	std::cout << "ScavTrap " << this->getName();
	std::cout << " destructor is called";
	std::cout << std::endl;
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->getName();
	std::cout << " is now in Gate keeper mode.";
	std::cout << std::endl;
}

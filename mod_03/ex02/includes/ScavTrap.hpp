#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {

public:
	ScavTrap(void);
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &other);
	ScavTrap &operator=(const ScavTrap &other);
	~ScavTrap();

	void guardGate(void);

	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	void setEnergyPoints(unsigned int pts);
	unsigned int getEnergyPoints(void) const;

private:
	unsigned int _energyPoints;

};


#endif

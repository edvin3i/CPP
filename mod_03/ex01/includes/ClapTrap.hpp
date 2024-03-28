#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap {

public:
	ClapTrap(void); // default constructor with default name
	ClapTrap(std::string name);
	ClapTrap &operator=(const ClapTrap& other);
	ClapTrap(const ClapTrap &other);
	~ClapTrap();

	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	void setName(std::string name);
	void setHitPoints(unsigned int pts);
	void setEnergyPoints(unsigned int pts);
	void setAttackDamage(unsigned int pts);

	std::string getName(void) const;
	unsigned int getHitPoints(void) const;
	unsigned int getEnergyPoints(void) const;
	unsigned int getAttackDamage(void) const;

private:
	std::string _nickName;
	unsigned int _hitPoints;
	unsigned int _energyPoints;
	unsigned int _attackDamage;

};


#endif

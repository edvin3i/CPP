#pragma once
#ifndef EX00_CLAPTRAP_HPP
#define EX00_CLAPTRAP_HPP

#include <string>

class ClapTrap {

public:
	ClapTrap(std::string name);
	//ClapTrap(std::string name, int hit_pts, int enrg_pts, int attk_dmg);
	ClapTrap &operator=(const ClapTrap& other);
	ClapTrap(const ClapTrap &other);
	~ClapTrap();

	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	void setHitPoints(unsigned int pts);
	void setEnergyPoints(unsigned int pts);
	void setAttackDamage(unsigned int pts);

	unsigned int getHitPoints();
	unsigned int getEnergyPoints();
	unsigned int getAttackDamage();

private:
	std::string _nickName;
	unsigned int _hitPoints;
	unsigned int _energyPoints;
	unsigned int _attackDamage;

};


#endif

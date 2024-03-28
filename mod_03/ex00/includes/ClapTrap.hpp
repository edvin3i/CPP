#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define RESET "\033[0m"
#define BRIGHT_BLACK   "\033[90m"
#define BG_BRIGHT_BLACK   "\033[100m"
#define BRIGHT_RED     "\033[91m"
#define BRIGHT_GREEN   "\033[92m"
#define BRIGHT_YELLOW  "\033[93m"
#define BRIGHT_BLUE    "\033[94m"
#define BRIGHT_MAGENTA "\033[95m"
#define BRIGHT_CYAN    "\033[96m"
#define BRIGHT_WHITE   "\033[97m"

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

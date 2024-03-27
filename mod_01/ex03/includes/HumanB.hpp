#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {

public:
	HumanB(std::string b_name);
	~HumanB(void);
	void setWeapon(Weapon &new_weapon);
	void attack(void);

private:
	std::string name;
	Weapon *weapon;
};


#endif

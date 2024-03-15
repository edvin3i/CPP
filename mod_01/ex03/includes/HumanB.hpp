#pragma once
#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
	HumanB(std::string bname);
	~HumanB(void);

public:
	void setWeapon(std::string w_type);
	void attack(void);

private:
	std::string name;
	Weapon *weapon;
};


#endif

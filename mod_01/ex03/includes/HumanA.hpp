#pragma once
#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {

	HumanA(std::string aname, Weapon &weapon);
	~HumanA(void);

public:
	void attack(void);

private:
	std::string name;
	Weapon &weapon;

};


#endif

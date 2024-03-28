#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {

public:
	HumanA(std::string a_name, Weapon &new_weapon);
	~HumanA(void);
	void attack(void) const;

private:
	std::string name;
	Weapon &weapon;
};


#endif

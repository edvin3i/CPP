#pragma once
#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon {

public:
	Weapon(std::string w_type);
	~Weapon(void);
	void setType(std::string new_type);

	const std::string &getType(void) const;

private:
	std::string type;

};


#endif

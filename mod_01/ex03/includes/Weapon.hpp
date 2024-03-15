#pragma once
#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>


class Weapon {

	Weapon(void);
	~Weapon(void);


public:

	void setType(std::string new_type);

	const std::string &getType(void) const;

private:
	std::string type;

};


#endif

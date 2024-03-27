#pragma once
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iomanip>
#include <iostream>


class Zombie {

public:

	Zombie(void);
	~Zombie(void);

	void setName(std::string zname);
	void announce(void);

private:

	std::string name;

};


#endif

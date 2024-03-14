#pragma once
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iomanip>
#include <iostream>



class Zombie {

public:

	Zombie(std::string zname);
	~Zombie(void);

	void announce(void);

private:

	std::string name;

};


#endif

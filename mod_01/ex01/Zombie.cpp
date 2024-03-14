#include "includes/Zombie.hpp"

Zombie::Zombie(void) {
}

Zombie::~Zombie(void) {
	std::cout << name << " is dead... again...";
	std::cout << std::endl;
}

void Zombie::setName(std::string zname) {
	name = zname;
}

void Zombie::announce(void) {
	std::cout << name << ": ";
	std::cout << "BraiiiiiiinnnzzzZ...";
	std::cout << std::endl;
}


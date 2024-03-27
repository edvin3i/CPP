#include "includes/Zombie.hpp"

Zombie::Zombie(std::string zname) : name(zname) {
}

Zombie::~Zombie(void) {
	std::cout << name << " is dead... again...";
	std::cout << std::endl;
}

void Zombie::announce(void) {
	std::cout << name << ": ";
	std::cout << "BraiiiiiiinnnzzzZ...";
	std::cout << std::endl;
}


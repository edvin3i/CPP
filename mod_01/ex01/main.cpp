#include "includes/Zombie.hpp"

Zombie*    zombieHorde(int n, std::string name);

int main() {

	int z_num = 10;
	Zombie *horde = zombieHorde(z_num, "Shaun");

	for (int i = 0; i < z_num; ++i)
	{
		horde[i].announce();
	}

	delete[] horde;
}
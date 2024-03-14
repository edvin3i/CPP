#include "includes/Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main() {

	// Creating the zombie on the heap
	Zombie *heapZombie = newZombie("Heap");
	heapZombie->announce();
	delete heapZombie;

	// Creating the Zombie on the stack
	randomChump("Stack");
}
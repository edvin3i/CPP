#include "includes/ClapTrap.hpp"

int main() {

	ClapTrap davin("Davin");
	ClapTrap bob("Bob");

	std::cout << "\nStarting points\n";
	std::cout << davin.getName() << ":\n";
	std::cout << "HP = " << davin.getHitPoints() << "; ";
	std::cout << "EP = " << davin.getEnergyPoints() << "; ";
	std::cout << "AD = " << davin.getAttackDamage() << ".\n";
	std::cout << bob.getName() << ":\n";
	std::cout << "HP = " << bob.getHitPoints() << "; ";
	std::cout << "EP = " << bob.getEnergyPoints() << "; ";
	std::cout << "AD = " << bob.getAttackDamage() << ".\n";
	std::cout<< std::endl;

	// Set the AttackDamage points - because it's more real
	davin.setAttackDamage(1);
	bob.setAttackDamage(1);

	// Davin attacks Bob, Bob should take 1 point of damage and then repairs it
	davin.attack("Bob");
	bob.takeDamage(1);
	std::cout << "Bob's hit points: " << bob.getHitPoints();
	std::cout<< std::endl;

	bob.beRepaired(1);
	std::cout << "Bob's hit points after repair: " << bob.getHitPoints();
	std::cout << std::endl;

	// Demonstrating multiple attacks to exhaust Davin's energy points
	std::cout << "\nDemonstrating multiple attacks to exhaust energy points:\n";
	for (int i = 0; i < 10; i++) {
		davin.attack("Bob");
	}

	// Bob trying to attack Davin
	std::cout << "\nBob trying to attack:\n";
	bob.attack("Davin");
	davin.takeDamage(1);

	// Bob takes massive damage
	std::cout << "\nBob takes massive damage:\n";
	bob.takeDamage(10);
	std::cout << "Bob's hit points after massive damage: " << bob.getHitPoints();
	std::cout << std::endl;

	// Bob attempts to repair after being destroyed
	std::cout << "\nBob attempts to repair after being destroyed:\n";
	bob.beRepaired(1);

	std::cout << "\nPoints at the end\n";
	std::cout << davin.getName() << ":\n";
	std::cout << "HP = " << davin.getHitPoints() << "; ";
	std::cout << "EP = " << davin.getEnergyPoints() << "; ";
	std::cout << "AD = " << davin.getAttackDamage() << ".\n";
	std::cout << bob.getName() << ":\n";
	std::cout << "HP = " << bob.getHitPoints() << "; ";
	std::cout << "EP = " << bob.getEnergyPoints() << "; ";
	std::cout << "AD = " << bob.getAttackDamage() << ".\n";
	std::cout<< std::endl;

	return 0;
}

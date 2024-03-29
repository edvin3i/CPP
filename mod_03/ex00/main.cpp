#include "includes/ClapTrap.hpp"

int main() {

	ClapTrap davin("Davin");
	ClapTrap bob("Bob");

	std::cout << CYAN <<  "\nStarting points for ClapTrap\n" << RESET;
	std::cout << GREEN << davin.getName() << ":\n";
	std::cout << RED << "HP = " << davin.getHitPoints() <<  RESET << "; ";
	std::cout << BLUE << "EP = " << davin.getEnergyPoints() << RESET << "; ";
	std::cout << MAGENTA << "AD = " << davin.getAttackDamage() << RESET << ".\n";
	std::cout << CYAN <<  "\nStarting points for ClapTrap\n" << RESET;
	std::cout << GREEN << bob.getName() << ":\n";
	std::cout << RED << "HP = " << bob.getHitPoints() <<  RESET << "; ";
	std::cout << BLUE << "EP = " << bob.getEnergyPoints() << RESET << "; ";
	std::cout << MAGENTA << "AD = " << bob.getAttackDamage() << RESET << ".\n";
	std::cout<< std::endl;

	// Set the AttackDamage points - because it's more real
	davin.setAttackDamage(1);
	bob.setAttackDamage(1);

	// Davin attacks Bob, Bob should take 1 point of damage and then repairs it
	std::cout << '\n' <<  BG_BRIGHT_BLACK << "Action:" << RESET << std::endl;
	davin.attack("Bob");
	bob.takeDamage(1);
	std::cout << "Bob's hit points: " << bob.getHitPoints();
	std::cout<< std::endl;

	bob.beRepaired(1);
	std::cout << "Bob's hit points after repair: " << bob.getHitPoints();
	std::cout << std::endl;

	// Demonstrating multiple attacks to exhaust Davin's energy points
	std::cout << '\n' <<  BG_BRIGHT_BLACK << "Demonstrating multiple attacks to exhaust Davin's energy points:" << RESET << std::endl;
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

	std::cout << '\n' <<  BG_BRIGHT_BLACK << "Final status:" << RESET << '\n';;
	std::cout << CYAN <<  "\nStarting points for ClapTrap\n" << RESET;
	std::cout << GREEN << davin.getName() << ":\n";
	std::cout << RED << "HP = " << davin.getHitPoints() <<  RESET << "; ";
	std::cout << BLUE << "EP = " << davin.getEnergyPoints() << RESET << "; ";
	std::cout << MAGENTA << "AD = " << davin.getAttackDamage() << RESET << ".\n";
	std::cout << CYAN <<  "\nStarting points for ClapTrap\n" << RESET;
	std::cout << GREEN << bob.getName() << ":\n";
	std::cout << RED << "HP = " << bob.getHitPoints() <<  RESET << "; ";
	std::cout << BLUE << "EP = " << bob.getEnergyPoints() << RESET << "; ";
	std::cout << MAGENTA << "AD = " << bob.getAttackDamage() << RESET << ".\n";
	std::cout<< std::endl;

	return 0;
}

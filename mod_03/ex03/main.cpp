#include "includes/ScavTrap.hpp"
#include "includes/FragTrap.hpp"


int main() {
	// Creating ClapTrap objects
	ClapTrap davin("Davin");
	ClapTrap bob("Bob");

	std::cout << "\nStarting points for ClapTrap\n";
	std::cout << davin.getName() << ":\n";
	std::cout << "HP = " << davin.getHitPoints() << "; ";
	std::cout << "EP = " << davin.getEnergyPoints() << "; ";
	std::cout << "AD = " << davin.getAttackDamage() << ".\n";
	std::cout << bob.getName() << ":\n";
	std::cout << "HP = " << bob.getHitPoints() << "; ";
	std::cout << "EP = " << bob.getEnergyPoints() << "; ";
	std::cout << "AD = " << bob.getAttackDamage() << ".\n";
	std::cout << std::endl;

	// Creating ScavTrap objects
	ScavTrap sonie("Sonie");
	ScavTrap bonie("Bonie");

	std::cout << "\nStarting points for ScavTrap\n";
	std::cout << sonie.getName() << ":\n";
	std::cout << "HP = " << sonie.getHitPoints() << "; ";
	std::cout << "EP = " << sonie.getEnergyPoints() << "; ";
	std::cout << "AD = " << sonie.getAttackDamage() << ".\n";
	std::cout << bonie.getName() << ":\n";
	std::cout << "HP = " << bonie.getHitPoints() << "; ";
	std::cout << "EP = " << bonie.getEnergyPoints() << "; ";
	std::cout << "AD = " << bonie.getAttackDamage() << ".\n";
	std::cout << std::endl;

	// Creating FragTrap objects
	FragTrap alice("Alice");
	FragTrap mavic("Mavic");

	std::cout << "\nStarting points for FragTrap\n";
	std::cout << alice.getName() << ":\n";
	std::cout << "HP = " << alice.getHitPoints() << "; ";
	std::cout << "EP = " << alice.getEnergyPoints() << "; ";
	std::cout << "AD = " << alice.getAttackDamage() << ".\n";
	std::cout << mavic.getName() << ":\n";
	std::cout << "HP = " << mavic.getHitPoints() << "; ";
	std::cout << "EP = " << mavic.getEnergyPoints() << "; ";
	std::cout << "AD = " << mavic.getAttackDamage() << ".\n";
	std::cout << std::endl;

	// Calling High Five! in FragTrap
	alice.highFivesGuys();
	mavic.highFivesGuys();

	// Set damage points
	davin.setAttackDamage(10);
	bob.setAttackDamage(15);
	sonie.setAttackDamage(20);
	bonie.setAttackDamage(25);

	// Attacks ClapTrap and ScavTrap
	davin.attack("Bob");
	bob.takeDamage(10);
	bob.beRepaired(10);

	sonie.attack("Bonie");
	bonie.takeDamage(20);
	bonie.beRepaired(20);

	// Sonie get Gate Keeper mode
	sonie.guardGate();

	std::cout << "\nDemonstrating multiple attacks to exhaust Davin's energy points:\n";
	for (int i = 0; i < 10; i++) {
		davin.attack("Bob");
	}

	std::cout << "\nScavTrap Bonie trying to attack ClapTrap Davin:\n";
	bonie.attack("Davin");
	davin.takeDamage(bonie.getAttackDamage());

	std::cout << "\nBob takes massive damage and tries to repair:\n";
	bob.takeDamage(100);
	bob.beRepaired(10);

	std::cout << "\nFinal status\n";
	std::cout << davin.getName() << ":\n";
	std::cout << "HP = " << davin.getHitPoints() << "; ";
	std::cout << "EP = " << davin.getEnergyPoints() << "; ";
	std::cout << "AD = " << davin.getAttackDamage() << ".\n";
	std::cout << sonie.getName() << ":\n";
	std::cout << "HP = " << sonie.getHitPoints() << "; ";
	std::cout << "EP = " << sonie.getEnergyPoints() << "; ";
	std::cout << "AD = " << sonie.getAttackDamage() << ".\n";
	std::cout << std::endl;

	return 0;
}

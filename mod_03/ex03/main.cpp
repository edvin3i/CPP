#include "includes/ScavTrap.hpp"
#include "includes/FragTrap.hpp"
#include "includes/DiamondTrap.hpp"


int main() {
	// Creating ClapTrap objects
	ClapTrap davin("Davin");

	std::cout << "\nStarting points for ClapTrap\n";
	std::cout << davin.getName() << ":\n";
	std::cout << "HP = " << davin.getHitPoints() << "; ";
	std::cout << "EP = " << davin.getEnergyPoints() << "; ";
	std::cout << "AD = " << davin.getAttackDamage() << ".\n";
	std::cout << std::endl;

	// Creating ScavTrap objects
	ScavTrap bonie("Bonie");

	std::cout << "\nStarting points for ScavTrap\n";
	std::cout << bonie.getName() << ":\n";
	std::cout << "HP = " << bonie.getHitPoints() << "; ";
	std::cout << "EP = " << bonie.getEnergyPoints() << "; ";
	std::cout << "AD = " << bonie.getAttackDamage() << ".\n";
	std::cout << std::endl;

	// Creating FragTrap objects
	FragTrap alice("Alice");

	std::cout << "\nStarting points for FragTrap\n";
	std::cout << alice.getName() << ":\n";
	std::cout << "HP = " << alice.getHitPoints() << "; ";
	std::cout << "EP = " << alice.getEnergyPoints() << "; ";
	std::cout << "AD = " << alice.getAttackDamage() << ".\n";
	std::cout << std::endl;

	// Creating DiamondTrap objects
	DiamondTrap emile("Emile");

	std::cout << "\nStarting points for DiamondTrap\n";
	std::cout << emile.getName() << ":\n";
	std::cout << "HP = " << emile.getHitPoints() << "; ";
	std::cout << "EP = " << emile.getEnergyPoints() << "; ";
	std::cout << "AD = " << emile.getAttackDamage() << ".\n";
	std::cout << std::endl;

	// Calling High Five! in FragTrap
	alice.highFivesGuys();

	// Set damage points
	davin.setAttackDamage(10);
	bonie.setAttackDamage(25);

	// Attacks ClapTrap and ScavTrap
	davin.attack("Bonie");


	bonie.takeDamage(20);
	bonie.beRepaired(20);

	// Sonie get Gate Keeper mode
	bonie.guardGate();

	std::cout << "\nDemonstrating multiple attacks to exhaust Davin's energy points:\n";
	for (int i = 0; i < 10; i++) {
		davin.attack("Bonie");
	}

	std::cout << "\nBonie takes massive damage and tries to repair:\n";
	bonie.beRepaired(23);

	std::cout << "\nScavTrap Bonie trying to attack ClapTrap Davin:\n";
	bonie.attack("Davin");
	davin.takeDamage(bonie.getAttackDamage());


	emile.whoAmI();
	emile.attack("Bonie");
	bonie.takeDamage(emile.getAttackDamage());

	std::cout << "\nFinal status\n";
	std::cout << davin.getName() << ":\n";
	std::cout << "HP = " << davin.getHitPoints() << "; ";
	std::cout << "EP = " << davin.getEnergyPoints() << "; ";
	std::cout << "AD = " << davin.getAttackDamage() << ".\n";
	std::cout << alice.getName() << ":\n";
	std::cout << "HP = " << alice.getHitPoints() << "; ";
	std::cout << "EP = " << alice.getEnergyPoints() << "; ";
	std::cout << "AD = " << alice.getAttackDamage() << ".\n";
	std::cout << bonie.getName() << ":\n";
	std::cout << "HP = " << bonie.getHitPoints() << "; ";
	std::cout << "EP = " << bonie.getEnergyPoints() << "; ";
	std::cout << "AD = " << bonie.getAttackDamage() << ".\n";
	std::cout << emile.getName() << ":\n";
	std::cout << "HP = " << emile.getHitPoints() << "; ";
	std::cout << "EP = " << emile.getEnergyPoints() << "; ";
	std::cout << "AD = " << emile.getAttackDamage() << ".\n";
	std::cout << std::endl;

	return 0;
}

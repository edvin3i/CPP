#include "includes/ScavTrap.hpp"
#include "includes/FragTrap.hpp"


int main() {
	// Creating ClapTrap objects
	ClapTrap davin("Davin");

	std::cout << CYAN <<  "\nStarting points for ClapTrap\n" << RESET;
	std::cout << GREEN << davin.getName() << ":\n";
	std::cout << RED << "HP = " << davin.getHitPoints() <<  RESET << "; ";
	std::cout << BLUE << "EP = " << davin.getEnergyPoints() << RESET << "; ";
	std::cout << MAGENTA << "AD = " << davin.getAttackDamage() << RESET << ".\n";
	std::cout << std::endl;

	// Creating ScavTrap objects
	ScavTrap bonie("Bonie");

	std::cout << CYAN <<  "\nStarting points for ScavTrap\n";
	std::cout << GREEN << bonie.getName() << ":\n";
	std::cout << RED << "HP = " << bonie.getHitPoints() <<  RESET << "; ";
	std::cout << BLUE << "EP = " << bonie.getEnergyPoints() << RESET << "; ";
	std::cout << MAGENTA << "AD = " << bonie.getAttackDamage() << RESET << ".\n";
	std::cout << std::endl;

	// Creating FragTrap objects
	FragTrap alice("Alice");

	std::cout << CYAN <<  "\nStarting points for FragTrap\n";
	std::cout << GREEN << alice.getName() << ":\n";
	std::cout << RED << "HP = " << alice.getHitPoints() <<  RESET << "; ";
	std::cout << BLUE << "EP = " << alice.getEnergyPoints() << RESET << "; ";
	std::cout << MAGENTA << "AD = " << alice.getAttackDamage() << RESET << ".\n";
	std::cout << std::endl;

	std::cout << '\n' <<  BG_BRIGHT_BLACK << "Personal messages:" << RESET << std::endl;;
	// Calling High Five! in FragTrap
	alice.highFivesGuys();

	// Bonie get Gate Keeper mode
	bonie.guardGate();

	// Set damage points
	davin.setAttackDamage(10);
	//bonie.setAttackDamage(25);

	// Attacks ClapTrap and ScavTrap
	std::cout << '\n' <<  BG_BRIGHT_BLACK << "Action:" << RESET << std::endl;
	alice.attack("Bonie");
	bonie.takeDamage(davin.getAttackDamage());
	bonie.beRepaired(davin.getAttackDamage());


	std::cout << '\n' <<  BG_BRIGHT_BLACK << "Demonstrating multiple attacks to exhaust Davin's energy points:" << RESET << std::endl;
	int j = 0;
	for (int i = 0; i < 11; i++) {
		davin.attack("Bonie");
		j++;
	}
	bonie.takeDamage(j * davin.getAttackDamage());

	std::cout << '\n' <<  BG_BRIGHT_BLACK <<  "Bonie takes massive damage and tries to repair:" << RESET << std::endl;
	bonie.beRepaired(23);

	std::cout << '\n' <<  BG_BRIGHT_BLACK << "Bonie trying to attack ClapTrap Davin:" << RESET << std::endl;
	bonie.attack("Davin");
	davin.takeDamage(bonie.getAttackDamage());


	std::cout << '\n' <<  BG_BRIGHT_BLACK << "Final status:" << RESET << '\n';;
	std::cout << GREEN << davin.getName() << ":\n";
	std::cout << RED << "HP = " << davin.getHitPoints() <<  RESET << "; ";
	std::cout << BLUE << "EP = " << davin.getEnergyPoints() << RESET << "; ";
	std::cout << MAGENTA << "AD = " << davin.getAttackDamage() << RESET << ".\n";
	std::cout << GREEN << bonie.getName() << ":\n";
	std::cout << RED << "HP = " << bonie.getHitPoints() <<  RESET << "; ";
	std::cout << BLUE << "EP = " << bonie.getEnergyPoints() << RESET << "; ";
	std::cout << MAGENTA << "AD = " << bonie.getAttackDamage() << RESET << ".\n";
	std::cout << GREEN << alice.getName() << ":\n";
	std::cout << RED << "HP = " << alice.getHitPoints() <<  RESET << "; ";
	std::cout << BLUE << "EP = " << alice.getEnergyPoints() << RESET << "; ";
	std::cout << MAGENTA << "AD = " << alice.getAttackDamage() << RESET << ".\n";
	std::cout << std::endl;
	std::cout << '\n' <<  BG_BRIGHT_BLACK << "Destructors:" << RESET << std::endl;

	return 0;
}

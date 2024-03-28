#include "includes/HumanA.hpp"
#include "includes/HumanB.hpp"

int main() {

	{
		Weapon club = Weapon("crude spiked club");

		// Using link because character has a weapon all time and can't be NULL
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");

		// Using ptr because character not all time has a weapon
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}

	return 0;
}
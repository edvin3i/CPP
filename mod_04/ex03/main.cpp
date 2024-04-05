#include "includes/AMateria.hpp"
#include "includes/IMateriaSource.hpp"
#include "includes/MateriaSource.hpp"
#include "includes/ICharacter.hpp"
#include "includes/Character.hpp"
#include "includes/Ice.hpp"
#include "includes/Cure.hpp"


int main () {

	std::cout << BG_BRIGHT_BLACK "Mandatory tests:" RESET << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;


	std::cout << BG_BRIGHT_BLACK "Additional tests:" RESET << std::endl;

	AMateria* ice = new Ice();
	AMateria* cure = new Cure();

	ICharacter* alice = new Character("Alice");
	ICharacter* davin = new Character("Davin");

	davin->equip(ice);
	davin->equip(cure);

	std::cout << BRIGHT_WHITE << davin->getName() << " Equipped ice and cure " RESET << std::endl;

	//  Alice
	std::cout << BRIGHT_WHITE << davin->getName() << " uses ice on " << alice->getName() << RESET << std::endl;
	davin->use(0, *alice);
	std::cout << BRIGHT_WHITE << davin->getName() << " uses cure on " << alice->getName() << RESET << std::endl;
	davin->use(1, *alice);

	// Deep copy
	Character bonie(*(Character*)davin);
	std::cout << BRIGHT_WHITE "[ Bonie ] "<< bonie.getName() << " is a clone of " << davin->getName() << RESET << std::endl;
	bonie.use(0, *alice);

	// Assignment
	Character nancy = bonie;
	std::cout << BRIGHT_WHITE << "[ Nancy ] " <<  nancy.getName() << " is a clone of " << bonie.getName() << RESET << std::endl;
	nancy.use(1, *alice);

	delete alice;
	delete davin;

	return 0;
}
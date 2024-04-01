#include "includes/Animal.hpp"
#include "includes/WrongCat.hpp"
#include "includes/Dog.hpp"
#include "includes/Cat.hpp"


int main() {

	std::cout << '\n' <<  BG_BRIGHT_BLACK << "Tests from subject:" << RESET << '\n';;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete i;
	delete j;
	delete meta;

	std::cout << '\n' <<  BG_BRIGHT_BLACK << "Wrong classes tests:" << RESET << '\n';
	const WrongAnimal *dog_cat = new WrongAnimal();
	dog_cat->makeSound(); // Will be called method from WrongAnimal instead WrongCat*/
	delete dog_cat;

	std::cout << '\n' <<  BG_BRIGHT_BLACK << "Yet another tests:" << RESET << '\n';
	Dog tim;
	Dog rex(tim);
	tim = rex;

	tim.makeSound();
	rex.makeSound();

	return 0;
}

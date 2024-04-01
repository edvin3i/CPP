#include "includes/Animal.hpp"
#include "includes/Dog.hpp"
#include "includes/Cat.hpp"


int main() {

	std::cout << '\n' <<  BG_BRIGHT_BLACK << "Tests from subject:" << RESET << '\n';;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;

	std::cout << '\n' <<  BG_BRIGHT_BLACK << "Animals array test:" << RESET << '\n';
	const int animal_cnt = 10;
	Animal *animals[animal_cnt];

	for (int i = 0; i < animal_cnt / 2; ++i)
	{
		animals[i] = new Dog();
	}

	for (int i = animal_cnt / 2; i < animal_cnt; ++i)
	{
		animals[i] = new Cat();
	}

	for (int i = 0; i < animal_cnt; ++i)
	{
		animals[i]->makeSound();
	}

	for (int i = 0; i < animal_cnt; ++i)
	{
		delete animals[i];
	}


	std::cout << '\n' <<  BG_BRIGHT_BLACK << "Yet another tests:" << RESET << '\n';
	Cat *white_cat = new Cat();
	white_cat->getBrain()->ideas[0] = "Play";
	std::cout << BRIGHT_WHITE << "White" <<  MAGENTA << " cat wants to " << RESET;
	std::cout << BLUE << white_cat->getBrain()->ideas[0] << '\n' << RESET;
	std::cout << std::endl;

	Cat *green_cat = new Cat(*white_cat);
	green_cat->getBrain()->ideas[0] = "Play";
	std::cout << BRIGHT_GREEN << "Green" <<  MAGENTA << " cat wants to " << RESET;
	std::cout << BLUE << green_cat->getBrain()->ideas[0] << '\n' << RESET;
	std::cout << std::endl;

	white_cat->getBrain()->ideas[0] = "Sleep";

	std::cout << BRIGHT_WHITE << "White" <<  MAGENTA << " cat wants to " << RESET;
	std::cout << BLUE << white_cat->getBrain()->ideas[0] << '\n' << RESET;
	std::cout << std::endl;

	std::cout << BRIGHT_GREEN << "Green" <<  MAGENTA << " cat wants to " << RESET;
	std::cout << BLUE << green_cat->getBrain()->ideas[0] << '\n' << RESET;
	std::cout << std::endl;

	delete white_cat;
	delete green_cat;

	return 0;
}

#include "includes/AAnimal.hpp"
#include "includes/WrongAnimal.hpp"
#include "includes/Dog.hpp"
#include "includes/Cat.hpp"
#include <cstdlib>
#include <ctime>
#include <iomanip>

int main() {

	std::cout << '\n' <<  BG_BRIGHT_BLACK << "Tests from subject:" << RESET << '\n';;
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();
	delete j; //should not create a leak
	delete i;

	std::cout << '\n' <<  BG_BRIGHT_BLACK << "Animals array test:" << RESET << '\n';
	const int animal_cnt = 4;
	AAnimal *animals[animal_cnt];

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

	std::cout << '\n' <<  BG_BRIGHT_BLACK << "Wrong classes tests:" << RESET << '\n';
	const WrongAnimal *dog_cat = new WrongAnimal();
	dog_cat->makeSound(); // Will be called method from WrongAnimal instead WrongCat
	delete dog_cat;

	std::cout << '\n' << BG_BRIGHT_BLACK << "Class copy test:" << RESET << '\n';
	Cat *white_cat = new Cat();
	white_cat->getBrain()->ideas[0] = "Play";
	std::cout << BRIGHT_WHITE << "White" << MAGENTA << " cat wants to " << RESET;
	std::cout << BLUE << white_cat->getBrain()->ideas[0];
	std::cout <<  std::setw(10) << CYAN"[ADDR]: " << &white_cat->getBrain()->ideas[0] << RESET;
	std::cout << std::endl;

	Cat *green_cat = new Cat(*white_cat);
	green_cat->getBrain()->ideas[0] = "Play";
	std::cout << BRIGHT_GREEN << "Green" << MAGENTA << " cat wants to " << RESET;
	std::cout << BLUE << green_cat->getBrain()->ideas[0];
	std::cout <<  std::setw(10) << CYAN"[ADDR]: " << &green_cat->getBrain()->ideas[0] << RESET;
	std::cout << std::endl;

	white_cat->getBrain()->ideas[0] = "Sleep";

	std::cout << BRIGHT_WHITE << "White" << MAGENTA << " cat's new idea is " << RESET;
	std::cout << BLUE << white_cat->getBrain()->ideas[0];
	std::cout <<  std::setw(10) << CYAN"[ADDR]: " << &white_cat->getBrain()->ideas[0] << RESET;
	std::cout << std::endl;

	std::cout << BRIGHT_GREEN << "Green" << MAGENTA << " cat still wants to " << RESET;
	std::cout << BLUE << green_cat->getBrain()->ideas[0];
	std::cout <<  std::setw(10)<< CYAN"[ADDR]: " << &green_cat->getBrain()->ideas[0] << RESET;
	std::cout << std::endl;

	// Creating a third cat for the assignment operator test
	Cat *blue_cat = new Cat();
	*blue_cat = *white_cat; // Using assignment operator
	blue_cat->getBrain()->ideas[0] = "Jump";

	std::cout << BRIGHT_BLUE << "Blue" << MAGENTA << " cat wants to " << RESET;
	std::cout << BLUE << blue_cat->getBrain()->ideas[0];
	std::cout <<  std::setw(10) << CYAN"[ADDR]: " << &blue_cat->getBrain()->ideas[0] << RESET;
	std::cout << std::endl;

	// Now change white_cat's first idea again to see if it affects blue_cat
	white_cat->getBrain()->ideas[0] = "Climb";

	std::cout << BRIGHT_WHITE << "White" << MAGENTA << " cat's new idea is " << RESET;
	std::cout << BLUE << white_cat->getBrain()->ideas[0];
	std::cout <<  std::setw(10)<< CYAN"[ADDR]: " << &white_cat->getBrain()->ideas[0] << RESET;
	std::cout << std::endl;

	std::cout << BRIGHT_BLUE << "Blue" << MAGENTA << " cat still wants to " << RESET;
	std::cout << BLUE << blue_cat->getBrain()->ideas[0];
	std::cout <<  std::setw(10)<< CYAN"[ADDR]: " << &blue_cat->getBrain()->ideas[0] << RESET;
	std::cout << std::endl;

	delete white_cat;
	delete green_cat;
	delete blue_cat;

	std::cout << '\n' <<  BG_BRIGHT_BLACK << "Just another one test with additional function:" << RESET << '\n';
	std::srand((unsigned int)(std::time(NULL)));

	Cat *murzie = new Cat();
	Dog *lucky = new Dog();

	int num = std::rand() % (BRAIN_VOL ) ;

	murzie->readThought(num);
	lucky->readThought(num);

	delete murzie;
	delete lucky;


	return 0;
}

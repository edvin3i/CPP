#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
	public:
	WrongAnimal(void); // default constructor with default name
	WrongAnimal(std::string name);
	WrongAnimal &operator=(const WrongAnimal& other);
	WrongAnimal(const WrongAnimal &other);
		~WrongAnimal();

		void setAnimalType(std::string type);
		const std::string getAnimalType(void) const;

		const void makeSound() const;

	protected:
		std::string _type;
	};


#endif

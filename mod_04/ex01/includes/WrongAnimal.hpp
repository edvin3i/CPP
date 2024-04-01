#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include "Animal.hpp"

class WrongAnimal {
	public:
	WrongAnimal(void);
	WrongAnimal(std::string name);
	WrongAnimal &operator=(const WrongAnimal& other);
	WrongAnimal(const WrongAnimal &other);
	~WrongAnimal();

		const std::string getType(void) const;

		void makeSound() const;

	protected:
		std::string _type;
	};


#endif

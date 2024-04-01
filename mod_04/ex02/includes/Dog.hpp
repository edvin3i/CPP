#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {
public:
	Dog(void);
	//Dog(std::string type);
	Dog &operator=(const Dog& other);
	Dog(const Dog &other);
	~Dog();

	const std::string getType(void) const;
	const void makeSound(void) const;
	const void readThought(const int num) const;

private:
	Brain *brain;
};


#endif

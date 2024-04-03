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
	virtual void makeSound(void) const;
	// more one virtual function to be more abstract
	virtual void readThought(const int num) const;

private:
	Brain *brain;
};


#endif

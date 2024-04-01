#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
public:
	Dog(void);
	//Dog(std::string type);
	Dog &operator=(const Dog& other);
	Dog(const Dog &other);
	virtual ~Dog();

	void makeSound() const;

private:
	Brain *brain;
};


#endif

#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {
public:
	Cat(void);
	//Cat(std::string type);
	Cat &operator=(const Cat& other);
	Cat(const Cat &other);
	~Cat();

	const std::string getType(void) const;
	virtual void makeSound(void) const;
	Brain *getBrain(void);
	// more one virtual function to be more abstract
	virtual void readThought(const int num) const;

private:
	Brain *brain;

};


#endif

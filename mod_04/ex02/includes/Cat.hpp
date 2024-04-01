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
	const void makeSound(void) const;
	const void readThought(const int num) const;
	Brain *getBrain(void);

private:
	Brain *brain;

};


#endif

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define RESET "\033[0m"
#define BRIGHT_BLACK   "\033[90m"
#define BG_BRIGHT_BLACK   "\033[100m"
#define BRIGHT_RED     "\033[91m"
#define BRIGHT_GREEN   "\033[92m"
#define BRIGHT_YELLOW  "\033[93m"
#define BRIGHT_BLUE    "\033[94m"
#define BRIGHT_MAGENTA "\033[95m"
#define BRIGHT_CYAN    "\033[96m"
#define BRIGHT_WHITE   "\033[97m"


#include <iostream>

class Animal {
public:
	Animal(void);
	Animal(std::string type);
	Animal &operator=(const Animal& other);
	Animal(const Animal &other);
	virtual ~Animal();

	const std::string getType(void) const;

	virtual void makeSound() const;

protected:
	std::string _type;
};


#endif

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "AAnimal.hpp" // for colours and etc

class Brain {
public:
	std::string ideas[5];
	Brain(void);
	Brain(const Brain &other);
	Brain &operator=(const Brain& other);
	~Brain();
};


#endif
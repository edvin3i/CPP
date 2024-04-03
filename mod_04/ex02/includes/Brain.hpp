#ifndef BRAIN_HPP
#define BRAIN_HPP

#define BRAIN_VOL 5

#include "AAnimal.hpp" // for colours etc

class Brain {
public:
	std::string ideas[BRAIN_VOL];
	Brain(void);
	Brain(const Brain &other);
	Brain &operator=(const Brain& other);
	~Brain();
};


#endif
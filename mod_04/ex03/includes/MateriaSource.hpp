#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource{
public:
	MateriaSource(void);
	MateriaSource(const MateriaSource &other);
	MateriaSource &operator=(const MateriaSource &other);
	~MateriaSource(void);

	void learnMateria(AMateria *m);
	AMateria *createMateria(std::string const &type);

private:
	AMateria *_learnedMateria[4];

};


#endif

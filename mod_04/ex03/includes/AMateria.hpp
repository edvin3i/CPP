#ifndef AMATERIA_HPP
#define AMATERIA_HPP


class AMateria
{
protected:


public:
	AMateria(std::string const & type);


	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif

#include "includes/MateriaSource.hpp"


MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; ++i)
	{
		_learnedMateria[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource &other) {
	for (int i = 0; i < 4; ++i)
	{
		if (other._learnedMateria[i])
			_learnedMateria[i] = other._learnedMateria[i]->clone();
		else
			_learnedMateria[i] = NULL;
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
	if (this != &other) {
		for (int i = 0; i < 4; ++i)
		{
			delete _learnedMateria[i];
			if (other._learnedMateria[i])
				_learnedMateria[i] = other._learnedMateria[i]->clone();
			else
				_learnedMateria[i] = NULL;
		}
	}
	return *this;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; ++i)
	{
		delete _learnedMateria[i];
	}
}

void MateriaSource::learnMateria(AMateria *m) {
	for (int i = 0; i < 4; ++i) {
		if (_learnedMateria[i] == NULL) {
			_learnedMateria[i] = m;
			break;
		}
	}
}

AMateria *MateriaSource::createMateria(const std::string &type) {
	for (int i = 0; i < 4; ++i)
	{
		if (_learnedMateria[i] && _learnedMateria[i]->getType() == type)
			return _learnedMateria[i]->clone();
	}
	return NULL;
}

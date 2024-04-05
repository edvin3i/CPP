#include "includes/Character.hpp"

Character::Character(const std::string &name) : _name(name), _invSize(0) {
	for(int i = 0; i < 4; ++i)
	{
		_inventory[i] = NULL;
	}
}

Character::Character(const Character &other) : _name(other._name), _invSize(other._invSize){
	for(int i = 0; i < other._invSize; ++i)
	{
		_inventory[i] = other._inventory[i]->clone();
	}
}

Character &Character::operator=(const Character &other) {
	if (this != &other) {
		for (int i = 0; i < _invSize; ++i) {
			delete _inventory[i];
			_inventory[i] = NULL;
		}
		_invSize = 0; // Сбрасываем размер инвентаря перед копированием
		for (int i = 0; i < other._invSize; ++i) {
			if (other._inventory[i] != NULL)
				_inventory[i] = other._inventory[i]->clone();
			else
				_inventory[i] = NULL;
		}
		_invSize = other._invSize; // Обновляем размер инвентаря после копирования
	}
	return *this;
}



Character::~Character() {
	for(int i = 0; i < _invSize; ++i) {
		if (_inventory[i] != NULL) { // Добавляем проверку перед удалением
			delete _inventory[i];
			_inventory[i] = NULL; // Обнуляем указатель после удаления
		}
	}
}

std::string const &Character::getName() const {
	return this->_name;
}

void Character::equip(AMateria *m) {
	if (_invSize < 4 && m) {
		_inventory[_invSize++] = m;
	}
}

void Character::unequip(int idx) {
	if (idx >= 0 && idx < _invSize && _inventory[idx]) {
		_inventory[idx] = NULL; // Отсоединяем материю, не удаляя объект
		for (int i = idx; i < _invSize - 1; ++i) {
			_inventory[i] = _inventory[i + 1]; // Сдвигаем остальные материи влево
		}
		_inventory[_invSize - 1] = NULL; // Обнуляем последний активный элемент после сдвига
		_invSize--;
	}
}

void Character::use(int idx, ICharacter &target) {
	if (idx >=0 && idx < _invSize && _inventory[idx])
	{
		_inventory[idx]->use(target);
	}
}

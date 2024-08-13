#include "Array.hpp"

template<typename T>
Array<T>::Array(): _size(0), _elements(NULL) {
	std::cout << YELLOW"Default constructor (without parameter) is called."RESET \
				<< std::endl;
}

template<typename T>
Array<T>::Array(unsigned int n): _size(n),  _elements(new T[n]) {
	std::cout << YELLOW"Constructor with parameter n = "RESET << n \
				<< YELLOW" is called."RESET << std::endl;
}

template<typename T>
Array<T>::~Array() {
	std::cout << BRIGHT_BLACK"Destructor is called."RESET << std::endl;
	delete[] _elements;
}

template<typename T>
Array<T> &Array<T>::operator=(const Array<T> &other) {
	if (this != &other) {
		T *tmp = new T[other.size()];
		for (size_t i = 0; i < other.size(); ++i) {
			tmp[i] = other._elements[i];
		}
		delete[] _elements;
		_elements = tmp;
		_size = other.size();
	}
	return *this;
}

template<typename T>
Array<T>::Array(const Array<T> &other): _size(other.size()), \
										_elements(new T[other.size()]) {
	for (size_t i = 0; i < this->_size; ++i) {
		_elements[i] = other._elements[i];
	}

}

template<typename T>
const T &Array<T>::operator[](unsigned int i) const {
	if (i >= _size) {
		std::cerr << RED"(1) Attempted to access index "RESET << i \
					<< RED" but the array size is "RESET << this->_size << std::endl;
		throw Array<T>::IndexIsOutOfBounds();
	}
	return _elements[i];
}

template<typename T>
T &Array<T>::operator[](unsigned int i) {
	if (i >= this->_size) {
		std::cerr << RED"(2) Attempted to access index "RESET << i \
					<< RED" but the array size is "RESET << this->_size << std::endl;
		throw Array<T>::IndexIsOutOfBounds();
	}
	return _elements[i];
}

template<typename T>
size_t Array<T>::size() const {
	return this->_size;
}

template<typename T>
const char *Array<T>::IndexIsOutOfBounds::what() const throw() {
	return "ERROR: Index Is Out Of Bounds!";
}

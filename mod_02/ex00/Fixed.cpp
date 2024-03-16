#include "includes/Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	num_val = 0;
}

Fixed::Fixed(const Fixed &other_obj) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other_obj;
}

Fixed &Fixed::operator=(const Fixed &other_obj) {
	std::cout << "Copy assignment operator called" << std::endl;
	setRawBits(other_obj.getRawBits());
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return num_val;
}

void Fixed::setRawBits(const int raw) {
	//std::cout << "setRawBits member function called" << std::endl;
	num_val = raw;
}

#include "includes/Fixed.hpp"

Fixed::Fixed() : num_val(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int init_val) {
	std::cout << "Int constructor called" << std::endl;
	num_val = init_val << bits;
}

Fixed::Fixed(const float init_val) {
	std::cout << "Float constructor called" << std::endl;
	num_val = roundf(init_val * static_cast<float>(1 << bits));
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
	//std::cout << "getRawBits member function called" << std::endl;
	return num_val;
}

void Fixed::setRawBits(const int raw) {
	//std::cout << "setRawBits member function called" << std::endl;
	num_val = raw;
}

float Fixed::toFloat(void) const {
	return static_cast<float>(num_val) / (1 << bits);
}
int Fixed::toInt(void) const {
	return num_val / (1 << bits);
}

std::ostream &operator<<(std::ostream &out_stream, const Fixed &fixed) {
	out_stream << fixed.toFloat();
	return out_stream;
}

#include "includes/Fixed.hpp"

Fixed::Fixed() : num_val(0) {
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int init_val) {
	//std::cout << "Int constructor called" << std::endl;
	num_val = init_val << bits;
}

Fixed::Fixed(const float init_val) {
	//std::cout << "Float constructor called" << std::endl;
	num_val = roundf(init_val * (float)(1 << bits));
}

Fixed::Fixed(const Fixed &other_obj) {
	//std::cout << "Copy constructor called" << std::endl;
	*this = other_obj;
}

Fixed &Fixed::operator=(const Fixed &other_obj) {
	//std::cout << "Copy assignment operator called" << std::endl;
	setRawBits(other_obj.getRawBits());
	return *this;
}

Fixed::~Fixed() {
	//std::cout << "Destructor called" << std::endl;
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
	return (float)(num_val) / (1 << bits);
}

int Fixed::toInt(void) const {
	return num_val / (1 << bits);
}

// Comparison operators overload

bool Fixed::operator>(const Fixed &other_obj) const {
	return this->num_val > other_obj.num_val;
}

bool Fixed::operator<(const Fixed &other_obj) const {
	return this->num_val < other_obj.num_val;
}

bool Fixed::operator>=(const Fixed &other_obj) const {
	return this->num_val >= other_obj.num_val;
}

bool Fixed::operator<=(const Fixed &other_obj) const {
	return this->num_val <= other_obj.num_val;
}

bool Fixed::operator==(const Fixed &other_obj) const {
	return this->num_val == other_obj.num_val;
}

bool Fixed::operator!=(const Fixed &other_obj) const {
	return this->num_val != other_obj.num_val;
}

// Arithmetic operators overload

Fixed Fixed::operator+(const Fixed &other_obj) {
	Fixed result;
	result.setRawBits(this->num_val + other_obj.num_val);
	return result;

}

Fixed Fixed::operator-(const Fixed &other_obj) {
	Fixed result;
	result.setRawBits(this->num_val - other_obj.num_val);
	return result;
}

Fixed Fixed::operator*(const Fixed &other_obj) {
	Fixed result;
	float a = this->toFloat();
	float b = other_obj.toFloat();
	result = Fixed(a * b);
	return result;
}

Fixed Fixed::operator/(const Fixed &other_obj) {
	Fixed result;
	float a = this->toFloat();
	float b = other_obj.toFloat();
	if (b != 0.0f)
		result = Fixed(a / b);
	else
	{
		std::cerr << "Error: division by zero!" << std::endl;
		return 0;
	}
	return result;
}

// Increment operators overload

Fixed Fixed::operator++() {
	this->num_val += 1;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp = *this;
	++(*this);
	return temp;
}

// Decrement operators overload

Fixed Fixed::operator--() {
	this->num_val -= 1;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed temp = *this;
	--(*this);
	return temp;
}

// min and max

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	if (a < b)
		return a;
	else
		return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	if (a < b)
		return a;
	else
		return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	if (a > b)
		return a;
	else
		return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	if (a > b)
		return a;
	else
		return b;
}

// Output operator overload

std::ostream &operator<<(std::ostream &out_stream, const Fixed &fixed) {
	out_stream << fixed.toFloat();
	return out_stream;
}

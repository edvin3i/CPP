#pragma once
#ifndef EX00_FIXED_HPP
#define EX00_FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed {

public:
	// default constructor
	Fixed(void);
	// Int constructor
	Fixed(const int init_val);
	// Float constructor
	Fixed(const float init_val);
	// copy constructor
	Fixed(const Fixed &other_obj);
	// Operators overloads
	Fixed &operator=(const Fixed &other_obj);
	Fixed operator+(const Fixed &other_obj);
	Fixed operator-(const Fixed &other_obj);
	Fixed operator*(const Fixed &other_obj);
	Fixed operator/(const Fixed &other_obj);

	bool operator>(const Fixed &other_obj) const;
	bool operator<(const Fixed &other_obj) const;
	bool operator>=(const Fixed &other_obj) const;
	bool operator<=(const Fixed &other_obj) const;
	bool operator==(const Fixed &other_obj) const;
	bool operator!=(const Fixed &other_obj) const;

	Fixed operator++();
	Fixed operator++(int);
	Fixed operator--();
	Fixed operator--(int);

	// min methods
	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed &min(const Fixed &a, const Fixed &b);

	// max methods
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &max(const Fixed &a, const Fixed &b);

	// destructor
	~Fixed();
	// getter
	int getRawBits(void) const;
	// setter
	void setRawBits(int const raw);
	// additional methods
	float toFloat(void) const;
	int toInt(void) const;

private:
	int num_val;
	static const int bits = 8;
};

std::ostream &operator<<(std::ostream &out_stream, const Fixed &fixed);

#endif

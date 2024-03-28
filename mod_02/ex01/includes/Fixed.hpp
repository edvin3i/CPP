#ifndef FIXED_HPP
#define FIXED_HPP

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
	// copy assignment operator overload
	Fixed &operator=(const Fixed &other_obj);
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

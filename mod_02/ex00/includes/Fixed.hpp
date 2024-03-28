#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {

public:
	// default constructor
	Fixed();
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

private:
	int num_val;
	static const int bits = 8;
};


#endif

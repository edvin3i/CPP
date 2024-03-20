#pragma once
#ifndef EX03_POINT_HPP
#define EX03_POINT_HPP

#include "Fixed.hpp"

class Point {

public:
	Point();
	Point(const float init_x, const float init_y);
	Point(const Point &other);
	Point &operator=(const Point &other);
	~Point();

	Fixed getX() const;
	Fixed getY() const;


private:
	const Fixed x;
	const Fixed y;


};

bool bsp(const Point &A, const Point &B, \
							const Point &C, const Point &P);

#endif

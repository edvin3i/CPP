#include "includes/Point.hpp"


Point::Point() : x(0), y(0) {
}

Point::Point(const float init_x, const float init_y) : x(Fixed(init_x)), y(Fixed(init_y)) {
}

Point::Point(const Point &other) : x(other.x), y(other.y) {
}

Point &Point::operator=(const Point &other) {
	(void) other;
	return *this;
}

Point::~Point() {
}

Fixed Point::getX() const {
	return this->x;
}

Fixed Point::getY() const {
	return this->y;
}

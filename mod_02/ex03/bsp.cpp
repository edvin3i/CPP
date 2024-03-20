#include "includes/Point.hpp"

Fixed multiplyVector(const Point &A, const Point &B, const Point &P) {

	Fixed result = (B.getX() - A.getX()) * (P.getY() - A.getY()) - \
				(P.getX() - A.getX()) * (B.getY() - A.getY());

	return result;
}

bool isPointOnSide(Point A, Point B, Point P) {

	Fixed min_x = Fixed::min(A.getX(), B.getX());
	Fixed max_x = Fixed::max(A.getX(), B.getX());
	Fixed min_y = Fixed::min(A.getY(), B.getY());
	Fixed max_y = Fixed::max(A.getY(), B.getY());

	bool result = P.getX() >= min_x && P.getX() <= max_x && \
				P.getY() >= min_y && P.getY() <= max_y;

	return result;
}

bool bsp(const Point &A, const Point &B, \
							const Point &C, const Point &P) {

	Fixed vec1 = multiplyVector(A, B, P);
	Fixed vec2 = multiplyVector(C, A, P);
	Fixed vec3 = multiplyVector(B, C, P);

	if (((vec1 == 0) && isPointOnSide(A, B, P)) || \
		((vec2 == 0) && isPointOnSide(C, A, P)) || \
		((vec3 == 0) && isPointOnSide(B, C, P))) {
		return false;
	}

	bool result = (vec1 >= 0 && vec2 >= 0 && vec3 >= 0) || \
				(vec1 <= 0 && vec2 <= 0 && vec3 <= 0);

	return result;
}
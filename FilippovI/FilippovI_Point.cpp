#include "stdafx.h"
#include "FilippovI_Point.h"

Point Point::operator+ (const Point& p) const {
	return Point(x + p.x, y + p.y, z + p.z);
}

Point Point::operator- (const Point& p) const {
	return Point(x - p.x, y - p.y, z - p.z);
}

Point Point::operator^ (const Point& p) const {
	return Point(y*p.z - z * p.y, p.x*z - x * p.z, x*p.y - y * p.x);
}

double Point::operator*(const Point& p) const {
	return x * p.x + y * p.y + z * p.z;
}

Point Point::operator*(double d) const {
	return Point(x*d, y*d, z*d);
}

double Point::countPosition(const std::vector<double>coef) const {
	return x * coef[0] + y * coef[1] + z * coef[2] + coef[3];
}

double Point::norma() const {
	return sqrt(x*x + y * y + z * z);
}

double Point::mult(const Point& p) {
	return x * p.y - y * p.x;
}

bool Point::isInside(const Point & p1, const Point & p2) const {
	if (fabs((*this - p1).norma() + (p2 - *this).norma() - (p1 - p2).norma()) < eps)
		return true;
	else return false;
}

void Point::normalize() {
	double n = norma();
	if (n < eps) return;
	x /= n, y /= n, z /= n;
}
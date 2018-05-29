#pragma once
#include<vector>
class Point
{
private:
	double x, y, z;
public:
	Point() {}

	Point(double x, double y, double z) : x(x), y(y), z(z) {}

	double getX() const {
		return x;
	}

	double getY() const {
		return y;
	}

	double getZ() const {
		return z;
	}

	Point operator+ (const Point& p) const;

	Point operator- (const Point& p) const;

	Point operator^ (const Point& p) const;

	double operator* (const Point& p) const;

	Point operator* (double d) const;

	double countPosition(const std::vector<double>coef) const;

	double norma() const;

	double mult(const Point& p);

	bool isInside(const Point& p1, const Point& p2) const;

	void normalize();
};


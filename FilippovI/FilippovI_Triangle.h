#pragma once
#include <vector>
class Triangle
{
private:
	std::vector<Point> points;

	std::vector<Point> getPoints() const {
		return points;
	}

	std::vector<double> getCoef() const;

	bool isCross(const Point& p1, const Point& p2) const;

	bool isDegenerated() const;

	bool checkPlane(const Point& p1, const Point& p2) const;

	bool isInside(const Point& p) const;

	bool checkIntersect(const Point& p1, const Point& p2, const Point& p3, const Point& p4) const;
public:
	Triangle() {}

	Triangle(const Point& p1, const Point& p2, const Point& p3);

	bool isCross(const Triangle& other) const;
};


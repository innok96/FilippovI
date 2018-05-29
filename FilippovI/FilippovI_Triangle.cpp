#include "stdafx.h"
#include "FilippovI_Triangle.h"

Triangle::Triangle(const Point& p1, const Point& p2, const Point& p3) {
	points.push_back(p1);
	points.push_back(p2);
	points.push_back(p3);
}

bool Triangle::isCross(const Triangle& other) const {
	std::vector<Point>pts = other.getPoints();
	return isCross(pts[0], pts[1]) || isCross(pts[0], pts[2]) || isCross(pts[1], pts[2]);
}

std::vector<double> Triangle::getCoef() const {
	std::vector<double>coef(4);
	Point p((points[1] - points[0]) ^ (points[2] - points[0]));
	coef[0] = p.getX(), coef[1] = p.getY(), coef[2] = p.getZ();
	coef[3] = -(coef[0] * points[0].getX() + coef[1] * points[0].getY() + coef[2] * points[0].getZ());
	return coef;
}

bool Triangle::checkPlane(const Point & p1, const Point & p2) const {
	if (checkIntersect(p1, p2, points[0], points[1])) return true;
	if (checkIntersect(p1, p2, points[1], points[2])) return true;
	if (checkIntersect(p1, p2, points[0], points[2])) return true;
	return isInside(p1);
}

bool Triangle::isInside(const Point & p) const {
	if (p.isInside(points[0], points[1]) || p.isInside(points[0], points[2]) || p.isInside(points[1], points[2])) return true;
	Point p1(p - points[0]), p2(p - points[1]), p3(p - points[2]);
	p1.normalize(), p2.normalize(), p3.normalize();
	double angle1 = acos(p1*p2), angle2 = acos(p1*p3), angle3 = acos(p2*p3);
	double sum = angle1 + angle2 + angle3;
	return fabs(angle1 + angle2 + angle3 - 2 * PI) < eps;
}

bool Triangle::checkIntersect(const Point & p1, const Point & p2, const Point & p3, const Point & p4) const {
	Point v1(p2 - p1), v2(p4 - p3), v3(p3 - p2);
	if (fabs(v1*(v2^v3)) > eps) return false;
	Point p21(p1 - p2), p34(p4 - p3), p24(p4 - p2);
	if ((p21^p34).norma() < eps) {
		if (p3.isInside(p1, p2) || p4.isInside(p1, p2))
			return true;
		else return false;
	}
	double u = p24.mult(p34) / p21.mult(p34), v = p21.mult(p24) / p21.mult(p34);
	return u >= 0 && u <= 1 && v >= 0 && v <= 1;
}

bool Triangle::isCross(const Point& p1, const Point& p2) const {
	if (isDegenerated()) return checkPlane(p1, p2);
	std::vector<double> coef = getCoef();
	double firstPointPosition = p1.countPosition(coef),
		secondPointPosition = p2.countPosition(coef);
	if (firstPointPosition*secondPointPosition > eps) return false;
	Point normal(coef[0], coef[1], coef[2]), v1(points[0] - p1), v2(p2 - p1);
	if (fabs(v2*normal) < eps) {
		if (fabs(v1*normal) > eps) return false;
		return checkPlane(p1, p2);
	}
	double mu = (v1*normal) / (v2*normal);
	Point maybeInsidePoint(p1 + ((p2 - p1)*mu));
	return isInside(maybeInsidePoint);
}

bool Triangle::isDegenerated() const {
	return ((points[1] - points[0]) ^ (points[2] - points[0])).norma() < eps;
}

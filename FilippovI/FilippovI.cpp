#include "stdafx.h"
#include "FilippovI.h"

bool foo(double t1[9], double t2[9]) {
	Triangle triangle1(Point(t1[0], t1[1], t1[2]), Point(t1[3], t1[4], t1[5]), Point(t1[6], t1[7], t1[8]));
	Triangle triangle2(Point(t2[0], t2[1], t2[2]), Point(t2[3], t2[4], t2[5]), Point(t2[6], t2[7], t2[8]));
	return triangle1.isCross(triangle2) || triangle2.isCross(triangle1);
}

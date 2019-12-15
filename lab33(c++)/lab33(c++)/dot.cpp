#include "dot.h"
#include <math.h>

Dot::Dot()
{
	x = 0; y = 0;
}
Dot::Dot(double x, double y)
{
	this->x = x;
	this->y = y;
}
double Dot::distanceTo(Dot point)
{
	a = point.x - x;
	b = point.y - y;
	return sqrt(pow(a, 2) + pow(b, 2));
}
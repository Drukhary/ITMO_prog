#include <string>
#include <math.h>
#include "Triangle.h"
//класс треугольника
Triangle::Triangle(Dot a, Dot b, Dot c)
{
	d1 = a;
	d2 = b;
	d3 = c;

}
double Triangle::Perimeter() 
{
	P = d1.distanceTo(d2) + d1.distanceTo(d3) + d2.distanceTo(d3);
	return P;
}
double Triangle::Squar() 
{
	double halfper = P / 2;
	S = halfper * (halfper - d1.distanceTo(d2)) * ((halfper - d1.distanceTo(d3)) * (halfper - d2.distanceTo(d3)));
	return S;
}

#pragma once
/* Triangle.h */
#include <string>
#include "dot.h"
using namespace std;
class Triangle
{
public:

	Triangle(Dot a, Dot b, Dot c);
	double Perimeter();
	double Squar();

private:
	Dot d1;
	Dot d2;
	Dot d3;
	double P;
	double S;
};

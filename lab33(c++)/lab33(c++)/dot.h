#pragma once
using namespace std;
class Dot
{
private:
	double x;
	double y;
	double a;
	double b;
public:
	Dot();
	Dot(double x, double y);
	double distanceTo(Dot point);
};


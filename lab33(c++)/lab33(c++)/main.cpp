#include "dot.h"
#include <math.h>
#include "Triangle.h"
#include <iostream>
#include <Windows.h>

using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Dot a(3, 2);
	Dot b(5, 6);
	Dot c(7, 1);
	Triangle trg(a, b, c);
	double perim = trg.Perimeter();
	double sqr = trg.Squar();
	cout << "Периметр треугольника: " << perim << endl;
	cout << "Площадь треугольника: " << sqr << endl;
	return 0;
}
#include <iostream>
#include <Windows.h>
using namespace std;

class Distance
{
private:
	int feet;
	float inches;
	const float MTF;
public:
	// ����������� �� ���������
	
	Distance() : feet(0), inches(0.0), MTF(3.280833F) { }
	// ����������� � ����� �����������
	Distance(int ft, float in) : feet(ft), inches(in), MTF(3.280833F) { }
	Distance(float meters) : MTF(3.280833F)
	{
		float fltfeet = MTF * meters; // ������� � ����
		feet = int(fltfeet); // ����� ������ �����
		inches = 12 * (fltfeet - feet); // ������� - ��� �����
	}
	void getdist()
	{
		cout << "\n������� ����� ����� : ";
		cin >> feet;
		cout << "\n������� ����� ������ : ";
		cin >> inches;
	}
	void showdist()
	{
		cout << feet << "\' - " << inches << "\"\n";
	}
	Distance operator+ (Distance) const;
	Distance operator- (Distance) const;
	operator float() const
	{
		float fracfeet = inches / 12;
		fracfeet += static_cast<float>(feet);
		return fracfeet / MTF;
	}
};int main(){	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);	Distance dist1(2.35F);	Distance dist2(2, 5);	float mtrs;	cout << "Dist1: " << dist1 << endl;	mtrs = static_cast<float>(dist1);	cout << "mtrs: " << mtrs << endl;	mtrs = dist2;	cout << "Dist2: " << dist2 << endl;	cout << "mtrs: " << mtrs;		return 0;}Distance Distance::operator+ (Distance d2) const
{
	int f = feet + d2.feet;
	float i = inches + d2.inches;
	if (i >= 12.0)
	{
		i -= 12.0;
		f++;
	}
	return Distance(f, i);
}Distance Distance::operator- (Distance d2) const
{
	int f;
	float i;
	f = feet;
	i = inches;
	if (feet > d2.feet)
	{
		f = feet - d2.feet;
		i = inches - d2.inches;

	}
	if (i >= 12.0)
	{
		i -= 12.0;
		f++;
	}
	return Distance(f, i);
}
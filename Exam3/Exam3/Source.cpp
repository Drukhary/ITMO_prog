#include <iostream>

using namespace std;

class employee
{
private:
	int number;
	float oklad;
public:
	employee(int num, float ok)
	{
		number=num;
		oklad = ok;
	}
	
	void print()
	{
		cout << number << endl;
		cout << oklad << endl;
	}

};
int main()
{
	int a1, a2, a3;
	float b1, b2, b3;
	cout << "Enter number ¹1 ";
	cin >> a1;
	cout << "Enter oklad ¹1 ";
	cin >> b1;

	cout << "Enter number ¹2 ";
	cin >> a2;
	cout << "Enter oklad ¹2 ";
	cin >> b2;

	cout << "Enter number ¹3 ";
	cin >> a3;
	cout << "Enter oklad ¹3 ";
	cin >> b3;

	employee* A = new employee(a1, b1);
	employee* B = new employee(a2, b2);
	employee* C = new employee(a3, b3);
	A->print();
	B->print();
	C->print();

	return 0;
}
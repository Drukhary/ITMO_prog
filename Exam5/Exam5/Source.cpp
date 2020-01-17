#include <iostream>
using namespace std;

int num = 1;

class number
{
private:
	int numbers;
public:
	
	

	number()
	{
		numbers = num;
		num += 1;
	}
	void print()
	{
		cout << "Your number " << numbers << endl;
	}

};
int main()
{
	number A;
	number B;
	number C;
	A.print();
	B.print();
	C.print();


	return 0;
}
#include <iostream>
#include <string>

using namespace std;

class publication
{
private:
	string name;
	float price;
public:
	void getdata()
	{
		cout << "Enter name ";
		cin >> name;
		cout << "Enter price ";
		cin >> price;
	}
	void putdata()
	{
		cout << name << endl;
		cout << price << endl;
	}
};
class book : public publication
{
private:
	int list;
public:
	void getdata()
	{
		publication::getdata(); 
		cout << "Enter lists ";
		cin >> list;
	}
	void putdata()
	{
		publication::putdata();
		cout << list << endl;
	}
};
class type : public publication
{
private:
	float time;
public:
	void getdata()
	{
		publication::getdata(); 
		cout << "Enter time ";
		cin >> time;
	}
	void putdata()
	{
		publication::putdata();
		cout << time;
	}
};
int main()
{

	book A;
	type B;
	A.getdata();
	A.putdata();
	B.getdata();
	B.putdata();


	return 0;
}
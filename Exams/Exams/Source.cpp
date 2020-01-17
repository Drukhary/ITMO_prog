#include <iostream>
#include <fstream>
#include <string>
using namespace std;



int main()
{
	struct Phone
	{
		string gorod;
		string stan;
		string account;
		string nomer;
	};

	Phone b;
	b.gorod = "(455)";
	b.stan = " 555";
	b.account = "-6578";
	b.nomer = b.gorod + b.stan + b.account;
	Phone a;
	string r;
	cin >> r;
	//cout << r[0]<< endl;
	//m = r[0] + r[1] + r[3];
	//cout << m << endl;
	string s = "(", d = ")", g = "-", m=" ";
	a.gorod = s + r[0] + r[1] + r[2]+d ;
	//m = "";
	//m = r[4] + r[5] + r[6];
	a.stan = m+ r[3] + r[4] + r[5];
	
	//m = r[7] + r[8] + r[9] + r[10];
	a.account = g + r[6] + r[7] + r[8] + r[9];
	a.nomer = a.gorod + a.stan + a.account;
	cout << b.nomer << endl;
	cout << a.nomer << endl;



	return 0;
}
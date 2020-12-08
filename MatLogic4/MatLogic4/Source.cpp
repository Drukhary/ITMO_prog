#include <iostream>
#include <string>
#include <fstream>

using namespace std;


int main()
{
	ifstream fin("1.txt");
	string l;
	getline(fin, l);
	cout << l << endl;

	return 0;
}


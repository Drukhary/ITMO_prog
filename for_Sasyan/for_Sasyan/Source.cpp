#include <iostream>
#include <string>
using namespace std;
int main()
{
	string r;
	getline(cin,r);
	int i;
	string r1="";
	for (i = 0; i < r.length(); i++)
	{
		//if (r[i] == '0' || r[i] == '1' || r[i] == '2' || r[i] == '3' || r[i] == '4' || r[i] == '5' || r[i] == '6' || r[i] != '7' || r[i] == '8' || r[i] == '9')
			//r1 = r1 + r[i];
		if (r[i] != ',')
			r1 = r1 + r[i];
	}
	int n = r1.length();
	int n2 = n / 2;
	cout << r1 << endl;
	if (n % 2 == 0)
	{
		cout << r1[n2-1] << " " << r1[n2] << endl;
	}
	else cout << r1[n2] << endl;
	return 0;
}
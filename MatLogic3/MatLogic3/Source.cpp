#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string Negation(string str, int n);
string Conjunction(string str, int n);
string Disjunction(string str, int n);
string Implication(string str, int n);
string Brackets(string str, int n);


string Brackets(string str, int n)
{

	string p1 = "", p2 = "", answ = "";
	int t1 = str.find("(");
	reverse(str.begin(), str.end());
	int t2 = str.find(')');
	reverse(str.begin(), str.end());
	t2 = n - t2 - 1;
	cout << n << " " << t2 << endl;
	if (t1 >= 0 && t2 >= 0)
	{
		for (int i = t1 + 1; i < t2; i++)
		{
			p1 += str[i];
		}
		p1 = Implication(p1, p1.size());
	}
	return p1;
}

string Negation(string str, int n)
{
	int t = str.find("!");
	int t1 = t;
	cout << t1 << endl;
	if (t >= 0)
	{
		str = "!,(" + str + ")";
	}
	cout << str << endl;
	str = Brackets(str, str.size());
	return str;
}
string Conjunction(string str, int n)
{
	string p1 = "", p2 = "", answ = "";
	int t = str.find("&"), j;
	cout << t << endl;
	reverse(str.begin(), str.end());
	int t1 = str.find(')');
	reverse(str.begin(), str.end());
	int t2 = str.find("(");
	t1 = n - t1 - 1;
	if (t > 0)
	{
		if (t<t2 || t>t1)
		{
			for (int i = 0; i < t; i++)
			{
				p1 += str[i];
			}
			for (int i = t + 1; i < n; i++)
			{
				p2 += str[i];
			}
			p1 = Conjunction(p1, p1.size());
			p2 = Conjunction(p2, p2.size());
			cout << p1 << " " << p2 << endl;
		}
		str = "&,(" + p1 + "),(" + p2 + ")";
	}
	cout << str << endl;
	str = Negation(str, str.size());
	return str;
}
string Disjunction(string str, int n)
{
	string p1 = "", p2 = "";
	int t = str.find("|"), j;
	cout << t << endl;
	reverse(str.begin(), str.end());
	int t1 = str.find(')');
	reverse(str.begin(), str.end());
	int t2 = str.find("(");
	t1 = n - t1 - 1;
	if (t > 0)
	{
		if (t<t2 || t>t1)
		{
			for (int i = 0; i < t; i++)
			{
				p1 += str[i];
			}
			for (int i = t + 1; i < n; i++)
			{
				p2 += str[i];
			}
			p1 = Disjunction(p1, p1.size());
			p2 = Disjunction(p2, p2.size());
			cout << p1 << " " << p2 << endl;
		}
		str = "|,(" + p1 + "),(" + p2 + ")";
	}
	cout << str << endl;
	str = Conjunction(str, str.size());
	return str;
}
string Implication(string str, int n)
{
	string p1 = "", p2 = "", answ = "";
	reverse(str.begin(), str.end());
	int t = str.find("->");
	int t1 = str.find(')');
	reverse(str.begin(), str.end());
	int t2 = str.find("(");
	t1 = n - t1 - 1;
	t = n - t - 1;
	if (t > 0)
	{
		if (t<t2 || t>t1)
		{
			for (int i = 0; i < t; i++)
			{
				p1 += str[i];
			}
			for (int i = t + 1; i < n; i++)
			{
				p2 += str[i];
			}
			p1 = Implication(p1, p1.size());
			p2 = Implication(p2, p2.size());
			cout << p1 << " " << p2 << endl;
		}
		str = "->,(" + p1 + "),(" + p2 + ")";
	}
	cout << str << endl;
	str = Disjunction(str, str.size());
	
	return str;
}

int main()
{
	char a = '&';
	char b = '|';
	string c = "->";
	char d = '!';

	ifstream fin("1.txt");
	string l, r, answ = "";
	string p1 = "", p2 = "";
	getline(fin, l);
	cout << l << endl;
	r = l;
	int n;
	n = r.size();

	int t1 = r.find("(");
	int t2 = r.find(")");

	string pop = Implication(r, n);
	cout << pop << endl;

	return 0;
}
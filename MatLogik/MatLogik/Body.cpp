#include <iostream>
#include <string>
#include <fstream>

using namespace std;
string Negation(string str, int n)
{
	int t = str.find("!");
	int t1 = str.find("!(");
	if (t >= 0 && t!=t1)
	{
		str.insert(t + 1, string("("));
		str += ")";
	}
	if (t >= 0 && t != t1)
		str = Negation(str, str.size());
	return str;
}
string Conjunction(string str, int n)
{
	string p1 = "", p2 = "", answ = "", str1,str2;
	int t = str.find("&");
	int j;
	if (t > 0)
	{
		for (int i = 0; i < t; i++)
		{
			p1 += str[i];
		}
		for (int i = t + 2; i < n; i++)
		{
			p2 += str[i];
		}
		int n1 = p1.size();
		int n2 = p2.size();
		//cout << p1 << " " << p2 << endl;
		j = p1.find("&");
		if (j >= 0)
		{
			p1 = Conjunction(p1, n1);
			
		}
		j = p2.find("&");
		if (j >= 0)
		{
			p2 = Conjunction(p2, n2);
		}
		cout << p1 << " " << p2 << endl;
		j = p1.find("!");
		//if (j >= 0)
		{
		//	p1 = Negation(p1, n1);

		}
		j = p2.find("!");
		//if (j >= 0)
		{
		//	p2 = Negation(p2, n2);
		}
	}
	int n1 = p1.size();
	int n2 = p2.size();
	//if (j >= 0)
	{
		p1 = Negation(p1, n1);

	}
	j = p2.find("!");
	//if (j >= 0)
	{
		p2 = Negation(p2, n2);
	}
	//cout << p1 << " " << p2 << endl;
	str = "&,(" + p1 + "),(" + p2 + ")";
	//cout << str << endl;
	return str;
}
string Disjunction(string str, int n)
{
	string p1 = "", p2 = "", answ = "";
	int t = str.find("|"),j;
	cout << t<< endl;
	if (t > 0)
	{
		for (int i = 0; i < t; i++)
		{
			p1 += str[i];
		}
		for (int i = t + 2; i < n; i++)
		{
			p2 += str[i];
		}
		//cout << p1 << " " << p2;
		int n1 = p1.size();
		int n2 = p2.size();
		j = p1.find("|");
		if (j  >= 0)
			p1 = Disjunction(p1, n1);
		j = p2.find("|");
		if (j >= 0)
			p2 = Disjunction(p2, n2);
		cout << p1 << " " << p2 << endl;
		j = p1.find("&");
		//if (j >= 0)
		{
			//p1 = Conjunction(p1, n1);

		}
		j = p2.find("&");
		//if (j >= 0)
		{
			//p2 = Conjunction(p2, n2);
		}
	}
	int n1 = p1.size();
	int n2 = p2.size();
	//if (j >= 0)
	{
		p1 = Conjunction(p1, n1);

	}
	j = p2.find("&");
	//if (j >= 0)
	{
		p2 = Conjunction(p2, n2);
	}
	//cout << p1 << " " << p2 << endl;
	str = "|,(" + p1 + "),(" + p2 + ")";
	return str;
}
string Implication(string str, int n)
{
	string p1 = "", p2 = "", answ = "";
	int t = str.find("->"),j;
	if (t > 0)
	{
		for (int i = 0; i < t; i++)
		{
			p1 += str[i];
		}
		for (int i = t + 2; i < n; i++)
		{
			p2 += str[i];
		}
		int n1 = p1.size();
		int n2 = p2.size();
		j = p1.find("->");
		if (j >= 0)
			p1 = Implication(p1, n1);
		j = p2.find("->");
		if (j > 0)
			p2 = Implication(p2, n2);
		cout << p1 << " " << p2 << endl;
		j = p1.find("|");
		//if (j > 0)
		{
		//	p1 = Disjunction(p1, n1);

		}
		j = p2.find("|");
		//if (j >= 0)
		{
		//	p2 = Disjunction(p2, n2);
		}
	}
	int n1 = p1.size();
	int n2 = p2.size();
	//if (j > 0)
	{
		p1 = Disjunction(p1, n1);

	}
	j = p2.find("|");
	//if (j >= 0)
	{
		p2 = Disjunction(p2, n2);
	}
	//cout << p1 << " " << p2 << endl;
	str = "->,(" + p1 + "),(" + p2 + ")";
	cout << str << endl;
	return str;
}

string Brackets(string str, int n)
{
	string l = "(";
	string r = ")";
	string p1 = "", p2 = "", answ = "";
	int t1 = str.find("(");
	reverse(str.begin(), str.end());
	int t2 = str.find(')');
	reverse(str.begin(), str.end());
	t2 = n - t2 - 1;
	cout << n << " " << t2 << endl;
	for (int i = t1 + 1; i < t2; i++)
	{
		p1 += str[i];
	}
	int t3= p1.find("(");
	if (t3 >= 0)
	{
		answ = Brackets(p1, p1.size());
	}
	string pop = Implication(answ, answ.size());

	return p1;
}

int main()
{
	char a = '&';
	char b = '|';
	string c = "->";
	char d = '!';

	ifstream fin("1.txt");
	string l, r, answ="";
	string p1="", p2="";
	getline(fin, l);
	cout << l <<endl;
	r = l;
	int n;
	n = r.size();

	int t1 = r.find("(");
	int t2 = r.find(")");

	string pop= Implication(r, n);
	//cout << pop << endl;

	return 0;
}
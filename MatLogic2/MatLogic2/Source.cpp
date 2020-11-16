#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string Negation(string str, int n);
string Conjunction(string str, int n);
string Disjunction(string str, int n);
string Implication(string str, int n);
string Brackets(string str, int n);

string Negation(string str, int n)
{
	int t = str.find("!");
	int t1 = t;
	if (t >= 0)
	{
		str.insert(t + 1, string("("));
		t1 += 2;
		while (str[t1 + 1] != '!' && str[t1 + 1] != '&' && str[t1 + 1] != '|' && str[t1 + 1] != '->' && t1+1<str.size()-1)
		{
			t1 += 1;
		}
		str.insert(t1-1, string(")"));

		for (int j = t + 1; j < str.size(); j++)
		{
			if (str[j] == '!')
				str = Negation(str, str.size());
		}
	}
	str = Conjunction(str, str.size());
	return str;
}

string Conjunction(string str, int n)
{
	string p1 = "", p2 = "", answ = "", str1, str2;
	int t = str.find("&"), t1=t,t2=t;
	if (t > 0)
	{
		while (str[t1 - 1] != '!' && str[t1 - 1] != '&' && str[t1 - 1] != '|' && str[t1 - 1] != '->' && t1 - 1 > 0)// && str[t1 - 1] != ')' && str[t1 - 1] != '(')
		{
			t1 -= 1;
		}
		str.insert(t1 + 1, string("("));

		while (str[t2 + 1] != '!' && str[t2 + 1] != '&' && str[t2 + 1] != '|' && str[t2 + 1] != '->' && t2 + 1 < str.size() - 1)// && str[t2 + 1] != ')' && str[t2 + 1] != '(')
		{
			t2 += 1;
		}
		str.insert(t1 - 1, string(")"));

		for (int j = t + 1; j < str.size(); j++)
		{
			if (str[j] == '&')
				str = Conjunction(str, str.size());
		}
	}
	str = Disjunction(str, str.size());
	return str;
}

string Disjunction(string str, int n)
{
	string p1 = "", p2 = "", answ = "";
	int t = str.find("|"), t1 = t, t2=t;
	if (t > 0)
	{
		while (str[t1 - 1] != '!' && str[t1 - 1] != '&' && str[t1 - 1] != '|' && str[t1 - 1] != '->' && t1 - 1 > 0)//str[t1 - 1] != ')' && str[t1 - 1] != '(')
		{
			t1 -= 1;
		}
		str.insert(t1 + 1, string("("));

		while (str[t2 + 1] != '!' && str[t2 + 1] != '&' && str[t2 + 1] != '|' && str[t2 + 1] != '->' && t2 + 1 < str.size() - 1)// str[t2 + 1] != ')' && str[t2 + 1] != '(')
		{
			t2 += 1;
		}
		str.insert(t1 - 1, string(")"));

		
		for (int j = t + 1; j < str.size(); j++)
		{
			if (str[j] == '|')
				str = Disjunction(str, str.size());
		}
	}
	str = Implication(str, str.size());
	return str;
}

string Implication(string str, int n)
{
	string p1 = "", p2 = "", answ = "";
	int t = str.find("->"), t1=t, t2=t;

	if (t > 0)
	{
		while (str[t1 - 1] != '!' && str[t1 - 1] != '&' && str[t1 - 1] != '|' && str[t1 - 1] != '->' && t1 - 1 >0 )//str[t1 - 1] != ')' && str[t1 - 1] != '(')
		{
			t1 -= 1;
		}
		str.insert(t1 + 1, string("("));

		while (str[t2 + 1] != '!' && str[t2 + 1] != '&' && str[t2 + 1] != '|' && str[t2 + 1] != '->' && t2 + 1 < str.size() - 1)// str[t2 + 1] != ')' && str[t2 + 1] != '(')
		{
			t2 += 1;
		}
		str.insert(t1 - 1, string(")"));

		for (int j = t + 1; j < str.size(); j++)
		{
			if (str[j] == '->')
				str = Implication(str, str.size());
		}
	}
	return str;
}

string Brackets(string str, int n)
{
	string l = "(";
	string r = ")";
	string p1 = "", p2 = "", answ = "";

	reverse(str.begin(), str.end());
	int t1 = str.find("(");
	reverse(str.begin(), str.end());
	int t2 = str.find(')');
	
	t1 = n - t1 - 1;
	//cout << n << " " << t2 << endl;
	for (int i = t1 + 1; i < t2; i++)
	{
		p1 += str[i];
	}
	p1 = Negation(p1, p1.size());


	//for (int j = t1 + 1; j < t2; j++)
	//{
	//	if (str[j] == '(')
	//		str = Implication(str, str.size());
	//}

	return p1;
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

	answ = Brackets(r, n);

	cout << answ;
	//int t1 = r.find("(");
	//int t2 = r.find(")");

	//string pop = Implication(r, n);
	//cout << pop << endl;

	return 0;
}
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

template <typename T, typename T1>
class Shariki {
private:
	T sharic;
	T1 opisanie;
public:
	Shariki(T shariki, T1 Opisanie)
	{
		sharic = shariki;
		opisanie = Opisanie;
	}
	void print()
	{
		cout << "Шарик: " << sharic << " Описание: " << opisanie << endl;
	}
};

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251); 
	Shariki <string, int> shar1("White", 2);
	Shariki <string, string> shar2("Yellow", "Broken");
	shar1.print();
	shar2.print();
	return 0;
}
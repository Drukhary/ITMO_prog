#include <iostream>
#include <string>
#include <windows.h>
using namespace std;
class Item
{
private:
	string title;
	double price;
	virtual void getdata()
	{
		cout << "\n������� ��������� : ";
		cin >> title;
		cout << "������� ���� : ";
		cin >> price;
	}
	virtual void putdata()
	{
		cout << "\n���������: " << title;
		cout << "\n����:" << price;
	}
};
{
private:
	int pages;
public:
	void getdata()
	{
		Item::getdata();
		cout << "������� ����� ������� : ";
		cin >> pages;
	}
	void putdata()
	{
		Item::putdata();
		cout << "\n�������: " << pages;
	}
};
{
private:
	double time;
public:
	void getdata()
	{
		Item::getdata();
		cout << "������� ����� �������� : ";
		cin >> time;
	}
	void putdata()
	{
		Item::putdata();
		cout << "\n����� �������� : " << time;
	}
};
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251); 
	Item* pubarr[100];
	char choice;
	do
	{
		cout << "\n������� ������ ��� ����� ��� ��������� �����(b / a) ? ";
		cin >> choice;
		if (choice == 'b')
			pubarr[n] = new Paperbook;
		else
			pubarr[n] = new AudioBook;
		pubarr[n++]->getdata();
		cout << "����������((� / n) ? ";
		cin >> choice;
	} while (choice == 'y');
		pubarr[j]->putdata(); //������� ������ � ����������
	cout << endl;
	return 0;
}
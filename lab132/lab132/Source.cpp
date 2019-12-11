#include <iostream>
#include <string>
#include <windows.h>
using namespace std;
class human
{
private:
	string name;
	string surname;
	string lastname;public:
	virtual void getdata()
	{
		cout << "\nВведите имя : ";
		cin >> name;
		cout << "\nВведите фамилию : ";
		cin >> surname;
		cout << "\nВведите отчество : ";
		cin >> lastname;
	}
	virtual void putdata()
	{
		cout << "\nИмя: " << name;
		cout << "\nФамилия: " << surname;
		cout << "\nОтчество: " << lastname;
	}
};class student : public human
{
private:
	int scores[5];
public:
	void getdata()
	{
		human::getdata();
		cout << "Введите оценки : ";
		cin >> scores[0] >> scores[1] >> scores[2] >> scores[3] >> scores[4];
	}
	void putdata()
	{
		human::putdata();
		cout << "\nСредний балл: " << (scores[0] + scores[1] + scores[2] + scores[3] + scores[4])/5;
	}
};class teacher : public human
{
private:
	double time;
public:
	void getdata()
	{
		human::getdata();
		cout << "Введите количество часов преподавания : ";
		cin >> time;
	}
	void putdata()
	{
		human::putdata();
		cout << "\nКоличество часов преподавания : " << time;
	}
};int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	human* pubarr[100];	int n = 1;
	char choice;
	do
	{
		cout << "\nВводить данные для студента или учителя (s / t) ? ";
		cin >> choice;
		if (choice == 's')
			pubarr[n] = new student;
		else
			pubarr[n] = new teacher;
		pubarr[n++]->getdata();
		cout << "Продолжать((у / n) ? ";
		cin >> choice;
	} while (choice == 'y');	for (int j = 0; j < n; j++) //цикл по всем объектам
		pubarr[j]->putdata(); //вывести данные о публикации
	cout << endl;
	return 0;
}
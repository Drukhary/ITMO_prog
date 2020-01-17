#include <iostream>
#include <Windows.h>
#include <string>
#include "OS.h"
#include "Version.h"
#include "User.h"
#include "time.h"


using namespace std;

string m;

class File
{
private:
	string title;
	string place;

public:
	virtual void getdata()
	{
		cout << "\n��������: ";
		cin >> title;
		cout << "������� ��������������: " << endl;
		cout<< "C:/";
		cin >> place;
	}
	virtual void putdata()
	{
		cout << "\n��������: " << title;
		cout << "\n��������������: �:/" << place;
	}
};

class TextFile : public File
{
private:
	string pages;
	string subject;
public:
	void getdata()
	{
		File::getdata();
		cout << "������� ���� ������: ";
		cin>>  subject;
		cout << "������� ����� c������: ";
		cin >> pages;
	}
	void putdata()
	{
		File::putdata();
		cout << "\n���� ������: " << subject;
		cout << "\n�������: " << pages;
	}
};

class AudioFile : public File
{
private:
	string time;
	string executor;
	string singer;
public:
	void getdata()
	{
		File::getdata();
		cout << "������� ����������� �����: ";
		cin >> executor;
		cout << "������� ����������� �����: ";
		cin >> singer;
		cout << "������� ����� �������� : ";
		cin >> time;
	}
	void putdata()
	{
		File::putdata();
		cout << "\n����������: " << executor;
		cout << "\n�����������: " << singer;
		cout << "\n����� �������� : " << time;
	}
};

class Tag : public File
{
private:
	string name;
public:
	void getdata()
	{
		File::getdata();
		cout << "������� �������� ��������� ��� ������: ";
		cin >> name;
	}
	void putdata()
	{
		File::putdata();
		cout << "\n�������� ������: " << name;
	}
};


void Security(string log, string pas)
{
	string yourlog;
	string yourpas;
	char c;
	string d;
	cout << "������� ����� � ������ ��� �����������" << endl;
	cout << "Enter login: ";
	cin >> yourlog;
	cout << "Enter password: ";
	cin >> yourpas;
	if (log == yourlog && pas == yourpas)
	{
		m = "yes";

	}
	else {
		cout << "Wrong!" << endl;
		cout << "Continue? (y/n): ";
		cin >> c;
		if (c == 'y')
			Security(log, pas);
		else {
			m = "no";
		}
	}
	

}



int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	string name;
	Version* verWin = new Version("7", "Professional");
	Version* verWin2 = new Version("7", "Home");
	Version* verWin3 = new Version("10", "Professoinal");

	Version* verLin = new Version("Mint", "18.2");
	Version* verLin2 = new Version("Ubuntu", "17.10");
	cout << "Aviable operating system: Windows or Linux" << endl;
	cout << "Operating system name: ";
	getline(cin, name);

	Version* yourVer = new Version("", "");


	int choose;
	if (name == "Windows")
	{
		cout << "Choose your version:" << endl;
		cout << "1. Windows 7 Professional" << endl;
		cout << "2. Windows 7 Home" << endl;
		cout << "3. Windows 10 Professional" << endl;
		cout << "Your choose: ";
		cin >> choose;
		if (choose == 1)
			yourVer = verWin;

		if (choose == 2)
			yourVer = verWin2;
		if (choose == 3)
			yourVer = verWin3;
	}

	if (name == "Linux")
	{
		cout << "Choose your version:" << endl;
		cout << "1. Linux Min 18.2" << endl;
		cout << "2. Linux Ubuntu 17.10" << endl;
		cout << "Your choose: ";
		cin >> choose;
		if (choose == 1)
			yourVer = verLin;
		if (choose == 2)
			yourVer = verLin2;
	}
	OS* yourOS = new OS(name, yourVer);
	string login;
	string password;
	cout << "Register your login and password" << endl;
	cout << "login: ";
	cin >> login;
	cout << "password: ";
	cin >> password;
	User* You = new User(login, password);
	yourOS->setUser(You);
	string time, data, country;
	cout << "������� �����: ";
	cin >> time;
	cout << "������� ����: ";
	cin >> data;
	cout << "������� ������: ";
	cin >> country;

	Country* my = new Country(time, data, country);

	cout << endl;
	Security(login, password);

	if (m == "yes")
	{
		File* pubarr[100];
		int n = 0;

		string choice;
		do
		{
			cout << "\n������� ������ ��� ���������� �����, ����� �����, ������ (text / audi / tag) ? ";
			cin >> choice;
			if (choice == "text")
			{
				pubarr[n] = new TextFile;

			}
			else if (choice == "audi")
			{
				pubarr[n] = new AudioFile;
			}
			else if (choice == "tag")
			{
				pubarr[n] = new Tag;
			}
			pubarr[n]->getdata();
			n++;
			cout << "����������((� / n) ? ";
			cin >> choice;
		} while (choice == "y" && n < 100);
		cout << endl;


		cout << "Your computer:" << endl;
		yourOS->displaywithUser();
		cout << endl;
		my->get_full_data();
		cout << endl;
		my->get_c();
		
		cout << endl;
		for (int j = 0; j < n; j++) //���� �� ���� ��������
		{
			cout << endl << "File �" << j + 1;
			pubarr[j]->putdata(); //������� ������ � ����������
			cout << endl;
		}
	}
	else
	{
		cout << "Your computer:" << endl;
		yourOS->displaywithUser();
		my->get_full_data();
		cout << endl;
		my->get_c();
	}

	return 0;
}
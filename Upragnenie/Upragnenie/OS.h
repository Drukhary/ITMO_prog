#pragma once
#include <string>
using namespace std;
#include "Version.h"
#include "User.h"

//имя и версия операционной системы
class OS
{
public:
	OS(string, Version*); // конструктор, версион - другой класс
	void set_name(string);
	string get_name();

	void setVersion(Version* text);
	Version getVersion();

	void display() const;
	void displayUser() const;
	void displaywithUser() const;


	void setUser(User* data);
	User getUser();


private:
	string name; // имя операционной системы
	Version* Ver; //версия операционной системы
	User* UserData;
};

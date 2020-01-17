#pragma once
#include <string>
using namespace std;
#include "Version.h"
#include "User.h"

//��� � ������ ������������ �������
class OS
{
public:
	OS(string, Version*); // �����������, ������� - ������ �����
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
	string name; // ��� ������������ �������
	Version* Ver; //������ ������������ �������
	User* UserData;
};

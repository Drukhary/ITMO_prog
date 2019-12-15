#include <iostream>
#include <string>
#include "OS.h"

using namespace std;

OS::OS(string name, Version* ver)
{
	OS::set_name(name);
	OS::setVersion(ver);
}

void OS::set_name(std::string name_os)
{
	OS::name = name_os;
}

std::string OS::get_name()
{
	return OS::name;
}

void OS::setVersion(Version* text)
{
	Ver = text;
}

Version OS::getVersion()
{
	return *Ver;
}

void OS::setUser(User* data)
{

	UserData = data;
}

User OS::getUser()
{
	return *UserData;
}

void OS::display() const
{
	cout << name << " " << Ver->getNumber() << " " << Ver->getCategory() << endl;
}

void OS::displayUser() const
{
	cout << "User login: " << UserData->get_login();
}

void OS::displaywithUser() const
{
	cout << name << " " << Ver->getNumber() << " " << Ver->getCategory() << endl;
	cout << "User login: " << UserData->get_login();
}

#include "Version.h"

Version::Version(string n)
{
	number = n;
	category = "����������";
}

Version::Version()
{
	number = "���";
	category = "����������";
}

Version::Version(string n, string type)
{
	number = n;
	category = type;
}

void Version::setNumber(string Number)
{
	number = Number;
}

string Version::getNumber()
{
	return number;
}

void Version::setCategory(string type)
{
	category = type;
}

string Version::getCategory()
{
	return category;
}
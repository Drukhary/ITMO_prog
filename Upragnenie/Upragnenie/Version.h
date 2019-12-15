#pragma once
#include <string>

using namespace std;

class Version
{
private:
	string number;
	string category;
public:
	Version();
	Version(string);
	Version(string, string);

	void setNumber(string Number);
	string getNumber();
	void setCategory(string type);
	string getCategory();
};

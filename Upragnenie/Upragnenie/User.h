#pragma once
#include <string>

using namespace std;

class User
{
private:
	string login;
	string password;
public:
	
	User(string, string);

	void set_login(string Login);
	string get_login();
	void set_password(string password);
	string get_password();
};

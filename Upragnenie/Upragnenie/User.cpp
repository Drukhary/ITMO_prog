#include "User.h"


User::User(string Login, string Password)
{
	login = Login;
	password = Password;
}

void User::set_login(string Login)
{
	login = Login;
}

string User::get_login()
{
	return login;
}

void User::set_password(string Password)
{
	password = Password;
}

string User::get_password()
{
	return password;
}
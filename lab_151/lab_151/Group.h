#pragma once /* Защита от двойного подключения заголовочного файла */
#include <string>
#include "Student.h"
#include "IdCard.h"
#include <list>
#include <algorithm>

using namespace std;

class Group
{
private:
	string name;
	list <Student> masSt;
	list <Student>::iterator iter;

public:
	Group(string name);
	Group();

	void setName(string newName);
	string getName();

	int getSize();

	void addStudent(Student newStudent);
	void delStudent(Student oldStudent);

	Student findStudent(string, string, IdCard*);

	void GroupSort();
	void GroupOut();
};

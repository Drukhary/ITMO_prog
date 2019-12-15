#include "IdCard.h"
#include <string>



IdCard::IdCard(int n)
{
	number = n;
	category = "Íå óñòàíîâëåíà";
}
IdCard::IdCard()
{
	number = 0;
	category = "Íå óñòàíîâëåíà";
}
IdCard::IdCard(int n, string cat)
{
	number = n;
	category = cat;
}
void IdCard::setNumber(int newNumber)
{
	number = newNumber;
}
int IdCard::getNumber()
{
	return number;
}
void IdCard::setCategory(string cat)
{
	category = cat;
}
string IdCard::getCategory()
{
	return category;
}


Student::Student(string name, string last_name, IdCard* id)
{
	Student::set_name(name);
	Student::set_last_name(last_name);
	Student::setIdCard(id);
}
void Student::setIdCard(IdCard* c)
{
	iCard = c;
}
IdCard Student::getIdCard()
{
	return *iCard;
}

int main()
{
	IdCard idc(123, “Áàçîâûé”);
	Student* student02 = new Student(name, last_name, idc);
	cout << ”IdCard: “ << student02->getIdCard().getNumber() << endl;
	cout << ”Category: “ << student02->getIdCard().getCategory() << endl;
	return 0;
}
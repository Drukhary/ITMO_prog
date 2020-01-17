#pragma once
#include <string>
using namespace std;
class time
{
private:
	std::string Time; // значение текущего времени
	std::string data; // значение текущей даты
public:

	time(std::string Time, std::string data)
	{
		this->Time = Time;             
		this->data = data;
	}
	void get_full_data() 
	{
		            
		cout << this->Time << endl;
		cout << this->data;
	}
	std::string get_time()
	{
		return this->Time;
	}
	std::string get_data()
	{
		return this->data;
	}
};

class Country : public time {
private:
	std::string country; //введенная пользователем страна
public:

	Country(
		std::string Time,
		std::string data,
		std::string сountry)
		:time(Time, data)
	{
		this->country = сountry;
	}
	string get_country()
	{
		return this->country;
	}
	void get_c()
	{
		cout << this->country;
	}
};

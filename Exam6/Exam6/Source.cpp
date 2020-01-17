#include <iostream>
#include <string>
using namespace std;

class time
{
private:
	int hours;
	int minutes;
	int seconds;
public:
	time()
	{
		hours = 0;
		minutes = 0;
		seconds = 0;
	}
	time(int hour, int minute, int second)
	{
		hours = hour;
		minutes = minute;
		seconds = second;
	}
	void print()
	{
		//if (seconds >= 60)
		//{
		//	seconds -= 60;
		//	minutes += 1;
		//}
		//if (minutes >= 60)
		//{
		//	minutes -= 60;
		//	hours += 1;
		//}
		//if (hours >= 24)
		//{
		//	hours -= 24;
		//}
		if (hours > 10)
			cout << hours;
		else cout << "0" << hours;
		cout << ":";
		if (minutes > 10)
			cout << minutes;
		else cout << "0" << minutes;
		cout << ":";
		if (seconds > 10)
			cout << seconds;
		else cout << "0" << seconds;
		cout << endl;
	}
	friend time operator+(time& A, time& B) {

		//return time(A.hours + B.hours, A.minutes + B.minutes, A.seconds + B.seconds);
		int hour, minute, second;
		hour = A.hours + B.hours;
		minute = A.minutes + B.minutes;
		second = A.seconds + B.seconds;
		if (second >= 60)
		{
			second -= 60;
			minute += 1;
		}
		if (minute >= 60)
		{
			minute -= 60;
			hour += 1;
		}
		if (hour >= 24)
		{
			hour -= 24;
		}
		return time(hour, minute, second);
	}
};
int main()
{
	time A(12, 59, 59);
	time B(11, 59, 59);
	time C;
	C = A + B;
	C.print();
	A.print();
	B.print();



	return 0;
}
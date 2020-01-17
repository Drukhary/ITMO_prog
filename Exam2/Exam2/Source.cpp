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
	time summ(time& A, time& B)
	{
		hours = A.hours + B.hours;
		minutes = A.minutes + B.minutes;
		seconds = A.seconds + B.seconds;
		if (seconds >= 60)
		{
			seconds -= 60;
			minutes += 1;
		}
		if (minutes >= 60)
		{
			minutes -= 60;
			hours += 1;
		}
		if (hours >= 24)
		{
			hours -= 24;
		}
		return time(hours, minutes, seconds);
	}
};
int main()
{
	time A(11, 59, 59);
	time B(11, 59, 59);
	time C;
	C.summ(A, B);
	C.print();
	A.print();
	B.print();




	return 0;
}
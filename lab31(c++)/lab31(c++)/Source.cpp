#include <iostream>
#include <string>
#include <cstdlib>
#include <windows.h>
#include <math.h>
using namespace std;

class Triangle
{
public:
	class ExScore //класс исключений
	{
	public:
		string origin; //для имени функции
		double iValue; //для хранения ошибочного значения

		ExScore(string r, double sc)
		{

			origin = r; //строка с именем виновника ошибки
			iValue = sc; //сохраненное неправильное значение
		}
	};
	
	void set_scores(double triangle_scores[])
	{
		for (int i = 0; i < 3; ++i) {
			

			scores[i] = triangle_scores[i];

		}
		if ((scores[0] + scores[1]) < scores[2])
		{
			throw ExScore("в функции set_scores()", triangle_scores[2]);
		}
		if ((scores[1] + scores[2]) < scores[0])
		{
			throw ExScore("в функции set_scores()", triangle_scores[0]);
		}
		if ((scores[0] + scores[2]) < scores[1])
		{
			throw ExScore("в функции set_scores()", triangle_scores[1]);
		}
	}
	// Установка среднего балла
	void set_area_score(double area)
	{
		area_score = area;
	}
	// Получение среднего балла
	double get_area_score()
	{
		return area_score;
	}
private:
	double scores[3]; // Промежуточные оценки
	double area_score; // Средний балл
};

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	// Создание объекта класса Student
	Triangle triangle01;
	//string name;
	//string last_name;
	double scores[3];
	// Ввод имени с клавиатуры
	// Сумма всех оценок
	double sum = 0;
	// Ввод промежуточных оценок
	for (int i = 0; i < 3; ++i) {
		cout << "Side " << i + 1 << ": ";
		cin >> scores[i];
		// суммирование
		sum += scores[i];
		cout << sum << endl;
	}

	try
	{


		// Сохранение промежуточных оценок в объект класса Student
		triangle01.set_scores(scores);
		//double area_score = sum / 5.0;
		//double p;
		//p= sum / 2;
		//cout << p << endl;
		double area_score = sqrt((sum/2) * ((sum / 2) - scores[0]) * ((sum / 2) - scores[1]) * ((sum / 2) - scores[2]));
		// Сохранение среднего балла в объект класса Student
		triangle01.set_area_score(area_score);
		cout << "Average ball for " << triangle01.get_area_score() << endl;
	}
	catch (Triangle::ExScore ex)
	{
		cout << "\nОшибка инициализации " << ex.origin;
		cout << "\nВведенное значение оценки " << ex.iValue <<
			" является недопустимым\n";
	}

	return 0;
}

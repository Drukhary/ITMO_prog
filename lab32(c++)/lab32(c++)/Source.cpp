#include <iostream>
#include <string>
#include <cstdlib>
#include <windows.h>
#include <math.h>
using namespace std;

class Triangle //класс треугольника
{
public:
	class ExScore //класс исключений
	{
	public:
		string origin; //для имени функции
		double iValue; //для хранения ошибочного значения

		ExScore(string r, double sc)
		{

			origin = r; //строка с номером стороны
			iValue = sc; //сохраненное неправильное значение стороны
		}
	};

	void set_scores(double triangle_scores[]) //получение и проверка сторон
	{
		for (int i = 0; i < 3; ++i) {


			scores[i] = triangle_scores[i];

		}
		if ((scores[0] + scores[1]) < scores[2]) //проверка сторон
		{
			throw ExScore("\nНеправильно задана сторона №3: ", triangle_scores[2]);
		}
		if ((scores[1] + scores[2]) < scores[0])
		{
			throw ExScore("\nНеправильно задана сторона №1: ", triangle_scores[0]);
		}
		if ((scores[0] + scores[2]) < scores[1])
		{
			throw ExScore("\nНеправильно задана сторона №2: ", triangle_scores[1]);
		}
	}
	// Установка площади
	void set_area_score(double area)
	{
		area_score = area;
	}
	// Получение площади
	double get_area_score()
	{
		return area_score;
	}
private:
	double scores[3]; // стороны
	double area_score; // площадь
};

void TryCatch(double scores[]) 
{
	double sum=0;
	Triangle triangle01;
	for (int i = 0; i < 3; i++) // ввод сторон
	{
		cout << "Side " << i + 1 << ": ";
		cin >> scores[i];
	}
	try
	{

		for (int i = 0; i < 3; i++)
		{
			sum += scores[i];
		}
		// Сохранение сторон в класс треугольника
		triangle01.set_scores(scores);
		double area_score = sqrt((sum / 2) * ((sum / 2) - scores[0]) * ((sum / 2) - scores[1]) * ((sum / 2) - scores[2]));
		// Сохранение площади в класс треугольника
		triangle01.set_area_score(area_score);
		cout << "Площадь равна " << triangle01.get_area_score() << endl;
	}
	catch (Triangle::ExScore ex)
	{
		cout << "\nОшибка инициализации " << ex.origin;
		cout << "\nВведенное значение стороны " << ex.iValue <<
			" является недопустимым\n";
		TryCatch(scores);
	}


}

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	double scores[3];
	TryCatch(scores);

	return 0;
}

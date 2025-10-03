// Project1.cpp: определяет точку входа для приложения.
//

#include "Project1.h"

using namespace std;

int main()
{	
	setlocale(LC_ALL, "russian");
	//вводим переменные double, так как double - вещественный тип данных (для деления(делить на float нельзя))
	double a, b, proizvedenie1, proizvedenie2, summa1, summa2, raznost1, raznost2, razmer_double, delenie1, delenie2;
	cin >> a;
	cin >> b;
	razmer_double = sizeof(double); // sizeof -- оператор для определения размера типа данных
	/*проводим операции над переменными :
	сложение
	вычитание
	усножение
	*/
	summa1 = a + b;
	summa2 = b + a;
	raznost1 = a - b;
	raznost2 = b - a;
	proizvedenie1 = a * b;
	proizvedenie2 = b * a;
	delenie1 = a / b;
	delenie2 = b / a;
	std::cout << "размер double" << razmer_double << std::endl;
	std::cout << summa1 << " double" << std::endl;
	std::cout << raznost1 << " double" << std::endl;
	std::cout << proizvedenie1 << " double" << std::endl;
	std::cout << summa2 << " double" << std::endl;
	std::cout << raznost2 << " double" << std::endl;
	std::cout << proizvedenie2 << " double" << std::endl;
	std::cout << delenie1 << " double" << std::endl;
	std::cout << delenie2 << " double" << std::endl;
	return 0;
}



// Project1.cpp: определяет точку входа для приложения.
//

#include "Project1.h"

using namespace std;

int main()
{	
	setlocale(LC_ALL, "russian");
	//вводим переменные double, так как double - тип данных с плавующей точкой(для деления)
	double a, b, proizvedenie1, proizvedenie2, summa1, summa2, raznost1, raznost2, razmer_double, delenie1, delenie2;
	cin >> a;
	cin >> b;
	razmer_double = sizeof(double); // sizeoff -- оператор для определения размера типа данных
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
	cout << "размер double" << razmer_double << endl;
	cout << summa1 << " double" << endl;
	cout << raznost1 << " double" << endl;
	cout << proizvedenie1 << " double" << endl;
	cout << summa2 << " double" << endl;
	cout << raznost2 << " double" << endl;
	cout << proizvedenie2 << " double" << endl;
	cout << delenie1 << " double" << endl;
	cout << delenie2 << " double" << endl;
	return 0;
}

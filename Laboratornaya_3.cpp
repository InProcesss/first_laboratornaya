#include "Laboratornaya_3.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "russian");
	int n, i = 1, nomer;
	float S = 0, number, maximum = -1;

	std::cout << "Введите количество чисел для последовательности" << std::endl;
	std::cin >> n;

	//Проверка числа n
	if (n < 1) {
		std::cout << "Неверное число, завершение программы" << std::endl;
		return 0;
	}
	//Ввод чиел последовательности, проверка их на условие, выявление наибольшего числа и его номера
	do {
		std::cin >> number;
		if (number > -0.36 && number <= 10.1) {
			S += number;
			if (number > maximum) {
				maximum = number;
				nomer = i;
				}
		}
		++i;
	} while (i <= n);
	//Проверка чисел последовательности
	if (S == 0) {
		std::cout << "Числа последовательности не удовлетворяют условию, завершение программы" << std::endl;
		return 0;
	}

	std::cout << "Сумма чисел: " << S << std::endl;
	std::cout << "Наибольшее число: " << maximum << std::endl;
	std::cout << "Номер наибольшего числа в последовательности: " << nomer << std::endl;


	//Пункт 2
	int X, proizvedenie = 1;
	std::cout << "Введите число |X| < 1000" << std::endl;
	std::cin >> X;
	
	//Проверка условия для X
	if (abs(X) >= 1000) {
		std::cout << "Неверное число, завершение программы" << std::endl;
		return 0;
	}
	//Модуль от X
	X = abs(X);
	//Случай, если число = 0
	if (X == 0) {
		std::cout << "Произведение цифр числа X = 0" << std::endl;
	}
	else { //Произведение
		while (X > 0) {
			proizvedenie *= (X % 10);
			X /= 10;
		}
		std::cout << "Произведение цифр числа X = " << proizvedenie << std::endl;
	}
	


	return 0;
}

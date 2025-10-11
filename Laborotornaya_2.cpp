
#include "Laborotornaya_2.h"
#include <string>
using namespace std;

int main()
{
	setlocale(LC_ALL, "russian");
	short A, bitValue;
	int i;
	std::cout << "Введите число A" << std::endl;
	std::cin >> A;

	std::cout << "Введите число i(номер бита) от 0 до 7" << std::endl;
	std::cin >> i;

	if ((i < 0) || (7 < i)) {
		std::cout << "Число i введено неверно, завершаю программу" << std::endl;
		return 0;
	}

	bitValue = (A >> i) & 1;

	//2 часть
	int B1,B2;
	string binary = "";
	if (bitValue != 0) {
		std::cout << "Введите число 1" << std::endl;
		std::cin >> B1;
		std::cout << "Введите число 2" << std::endl;
		std::cin >> B2;
		if (B1 % B2 == 0) {
			std::cout << "число1 / число2 = " << (B1 / B2) << std::endl;

		}
		if (B2 % B1 == 0) {
			std::cout << "число2 / число1 = " << (B2 / B1) << std::endl;
		}
		else{
			std::cout << "число2 * число1 = " << (B2 * B1) << std::endl;
		}
	}
	else {
		short result = A ^ ((i+1) | (i-1));
		std::cout << "число A с измененными i+1 и i+2 =" << result << std::endl;
	}



	int N;

	std::cout << "Введите номер ошибки: " << std::endl;
	std::cin >> N;


	switch (N) {
	case 1:
		std::cout << "Неисправность ЭБУ впрыска" << endl;
		break;
	case 2:
		std::cout << "Неисправность ДУТ" << endl;
		break;
	case 4:
		std::cout << "Повышенное напряжение" << endl;
		break;
	case 8:
		std::cout << "Пониженное напряжение" << endl;
		break;
	case 13:
		std::cout << "Отсутствует сигнал датчика кислорода" << endl;
		break;
	case 51:
		std::cout << "Неисправность работы ПЗУ" << endl;
		break;
	case 52:
		std::cout << "Неисправность работы ОЗУ" << endl;
		break;
	case 55:
		std::cout << "Слишком бедная смесь" << endl;
		break;
	case 61:
		std::cout << "Проблемы в работе датчика кислорода" << endl;
		break;
	default:
		std::cout << "Неизвестный код ошибки" << endl;
		break;
	}

	return 0;
}

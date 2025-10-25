// LABARATORNAYA_4.cpp: определяет точку входа для приложения.
//

#include "LABARATORNAYA_4.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "russian");

	int massive[6];
	for (int i = 0; i < 6; i++) {
		std::cout << "Ведите " << i + 1 << " число массива" << std::endl;
		std::cin >> massive[i];
	}

	int n = 0;
	for (int i = 0; i < 5; i++) {
		if (massive[i] == massive[i+1]){
			n++;
			break;
		}
	}

	if (n != 0) {
		for (int i = 0; i < 5; i++) {
			for (int j = i+1; j < 6; j++) {
				if (massive[i] > massive[j]) {
					std::swap(massive[i], massive[j]);
				}
			}
		}
		std::cout << "Cортированный массив:" << std::endl;
		for (int i = 0; i < 6; i++) {
			std::cout << massive[i] << " ";
		}
		std::cout << " " << std::endl;
	}


	int stroka1[4], stroka2[4], stroka3[4];
	int summa1 = 0, summa2 = 0, summa3 = 0;

	for (int i = 0; i < 4; i++) {
		std::cout << "Ведите " << i + 1 << " число 1 строки" << std::endl;
		std::cin >> stroka1[i];
		summa1 += abs(stroka1[i]);
	}

	for (int i = 0; i < 4; i++) {
		std::cout << "Ведите " << i + 1 << " число 2 строки" << std::endl;
		std::cin >> stroka2[i];
		summa2 += abs(stroka2[i]);
	}

	for (int i = 0; i < 4; i++) {
		std::cout << "Ведите " << i + 1 << " число 3 строки" << std::endl;
		std::cin >> stroka3[i];
		summa3 += abs(stroka3[i]);
	}

	if ((summa1 > summa2) && (summa1 > summa3)) {
		for (int i = 0; i < 4; i++) {
			stroka1[i] = 0;
		}
	}
	if ((summa2 > summa1) && (summa2 > summa3)) {
		for (int i = 0; i < 4; i++) {
			stroka2[i] = 0;
		}
	}
	if ((summa3 > summa2) && (summa3 > summa1)) {
		for (int i = 0; i < 4; i++) {
			stroka3[i] = 0;
		}
	}


	for (int i = 0; i < 4; i++) {
		std::cout << stroka1[i];
	}
	std::cout << " " << std::endl;
	for (int i = 0; i < 4; i++) {
		std::cout << stroka2[i];
	}
	std::cout << " " << std::endl;
	for (int i = 0; i < 4; i++) {
		std::cout << stroka3[i];
	}
	return 0;
}

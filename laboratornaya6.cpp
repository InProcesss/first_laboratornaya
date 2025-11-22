// laboratornaya6.cpp: определяет точку входа для приложения.
//

#include "laboratornaya6.h"

#include <iostream>
#include <cstdlib>

int** sozdatMatricu(int stroki, int stolbci) {
    int** matrica = (int**)malloc(stroki * sizeof(int*));
    for (int i = 0; i < stroki; i++) {
        matrica[i] = (int*)calloc(stolbci, sizeof(int)); 
    }
    return matrica;
}


void pokazatMatricu(int** matrica, int stroki, int stolbci) {
    for (int i = 0; i < stroki; i++) {
        for (int j = 0; j < stolbci; j++) {
            std::cout << matrica[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}


int* naytiNulevyeStolbci(int** matrica, int stroki, int stolbci, int& kolichestvo) {
    int* nulevyeStolbci = (int*)malloc(stolbci * sizeof(int));
    kolichestvo = 0;

    for (int j = 0; j < stolbci; j++) {
        bool estNol = false;
        for (int i = 0; i < stroki; i++) {
            if (matrica[i][j] == 0) {
                estNol = true;
                break;
            }
        }
        if (estNol) {
            nulevyeStolbci[kolichestvo] = j;
            kolichestvo++;
        }
    }

    
    if (kolichestvo < stolbci) {
        nulevyeStolbci = (int*)realloc(nulevyeStolbci, kolichestvo * sizeof(int));
    }

    return nulevyeStolbci;
}


int** udalitStolbci(int** matrica, int stroki, int& stolbci, int* stolbciDlyaUdaleniya, int kolichestvoUdaleniya) {
    if (kolichestvoUdaleniya == 0) return matrica;

    int novyeStolbci = stolbci - kolichestvoUdaleniya;

    
    matrica = (int**)realloc(matrica, stroki * sizeof(int*));

    for (int i = 0; i < stroki; i++) {
        
        int* novayaStroka = (int*)malloc(novyeStolbci * sizeof(int));
        int novyiIndexStolbca = 0;

        for (int j = 0; j < stolbci; j++) {
            bool nuzhnoUdalit = false;
            for (int k = 0; k < kolichestvoUdaleniya; k++) {
                if (j == stolbciDlyaUdaleniya[k]) {
                    nuzhnoUdalit = true;
                    break;
                }
            }

            if (!nuzhnoUdalit) {
                novayaStroka[novyiIndexStolbca] = matrica[i][j];
                novyiIndexStolbca++;
            }
        }

        
        free(matrica[i]);
        matrica[i] = novayaStroka;
    }

    stolbci = novyeStolbci;
    return matrica;
}


int** rasshiritMatricu(int** matrica, int& stroki, int& stolbci, int dobavitStrok, int dobavitStolbcov, int C, int D) {
    int novyeStroki = stroki + dobavitStrok;
    int novyeStolbci = stolbci + dobavitStolbcov;

    
    matrica = (int**)realloc(matrica, novyeStroki * sizeof(int*));

    
    for (int i = 0; i < stroki; i++) {
        matrica[i] = (int*)realloc(matrica[i], novyeStolbci * sizeof(int));
    }

    
    for (int i = stroki; i < novyeStroki; i++) {
        matrica[i] = (int*)calloc(novyeStolbci, sizeof(int));
    }

    
    for (int i = 0; i < novyeStroki; i++) {
        for (int j = 0; j < novyeStolbci; j++) {
            if (i >= stroki || j >= stolbci) { 
                matrica[i][j] = (i - 1) * C + (j - 1) * D;
            }
        }
    }

    stroki = novyeStroki;
    stolbci = novyeStolbci;
    return matrica;
}

void chast1() {
    std::cout << "часть 1" << std::endl;

    
    int** matrica = sozdatMatricu(2, 2);

    std::cout << "Введите 4 числа для матрицы" << std::endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            std::cin >> matrica[i][j];
        }
    }

    std::cout << "матрица" << std::endl;
    pokazatMatricu(matrica, 2, 2);

    
    int A, B, C, D;

    do {
        std::cout << "Введите A";
        std::cin >> A;
        if (A < 0) std::cout << "ошибка, введите снова" << std::endl;
    } while (A < 0);

    do {
        std::cout << "Введите B";
        std::cin >> B;
        if (B < 0) std::cout << "ошибка, введите снова" << std::endl;
    } while (B < 0);

    std::cout << "Введите C";
    std::cin >> C;
    std::cout << "Введите D";
    std::cin >> D;

    
    int stroki = 2, stolbci = 2;
    matrica = rasshiritMatricu(matrica, stroki, stolbci, A, B, C, D);

    std::cout << "Матрица после" << std::endl;
    pokazatMatricu(matrica, stroki, stolbci);

    
    int kolichestvoNulei;
    int* nulevyeStolbci = naytiNulevyeStolbci(matrica, stroki, stolbci, kolichestvoNulei);

    if (kolichestvoNulei > 0) {
        std::cout << "Столбцы с нулями";
        for (int i = 0; i < kolichestvoNulei; i++) {
            std::cout << nulevyeStolbci[i] << " ";
        }
        std::cout << std::endl;

        
        matrica = udalitStolbci(matrica, stroki, stolbci, nulevyeStolbci, kolichestvoNulei);

        std::cout << "Матрица после удаления" << stroki << "x" << stolbci << ":" << std::endl;
        pokazatMatricu(matrica, stroki, stolbci);
    }
    else {
        std::cout << "Нулей нет" << std::endl;
    }

    
    for (int i = 0; i < stroki; i++) {
        free(matrica[i]);
    }
    free(matrica);
    free(nulevyeStolbci);


}



void chast2() {
    std::cout << "Часть 2" << std::endl;

    double a, b;
    std::cout << "Введите a";
    std::cin >> a;
    std::cout << "Введите b";
    std::cin >> b;


    double* ukazatelA = new double(a);  
    double* ukazatelB = new double(b); 

    std::cout << "Исходные a = " << a << ", b = " << b << std::endl;

    *ukazatelA *= 3;

    double vremennaya = *ukazatelA;
    *ukazatelA = *ukazatelB;
    *ukazatelB = vremennaya;

    std::cout << "После обмена a = " << *ukazatelA << ", b = " << *ukazatelB << std::endl;

    delete ukazatelA;
    delete ukazatelB;
}


int main() {
    setlocale(LC_ALL, "russian");
    int vybor;
    std::cout << "Выберите часть:1 или 2" << std::endl;
    std::cin >> vybor;

    switch (vybor) {
    case 1:
        chast1();
        break;
    case 2:
        chast2();
        break;
    default:
        std::cout << "Неверное число" << std::endl;
    }


    return 0;
}
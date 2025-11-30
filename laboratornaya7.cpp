
#include "laboratornaya7.h"
#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <limits>
#include <cstdlib>
#include <ctime>

using namespace std;

std::vector<int> mainArray; 

void initializeArray() {
    std::cout << "СОЗДАНИЕ МАССИВА" << std::endl;
    std::cout << "Введите количество элементов массива";
    int size;
    std::cin >> size;

    if (size <= 0) {
        std::cout << "Неверный размер массива" << std::endl;
        return;
    }

    mainArray.resize(size);
    std::cout << "Введите " << size << " элементов массива:" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << "Элемент " << i + 1 << ": ";
        std::cin >> mainArray[i];
    }

    std::cout << "Массив успешно создан: ";
}

void showArray(const std::vector<int>& arrayToShow = mainArray) {
    if (arrayToShow.empty()) {
        std::cout << "Массив пуст" << std::endl;
        return;
    }

    std::cout << "[";
    for (size_t i = 0; i < arrayToShow.size(); i++) {
        std::cout << arrayToShow[i];
        if (i != arrayToShow.size() - 1) std::cout << " ";
    }
    std::cout << "]" << std::endl;
}

void addToStart() {
    if (mainArray.empty()) {
        std::cout << "Массив пуст. Сначала создайте массив." << std::endl;
        return;
    }

    int element;
    std::cout << "Введите элемент для добавления в начало: ";
    std::cin >> element;
    mainArray.insert(mainArray.begin(), element);
    std::cout << "Массив после: ";
    showArray();
}

void addToEnd() {
    if (mainArray.empty()) {
        std::cout << "Массив пуст. Сначала создайте массив." << std::endl;
        return;
    }

    int element;
    std::cout << "Введите элемент для добавления в конец: ";
    std::cin >> element;
    mainArray.push_back(element);
    std::cout << "Массив после: ";
    showArray();
}

void clearAll() {
    mainArray.clear();
    std::cout << "Массив очищен" << std::endl;
}

void findElement() {
    if (mainArray.empty()) {
        std::cout << "Массив пуст. Сначала создайте массив." << std::endl;
        return;
    }

    int element;
    std::cout << "Введите элемент для поиска: ";
    std::cin >> element;

    std::vector<int> indexes;
    for (size_t i = 0; i < mainArray.size(); i++) {
        if (mainArray[i] == element) {
            indexes.push_back(i);
        }
    }

    if (indexes.empty()) {
        std::cout << "[]" << std::endl;
    }
    else {
        std::cout << "[";
        for (size_t i = 0; i < indexes.size(); i++) {
            std::cout << indexes[i];
            if (i != indexes.size() - 1) std::cout << ",";
        }
        std::cout << "]" << std::endl;
    }
}

void variantTask() {
    if (mainArray.empty()) {
        std::cout << "Массив пуст. Сначала создайте массив." << std::endl;
        return;
    }

    std::cout << "Массив до выполнения: ";
    showArray();

    int maxElement = mainArray[0];
    for (size_t i = 1; i < mainArray.size(); i++) {
        if (mainArray[i] > maxElement) {
            maxElement = mainArray[i];
        }
    }

    int count = 0;
    for (size_t i = 0; i < mainArray.size(); i++) {
        if (mainArray[i] == maxElement) {
            count++;
        }
    }

    if (count == 1) {
        mainArray.insert(mainArray.begin(), maxElement);
    }
    else {
        for (size_t i = 0; i < mainArray.size(); ) {
            if (mainArray[i] == maxElement) {
                mainArray.erase(mainArray.begin() + i);
            }
            else {
                i++;
            }
        }
        mainArray.push_back(maxElement);
    }

    std::cout << "Массив после: ";
    showArray();
}

void showMenu() {
    if (mainArray.empty()) {
        std::cout << "Массив не создан" << std::endl;
        initializeArray();
        if (mainArray.empty()) {
            return; 
        }
    }

    int choice;
    do {
        std::cout << "\nМЕНЮ" << std::endl;
        std::cout << "0 - Выход" << std::endl;
        std::cout << "1 - Просмотр массива" << std::endl;
        std::cout << "2 - Добавить элемент в начало" << std::endl;
        std::cout << "3 - Добавить элемент в конец" << std::endl;
        std::cout << "4 - Очистка массива" << std::endl;
        std::cout << "5 - Поиск элемента" << std::endl;
        std::cout << "6 - Вариант 3" << std::endl;
        std::cout << "7 - Пересоздать массив" << std::endl;
        std::cout << "Выберите пункт: ";

        std::cin >> choice;

        switch (choice) {
        case 0:
            std::cout << "Выход" << std::endl;
            break;
        case 1:
            showArray();
            break;
        case 2:
            addToStart();
            break;
        case 3:
            addToEnd();
            break;
        case 4:
            clearAll();
            break;
        case 5:
            findElement();
            break;
        case 6:
            variantTask();
            break;
        case 7:
            initializeArray();
            break;
        default:
            std::cout << "Неверный выбор" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (choice != 0 && choice != 8);
}

//ПУНКТ 2
const int ARRAY_SIZE = 10;
using IntArray = std::array<int, ARRAY_SIZE>;


void fillWithRandom(IntArray& arrayToFill) {
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        arrayToFill[i] = (std::rand() % 21) - 10; 
    }
}


void showArray(const IntArray& arrayToShow) {
    std::cout << "[";
    for (int i = 0; i < ARRAY_SIZE; i++) {
        std::cout << arrayToShow[i];
        if (i != ARRAY_SIZE - 1) std::cout << " ";
    }
    std::cout << "]" << std::endl;
}

void sortAscendingByValue(IntArray arrayCopy) {

    for (int i = 0; i < ARRAY_SIZE - 1; i++) {
        for (int j = 0; j < ARRAY_SIZE - i - 1; j++) {
            if (arrayCopy[j] > arrayCopy[j + 1]) {
                std::swap(arrayCopy[j], arrayCopy[j + 1]);
            }
        }
    }

    std::cout << "Отсортированный массив: ";
    showArray(arrayCopy);
}


void sortAscendingByReference(IntArray& arrayReference) {

    for (int i = 0; i < ARRAY_SIZE - 1; i++) {
        for (int j = 0; j < ARRAY_SIZE - i - 1; j++) {
            if (arrayReference[j] > arrayReference[j + 1]) {
                std::swap(arrayReference[j], arrayReference[j + 1]);
            }
        }
    }
}

void sortDescendingByPointer(IntArray* arrayPointer) {
    for (int i = 0; i < ARRAY_SIZE - 1; i++) {
        for (int j = 0; j < ARRAY_SIZE - i - 1; j++) {
            if ((*arrayPointer)[j] < (*arrayPointer)[j + 1]) { 
                std::swap((*arrayPointer)[j], (*arrayPointer)[j + 1]);
            }
        }
    }
}

void demonstrateParameterPassing() {
    IntArray demoArray;
    fillWithRandom(demoArray);

    std::cout << "\n\nПУНКТ 2" << std::endl;

    std::cout << "\nИсходный массив:" << std::endl;

    showArray(demoArray);


    std::cout << "\nПередача по значению" << std::endl;
    std::cout << "Передача массива в функцию по значению создает копию массива." << std::endl;
    std::cout << "Изменения внутри функции не влияют на оригинальный массив." << std::endl;
    sortAscendingByValue(demoArray);
    std::cout << "Оригинальный массив после вызова: ";
    showArray(demoArray);


    std::cout << "\nПередача по сслыке" << std::endl;
    std::cout << "Передача массива по ссылке не создает копию." << std::endl;
    std::cout << "Работаем с оригинальным массивом." << std::endl;
    std::cout << "Изменения внутри функции сохраняются." << std::endl;
    sortAscendingByReference(demoArray);
    std::cout << "Оригинальный массив после вызова: ";
    showArray(demoArray);


    std::cout << "\nПередача по указателю" << std::endl;
    std::cout << "Передача указателя на массив не создает копию." << std::endl;
    std::cout << "Работаем с оригинальным массивом через указатель." << std::endl;
    std::cout << "Изменения внутри функции сохраняются." << std::endl;
    sortDescendingByPointer(&demoArray);
    std::cout << "Оригинальный массив после вызова: ";
    showArray(demoArray);

}

//ПУНКТ 3
void explainChoice() {
    std::cout << "\n\nПУНКТ 3" << std::endl;

    std::cout << "\nВ пункте 1 использован std::vector:" << std::endl;
    std::cout << " динамическое изменение размера - операции добавления в начало/конец," << std::endl;
    std::cout << "   очистка требуют изменения размера массива" << std::endl;

    std::cout << "\nВ пункте 2 использован std::array:" << std::endl;
    std::cout << " фиксированный размер - по условию требуется ровно 10 элементов" << std::endl;
    std::cout << " статическое выделение памяти - не требуется изменение размера" << std::endl;

    std::cout << "\nstd::vector и std::array выполняют одинаковую роль:" << std::endl;
    std::cout << "• Когда размер массива известен и не меняется" << std::endl;
    std::cout << "• Когда не требуется динамическое изменение размера" << std::endl;

}


int main() {
    setlocale(LC_ALL, "russian");

    std::srand(std::time(nullptr));

    int userChoice;
    do {
        std::cout << "ГЛАВНОЕ МЕНЮ" << std::endl;
        std::cout << "1. Пункт 1" << std::endl;
        std::cout << "2. Пункт 2" << std::endl;
        std::cout << "3. Объяснение выбора" << std::endl;
        std::cout << "0. Выход" << std::endl;
        std::cout << "Выберите пункт: ";
        std::cin >> userChoice;

        switch (userChoice) {
        case 1:
            showMenu();
            break;
        case 2:
            demonstrateParameterPassing();
            break;
        case 3:
            explainChoice();
            break;
        case 0:
            std::cout << "Выход из программы" << std::endl;
            break;
        default:
            std::cout << "Неверный выбор" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (userChoice != 0);

    return 0;
}
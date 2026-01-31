#include "1 LABA.h"
#include <iostream>
#include <string>
#include <cctype>
#include <stdexcept>

using namespace std;

class Car {
public:
    string brand;

    // Конструктор по умолчанию
    Car() : brand("Porshe"), model("911"),
        bodyNumber("12312"), regNumber("F666FF"), mileage(100) {
    }

    // Конструктор полного заполнения
    Car(string brand, string model, string bodyNumber,
        string regNumber, int mileage)
        : brand(brand), model(model), mileage(mileage) {
        setBodyNumber(bodyNumber);
        setRegNumber(regNumber);
    }

    // Конструктор копирования
    Car(const Car& other) {
        brand = other.brand;
        model = other.model;
        bodyNumber = other.bodyNumber;
        regNumber = other.regNumber;
        mileage = other.mileage;
    }

    // Деструктор
    ~Car() {
        cout << "Деструктор Car вызван" << endl;
    }

    // ===== GET =====
    string getBrand() const { return brand; }
    string getModel() const { return model; }
    string getBodyNumber() const { return bodyNumber; }
    string getRegNumber() const { return regNumber; }
    int getMileage() const { return mileage; }

    // ===== SET с try/catch =====

    void setBodyNumber(const string& number) {
        if (number.length() != 6)
            throw invalid_argument("Номер кузова должен состоять из 6 символов");

        for (char c : number) {
            if (!isalnum(c))
                throw invalid_argument("Номер кузова должен содержать только буквы и цифры");
        }

        bodyNumber = number;
    }

    void setRegNumber(const string& number) {
        if (number.length() != 6)
            throw invalid_argument("Госномер должен быть длиной 6 символов");

        if (!isalpha(number[0]) ||
            !isdigit(number[1]) ||
            !isdigit(number[2]) ||
            !isdigit(number[3]) ||
            !isalpha(number[4]) ||
            !isalpha(number[5])) {
            throw invalid_argument("Госномер должен быть в формате А555АА");
        }

        regNumber = number;
    }

    // Методы
    void rollbackMileage(int x) {
        if (x <= 0)
            throw invalid_argument("Скручивание должно быть положительным числом");

        if (mileage - x < 0)
            throw invalid_argument("Пробег не может быть отрицательным");

        mileage -= x;
    }

    void printInfo() const {
        std::cout << "Марка: " << brand << std::endl;
        std::cout << "Модель: " << model << std::endl;
        std::cout << "Номер кузова: " << bodyNumber << std::endl;
        std::cout << "Гос. номер: " << regNumber << std::endl;
        std::cout << "Пробег: " << mileage  << std::endl;
    }

protected:
    string model;

private:
    string bodyNumber;
    string regNumber;
    int mileage;
};




int main() {
    setlocale(LC_ALL, "russian");
    
    
    string brand_new = "LADA";
    try {
        Car car;

        car.brand = brand_new;          
        car.setBodyNumber("AH1834"); 
        car.setRegNumber("O888OO");
        car.rollbackMileage(10);        
        car.printInfo();
    }
    catch (const exception& e) {
        cout << "Ошибка: " << e.what() << endl;
    }

    return 0;
}

// Виконав Іван Єнко
#include <Windows.h>
#include <iostream>
#include <string>

// Абстрактний клас, який представляє автомобіль
class Car {
public:
    virtual void repair() = 0;
    virtual ~Car() = default;
};

// Конкретні реалізації автомобілів
class Sedan : public Car {
public:
    void repair() override {
        std::cout << "Repairing Sedan car." << std::endl;
    }
};

class SUV : public Car {
public:
    void repair() override {
        std::cout << "Repairing SUV car." << std::endl;
    }
};

// Фабричний клас, який визначає метод для створення автомобілів
class CarFactory {
public:
    virtual Car* createCar() = 0;
    virtual ~CarFactory() = default;
};

// Конкретні фабрики для створення конкретних типів автомобілів
class SedanFactory : public CarFactory {
public:
    Car* createCar() override {
        return new Sedan();
    }
};

class SUVFactory : public CarFactory {
public:
    Car* createCar() override {
        return new SUV();
    }
};

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    // Використання фабрики для створення об'єкта автомобіля
    CarFactory* factory = new SedanFactory();
    Car* car = factory->createCar();
    car->repair();

    // Очищення пам'яті
    delete car;
    delete factory;

    return 0;
}

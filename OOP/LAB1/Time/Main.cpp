#include "Time.hpp"
#include<iostream>
#include <iomanip>

int main() {
    setlocale(LC_ALL, "ru");
    // Создание объекта времени
    Time t1(10, 30, 45);
    std::cout << "Начальное время: " << t1.toString() << std::endl;

    // Сложение времен
    Time t2(2, 15, 20);
    Time sum = t1 + t2;
    std::cout << "Сумма времени: " << sum.toString() << std::endl;

    // Добавление времени в минутах
    t1.addMinutes(25);
    std::cout << "Время после добавления 25 минут: " << t1.toString() << std::endl;

    // Перевод времени в секунды
    std::cout << "Время в секундах: " << t1.toSeconds() << std::endl;

    return 0;
}
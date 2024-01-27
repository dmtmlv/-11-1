#include "Time.h"
#include <iostream>

int main() {
    setlocale(LC_ALL, "ru");
    // Создание объекта времени

    Time t1(13, 20, 59);
    Time t2(4, 15, 10);

    std::cout << "Начальное время t1: " << t1.getString() << std::endl;
    std::cout << "Добавочное время t2: " << t2.getString() << std::endl;

    // Сложение времен
    Time sum = t1 + t2;
    std::cout << "Сумма времени t1+t2: " << sum.getString() << std::endl;

    // Добавление времени в минутах
    t1.addMinutes(30);
    std::cout << "Время после добавления 30 минут: " << t1.getString() << std::endl;

    // Перевод времени в секунды
    std::cout << "Перевод времени в секундах: " << t1.convertToSeconds() << std::endl;

    // Перевод времени в минуты
    std::cout << "Перевод времени в минуты: " << t1.convertToMinutes() << std::endl;
    // Перевод времени в часы
    std::cout << "Перевод времени в часы: " << t1.convertToHours() << std::endl;

    return 0;
}

#pragma once
#include <iostream>
#include <iomanip>
#include <sstream>

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    // Конструктор с параметрами
    Time(int h, int m, int s);

    // Геттеры и сеттеры
    int getHours() const;
    int getMinutes() const;
    int getSeconds() const;
    void setHours(int h);
    void setMinutes(int m);
    void setSeconds(int s);

    // Сложение времени
    Time operator+(const Time& t) const;

    // Вычитание времени
    Time operator-(const Time& t) const;

    // Добавление времени в минутах
    void addMinutes(int m);

    // Перевод времени в секунды
    int toSeconds() const;

    // Преобразование в строку (в формате Часы:Минуты:Секунды)
    std::string toString() const;
};


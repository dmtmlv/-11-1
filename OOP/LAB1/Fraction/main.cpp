#include<iostream>
#include "Fraction.h"

int main() {
    setlocale(LC_ALL, "ru");
    // Создание дроби с конструктором с параметрами
    Fraction fraction(3, 4);

    // Использование геттеров
    std::cout << "Numerator: " << fraction.getNumerator() << std::endl;
    std::cout << "Denominator: " << fraction.getDenominator() << std::endl;

    // Использование сеттеров
    fraction.setNumerator(36);
    fraction.setDenominator(6);

    // Использование методов
    Fraction other(1, 1);
    Fraction sum = fraction.add(other);
    std::cout << "Сумма: " << sum.getNumerator() << "/" << sum.getDenominator() << std::endl;

    Fraction sub = fraction.subtract(other);
    std::cout << "Разница: " << sub.getNumerator() << "/" << sub.getDenominator() << std::endl;

    Fraction mul = fraction.multiply(other);
    std::cout << "Произведение: " << mul.getNumerator() << "/" << mul.getDenominator() << std::endl;

    Fraction div = fraction.divide(other);
    std::cout << "Частное: " << div.getNumerator() << "/" << div.getDenominator() << std::endl;
}
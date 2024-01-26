#include "Fraction.h"

Fraction::Fraction() {
    numerator = 0;
    denominator = 0;
}

    // Конструктор с параметрами
Fraction::Fraction(int num, int denom) {
        numerator = num;
        denominator = denom;
    }

    // Геттеры и сеттеры
    int Fraction::getNumerator() {
        return numerator;
    }

    int Fraction::getDenominator() {
        return denominator;
    }

    void Fraction::setNumerator(int num) {
        numerator = num;
    }

    void Fraction::setDenominator(int denom) {
        // Проверка делителя на ноль
        if (denom == 0) {
            throw std::runtime_error("Знаменатель не может быть равен нулю");
        }
        denominator = denom;
    }

    // Метод для сокращения дроби
    void Fraction::simplify() {
        int divisor = gcd(numerator, denominator);
        numerator /= divisor;
        denominator /= divisor;
    }

    // Метод для сложения дробей
    Fraction Fraction::add(Fraction other) {
        int num = numerator * other.getDenominator() + other.getNumerator() * denominator;
        int denom = denominator * other.getDenominator();
        Fraction result(num, denom);
        result.simplify();
        return result;
    }

    // Метод для вычитания дробей
    Fraction Fraction::subtract(Fraction other) {
        int num = numerator * other.getDenominator() - other.getNumerator() * denominator;
        int denom = denominator * other.getDenominator();
        Fraction result(num, denom);
        result.simplify();
        return result;
    }

    // Метод для умножения дробей
    Fraction Fraction::multiply(Fraction other) {
        int num = numerator * other.getNumerator();
        int denom = denominator * other.getDenominator();
        Fraction result(num, denom);
        result.simplify();
        return result;
    }

    // Метод для деления дробей
    Fraction Fraction::divide(Fraction other) {
        int num = numerator * other.getDenominator();
        int denom = denominator * other.getNumerator();
        Fraction result(num, denom);
        result.simplify();
        return result;
    }

    // Метод для сравнения дробей
    bool Fraction::equals(Fraction other) {
        simplify();
        other.simplify();
        return (numerator == other.getNumerator()) && (denominator == other.getDenominator());
    }

    // Метод для вычисления наибольшего общего делителя
    int Fraction::gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        else {
            return gcd(b, a % b);
        }
    }

    // Перегрузка оператора сложения
    Fraction Fraction::operator+(Fraction other) {
        return add(other);
    }

    // Перегрузка оператора вычитания
    Fraction Fraction::operator-(Fraction other) {
        return Fraction::subtract(other);
    }

    // Перегрузка оператора умножения
    Fraction Fraction::operator*(Fraction other) {
        return multiply(other);
    }

    // Перегрузка оператора деления
    Fraction Fraction::operator/(Fraction other) {
        return divide(other);
    }

    // Перегрузка оператора сравнения на равенство
    bool Fraction::operator==(Fraction other) {
        return equals(other);
    }

    // Запись состояния объекта в файл
    void Fraction::writeToFile(std::ofstream& file) {
        file << numerator << "/" << denominator << std::endl;
    }

    // Чтение состояния объекта из файла
    void Fraction::readFromFile(std::ifstream& file) {
        char slash;
        file >> numerator >> slash >> denominator;
    }
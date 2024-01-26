#include<iostream>
#include "Fraction.h"

int main() {
    setlocale(LC_ALL, "ru");
    // �������� ����� � ������������� � �����������
    Fraction fraction(3, 4);

    // ������������� ��������
    std::cout << "Numerator: " << fraction.getNumerator() << std::endl;
    std::cout << "Denominator: " << fraction.getDenominator() << std::endl;

    // ������������� ��������
    fraction.setNumerator(36);
    fraction.setDenominator(6);

    // ������������� �������
    Fraction other(1, 1);
    Fraction sum = fraction.add(other);
    std::cout << "�����: " << sum.getNumerator() << "/" << sum.getDenominator() << std::endl;

    Fraction sub = fraction.subtract(other);
    std::cout << "�������: " << sub.getNumerator() << "/" << sub.getDenominator() << std::endl;

    Fraction mul = fraction.multiply(other);
    std::cout << "������������: " << mul.getNumerator() << "/" << mul.getDenominator() << std::endl;

    Fraction div = fraction.divide(other);
    std::cout << "�������: " << div.getNumerator() << "/" << div.getDenominator() << std::endl;
}
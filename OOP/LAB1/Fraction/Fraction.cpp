#include "Fraction.h"

Fraction::Fraction() {
    numerator = 0;
    denominator = 0;
}

    // ����������� � �����������
Fraction::Fraction(int num, int denom) {
        numerator = num;
        denominator = denom;
    }

    // ������� � �������
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
        // �������� �������� �� ����
        if (denom == 0) {
            throw std::runtime_error("����������� �� ����� ���� ����� ����");
        }
        denominator = denom;
    }

    // ����� ��� ���������� �����
    void Fraction::simplify() {
        int divisor = gcd(numerator, denominator);
        numerator /= divisor;
        denominator /= divisor;
    }

    // ����� ��� �������� ������
    Fraction Fraction::add(Fraction other) {
        int num = numerator * other.getDenominator() + other.getNumerator() * denominator;
        int denom = denominator * other.getDenominator();
        Fraction result(num, denom);
        result.simplify();
        return result;
    }

    // ����� ��� ��������� ������
    Fraction Fraction::subtract(Fraction other) {
        int num = numerator * other.getDenominator() - other.getNumerator() * denominator;
        int denom = denominator * other.getDenominator();
        Fraction result(num, denom);
        result.simplify();
        return result;
    }

    // ����� ��� ��������� ������
    Fraction Fraction::multiply(Fraction other) {
        int num = numerator * other.getNumerator();
        int denom = denominator * other.getDenominator();
        Fraction result(num, denom);
        result.simplify();
        return result;
    }

    // ����� ��� ������� ������
    Fraction Fraction::divide(Fraction other) {
        int num = numerator * other.getDenominator();
        int denom = denominator * other.getNumerator();
        Fraction result(num, denom);
        result.simplify();
        return result;
    }

    // ����� ��� ��������� ������
    bool Fraction::equals(Fraction other) {
        simplify();
        other.simplify();
        return (numerator == other.getNumerator()) && (denominator == other.getDenominator());
    }

    // ����� ��� ���������� ����������� ������ ��������
    int Fraction::gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        else {
            return gcd(b, a % b);
        }
    }

    // ���������� ��������� ��������
    Fraction Fraction::operator+(Fraction other) {
        return add(other);
    }

    // ���������� ��������� ���������
    Fraction Fraction::operator-(Fraction other) {
        return Fraction::subtract(other);
    }

    // ���������� ��������� ���������
    Fraction Fraction::operator*(Fraction other) {
        return multiply(other);
    }

    // ���������� ��������� �������
    Fraction Fraction::operator/(Fraction other) {
        return divide(other);
    }

    // ���������� ��������� ��������� �� ���������
    bool Fraction::operator==(Fraction other) {
        return equals(other);
    }

    // ������ ��������� ������� � ����
    void Fraction::writeToFile(std::ofstream& file) {
        file << numerator << "/" << denominator << std::endl;
    }

    // ������ ��������� ������� �� �����
    void Fraction::readFromFile(std::ifstream& file) {
        char slash;
        file >> numerator >> slash >> denominator;
    }
#pragma once
#include<fstream>

class Fraction
{
private:
    int numerator;
    int denominator;

public:
    Fraction(int num, int denom);

    int getNumerator();
    int getDenominator();

    void setNumerator(int num);
    void setDenominator(int denom);

    void simplify();

    Fraction add(Fraction other);

    Fraction subtract(Fraction other);
    Fraction multiply(Fraction other);
    Fraction divide(Fraction other);

    bool equals(Fraction other);

    int gcd(int a, int b);

    Fraction operator+(Fraction other);
    Fraction operator-(Fraction other);
    Fraction operator*(Fraction other);
    Fraction operator/(Fraction other);

    bool operator==(Fraction other);

    void writeToFile(std::ofstream& file);
    void readFromFile(std::ifstream& file);
    Fraction();
};



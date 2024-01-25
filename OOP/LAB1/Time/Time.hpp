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
    // ����������� � �����������
    Time(int h, int m, int s);

    // ������� � �������
    int getHours() const;
    int getMinutes() const;
    int getSeconds() const;
    void setHours(int h);
    void setMinutes(int m);
    void setSeconds(int s);

    // �������� ������
    Time operator+(const Time& t) const;

    // ��������� ������
    Time operator-(const Time& t) const;

    // ���������� ������� � �������
    void addMinutes(int m);

    // ������� ������� � �������
    int toSeconds() const;

    // �������������� � ������ (� ������� HH:MM:SS)
    std::string toString() const;
};


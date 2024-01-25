#include "Time.hpp"
#include<iostream>
#include <iomanip>

int main() {
    setlocale(LC_ALL, "ru");
    // �������� ������� �������
    Time t1(10, 30, 45);
    std::cout << "��������� �����: " << t1.toString() << std::endl;

    // �������� ������
    Time t2(2, 15, 20);
    Time sum = t1 + t2;
    std::cout << "����� �������: " << sum.toString() << std::endl;

    // ���������� ������� � �������
    t1.addMinutes(25);
    std::cout << "����� ����� ���������� 25 �����: " << t1.toString() << std::endl;

    // ������� ������� � �������
    std::cout << "����� � ��������: " << t1.toSeconds() << std::endl;

    return 0;
}
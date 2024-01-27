#include<iostream>
#include<fstream>
#include<string>
#include "GeometricFigure.h"
int main() {
    setlocale(LC_ALL, "ru");

    // создание объекта
    GeometricFigure figure(4, 3.0, 4.0);

    // вызов основных методов
    std::cout << "Площадь: " << figure.calculateArea() << std::endl;
    std::cout << "Периметр: " << figure.calculatePerimeter() << std::endl;

    // динамическое создание объекта
    GeometricFigure* dynamicFigure = new GeometricFigure(2, 2.0, 2.0);

    // использование объекта
    std::cout << "Количество сторон у динамически созданного объекта: " << dynamicFigure->getSides() << std::endl;

    // массив из объектов
    GeometricFigure figuresArray[3] = { GeometricFigure(3, 1.0, 1.0), GeometricFigure(4, 6.0, 4.0), GeometricFigure(4, 2.0, 3.0) };

    // массив из указателей на объекты
    GeometricFigure* pointersArray[3];
    for (int i = 0; i < 3; i++) {
        pointersArray[i] = &figuresArray[i];
    }

    // вызов метода для одного элемента из массива
    std::cout << "Периметр первой фигуры из созданного массива: " << pointersArray[0]->calculatePerimeter() << std::endl;

    return 0;
}
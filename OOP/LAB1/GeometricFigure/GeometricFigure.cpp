#include <iostream>
#include <fstream>
#include "GeometricFigure.h"


GeometricFigure::GeometricFigure() {
	int sides;
	float x, y;
}
// конструктор с параметрами
GeometricFigure::GeometricFigure(int s, float xx, float yy){ 
	sides = s;
	x = xx;
	y = yy;
}


// геттеры
int GeometricFigure::getSides() const { return sides; }
float GeometricFigure::getX() const { return x; }
float GeometricFigure::getY() const { return y; }

// сеттеры
void GeometricFigure::setSides(int s) { sides = s; }
void GeometricFigure::setX(float xx) { x = xx; }
void GeometricFigure::setY(float yy) { y = yy; }

// методы для расчета площади и периметра
float GeometricFigure::calculateArea() const {
	return x * y;
}

float GeometricFigure::calculatePerimeter() const {
	return 2 * (x+y);
}

// операторы
bool GeometricFigure::operator==(const GeometricFigure& other) const {
	return (this->sides == other.sides && this->x == other.x && this->y == other.y);
}

// метод для записи в файл
void GeometricFigure::writeToFile(std::ofstream& file) const {
	file << sides << " " << x << " " << y << std::endl;
}

// метод для чтения из файла
void GeometricFigure::readFromFile(std::ifstream& file) {
	file >> sides >> x >> y;
}



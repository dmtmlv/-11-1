#include <iostream>
#include <fstream>
#include "GeometricFigure.h"


GeometricFigure::GeometricFigure() {
	int sides;
	float x, y;
}
// ����������� � �����������
GeometricFigure::GeometricFigure(int s, float xx, float yy){ 
	sides = s;
	x = xx;
	y = yy;
}


// �������
int GeometricFigure::getSides() const { return sides; }
float GeometricFigure::getX() const { return x; }
float GeometricFigure::getY() const { return y; }

// �������
void GeometricFigure::setSides(int s) { sides = s; }
void GeometricFigure::setX(float xx) { x = xx; }
void GeometricFigure::setY(float yy) { y = yy; }

// ������ ��� ������� ������� � ���������
float GeometricFigure::calculateArea() const {
	return x * y;
}

float GeometricFigure::calculatePerimeter() const {
	return 2 * (x+y);
}

// ���������
bool GeometricFigure::operator==(const GeometricFigure& other) const {
	return (this->sides == other.sides && this->x == other.x && this->y == other.y);
}

// ����� ��� ������ � ����
void GeometricFigure::writeToFile(std::ofstream& file) const {
	file << sides << " " << x << " " << y << std::endl;
}

// ����� ��� ������ �� �����
void GeometricFigure::readFromFile(std::ifstream& file) {
	file >> sides >> x >> y;
}



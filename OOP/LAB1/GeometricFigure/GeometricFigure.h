#pragma once
#include <iostream>
#include <fstream>
#include "GeometricFigure.h"


class GeometricFigure {
private:
    int sides;
    float x, y;

public:
    GeometricFigure(int s, float xx, float yy);

    int getSides() const;
    float getX() const;
    float getY() const;

    void setSides(int s);
    void setX(float xx);
    void setY(float yy);


    float calculateArea() const;
    float calculatePerimeter() const;

    bool operator==(const GeometricFigure& other) const;


    void writeToFile(std::ofstream& file) const;
    void readFromFile(std::ifstream& file);
    GeometricFigure();
};




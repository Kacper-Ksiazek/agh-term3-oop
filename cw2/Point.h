#pragma once

#include "iostream"

using namespace std;

struct Point {
    double mX;
    double mY;

    // 1. Settery
    void setX(double x);
    void setY(double y);
    void setPoint(double x, double y);

    // 2. Gettery
    double getX();
    double getY();

    // 3. Operatory
    friend ostream& operator << (ostream& os, const Point& point);
    friend istream& operator >> (istream& is, Point& point);

    // 4. Konstruktory
    Point();
    Point(double x, double y);

    // 5. Akcje
    void Turn(double angle);
    void Move(double x, double y);
};


#pragma once

#include "iostream"

using namespace std;

struct Point {
    double mX;
    double mY;

    // 1. Settery
    inline void setX(double x);
    inline void setY(double y);

    void setPoint(double x, double y);
    void setPoint(const Point &point);

    // 2. Gettery
    inline double getX() const;
    inline double getY() const;

    // 3. Operatory
    friend ostream& operator << (ostream& os, const Point& point);
    friend istream& operator >> (istream& is, Point& point);

    // 4. Konstruktory
    Point(const Point& point);
    Point(double x=0, double y=0);

    // 5. Akcje
    void Turn(double angle);
    void Move(double x, double y);
};


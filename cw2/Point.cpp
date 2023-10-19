#include "Point.h"
#include "iostream"
#include "cmath"

using namespace std;

// 1. Settery

void Point::setX(double x) {
    mX = x;
}

void Point::setY(double y) {
    mY = y;
}

void Point::setPoint(double x, double y) {
    mX = x;
    mY = y;
}

// 2. Gettery

double Point::getX() {
    return mX;
}

double Point::getY() {
    return mY;
}

// 3. Operatory

ostream& operator << (ostream& os, const Point& point) {
    os << "[" << point.mX << ", " << point.mY << "]";
    return os;
}

istream& operator >>(istream& is, Point& point) {
    cout<<"Podaj x: ";
    is >> point.mX;
    cout<<"Podaj y: ";
    is >> point.mY;

    return is;
}

// 4. Konstruktory

Point::Point() {
    mX = 0;
    mY = 0;
}

Point::Point(double x, double y) {
    mX = x;
    mY = y;
}

// 5. Akcje

void Point::Turn(double angleInRads) {
    double currentX= getX();
    double currentY= getY();

    double cosinus = cos(angleInRads);
    double sinus = sin(angleInRads);

    // https://www.obliczeniowo.com.pl/65
    setX(currentX * cosinus - currentY * sinus);
    setY(currentX * sinus + currentY * cosinus);
}

void Point::Move(double x, double y) {
    setX(getX() + x);
    setY(getY() + y);
}


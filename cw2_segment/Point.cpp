#include "Point.h"
#include "iostream"
#include "cmath"

using namespace std;

// 1. Settery

inline void Point::setX(double x) {
    mX = x;
}

inline void Point::setY(double y) {
    mY = y;
}

void Point::setPoint(double x, double y) {
    setX(x);
    setY(y);
}

inline void Point::setPoint(const Point &p) {
    setX(p.mX);
    setY(p.mY);
}

// 2. Gettery

inline double Point::getX() const {
    return mX;
}

inline double Point::getY() const {
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

Point::Point(const Point &point) {
    mX = point.mX;
    mY = point.mY;
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



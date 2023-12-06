#include "ThreeNum.h"

void static ensureGreaterThanZero(double x){
    if(x < 0){
        cout<< "Wartosc musi byc wieksza lub rowna od zero! Otrzymano: "<<x<< endl;
        exit(1);
    }
}

void static ensureGreaterThanZero(double x1, double x2, double x3){
    if(x1 < 0){
        cout<< "Wartosc x1 musi byc wieksza lub rowna od zero! Otrzymano: "<<x1<< endl;
        exit(1);
    }
    if(x2 < 0){
        cout<< "Wartosc x2 musi byc wieksza lub rowna od zero! Otrzymano: "<<x2<< endl;
        exit(1);
    }
    if(x3 < 0){
        cout<< "Wartosc x3 musi byc wieksza lub rowna od zero! Otrzymano: "<<x3<< endl;
        exit(1);
    }
}



ThreeNum::ThreeNum(double x1, double x2, double x3) {
    // Validation is done in setAll
    setAll(x1, x2, x3);
}

ThreeNum::ThreeNum(const ThreeNum &ThreeNumInstanceToCopy) {
    // Validation is done in setAll
    setAll(ThreeNumInstanceToCopy.x1, ThreeNumInstanceToCopy.x2, ThreeNumInstanceToCopy.x3);
}

ThreeNum &ThreeNum::operator=(const ThreeNum &ThreeNumInstanceToCopy) {
    // Validation is done in setAll
    setAll(ThreeNumInstanceToCopy.x1, ThreeNumInstanceToCopy.x2, ThreeNumInstanceToCopy.x3);

    return *this;
}

double ThreeNum::getX1() const {
    return x1;
}

double ThreeNum::getX2() const {
    return x2;
}

double ThreeNum::getX3() const {
    return x3;
}

void ThreeNum::setX1(double x1) {
    ensureGreaterThanZero(x1);

    this->x1 = x1;
}

void ThreeNum::setX2(double x2) {
    ensureGreaterThanZero(x2);

    this->x2 = x2;
}

void ThreeNum::setX3(double x3) {
    ensureGreaterThanZero(x3);

    this->x3 = x3;
}

void ThreeNum::setAll(double x1, double x2, double x3) {
    ensureGreaterThanZero(x1, x2, x3);

    this->x1 = x1;
    this->x2 = x2;
    this->x3 = x3;
}

ThreeNum &ThreeNum::operator+=(const ThreeNum &a) {
    this->x1 += a.getX1();
    this->x2 += a.getX2();
    this->x3 += a.getX3();

    return *this;
}

ThreeNum &ThreeNum::operator+=(const double a) {
    ensureGreaterThanZero(x1 + a, x2 + a, x3 + a);

    this->x1 += a;
    this->x2 += a;
    this->x3 += a;

    return *this;
}

ThreeNum &ThreeNum::operator*=(const ThreeNum &a) {
    this->x1 *= a.getX1();
    this->x2 *= a.getX2();
    this->x3 *= a.getX3();

    return *this;
}

ThreeNum &ThreeNum::operator*=(const double a) {
    ensureGreaterThanZero(a);

    this->x1 *= a;
    this->x2 *= a;
    this->x3 *= a;

    return *this;
}

double ThreeNum::Ave() const {
    return 3 / ((1.0 / getX1()) + (1.0 / getX2()) + (1.0 / getX3()));
}

ThreeNum operator+(const ThreeNum &a, const ThreeNum &b) {
    return ThreeNum(
            a.getX1() + b.getX1(),
            a.getX2() + b.getX2(),
            a.getX3() + b.getX3()
            );
}

ThreeNum operator*(const ThreeNum &a, const ThreeNum &b) {
    return ThreeNum(
            a.getX1() * b.getX1(),
            a.getX2() * b.getX2(),
            a.getX3() * b.getX3()
            );
}

ThreeNum operator*(const ThreeNum &a, const double b) {
    return ThreeNum(
            a.getX1() * b,
            a.getX2() * b,
            a.getX3() * b
            );
}

ostream &operator<<(ostream &os, const ThreeNum &ThreeNumInstance) {
    os<< "[ "<< ThreeNumInstance.getX1() << ", " << ThreeNumInstance.getX2() << ", " << ThreeNumInstance.getX3() << " ]";
    return os;
}

istream &operator>>(istream &is, ThreeNum &ThreeNumInstance) {
    cout<< "Podaj x1: ";
    is>> ThreeNumInstance.x1;
    ensureGreaterThanZero(ThreeNumInstance.getX1());

    cout<< "Podaj x2: ";
    is>> ThreeNumInstance.x2;
    ensureGreaterThanZero(ThreeNumInstance.getX2());

    cout<< "Podaj x3: ";
    is>> ThreeNumInstance.x3;
    ensureGreaterThanZero(ThreeNumInstance.getX3());

    return is;
}



#pragma once

#include <iostream>
#include <cmath>

using namespace std;

class ThreeNum {
private:
    double x1;
    double x2;
    double x3;
public:
    // Konsruktor z parametrami domyślnymi
    ThreeNum(double x1 = 0, double x2 = 0, double x3 = 0);

    // Konstruktor kopiujący
    ThreeNum(const ThreeNum &ThreeNumInstanceToCopy);

    // Operator podstawiania
    ThreeNum &operator=(const ThreeNum &ThreeNumInstanceToCopy);

    // Gettery
    inline double getX1() const;

    inline double getX2() const;

    inline double getX3() const;

    // Settery
    inline void setX1(double x1);

    inline void setX2(double x2);

    inline void setX3(double x3);

    inline void setAll(double x1, double x2, double x3);

    // Operator dodawania liczb
    friend ThreeNum operator+(const ThreeNum &a, const ThreeNum &b);

    // Operator mnozenia liczb
    friend ThreeNum operator*(const ThreeNum &a, const ThreeNum &b);

    // Operator mnozenia przez skalar
    friend ThreeNum operator*(const ThreeNum &a, const double b);

    // Operator zwiekszenia przez dodawania
    ThreeNum &operator+=(const ThreeNum &a);

    ThreeNum &operator+=(const double a);

    // Operator zwiekszenia przez mnozenie
    ThreeNum &operator*=(const ThreeNum &a);

    ThreeNum &operator*=(const double a);

    // Metoda Ave
    double Ave() const;

    // Operatory strumieniowe
    friend ostream &operator<<(ostream &os, const ThreeNum &ThreeNumInstance);

    friend istream &operator>>(istream &is, ThreeNum &ThreeNumInstance);
};



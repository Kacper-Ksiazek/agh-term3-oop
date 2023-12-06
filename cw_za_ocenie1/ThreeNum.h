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
    ThreeNum& operator=(const ThreeNum &ThreeNumInstanceToCopy);
};



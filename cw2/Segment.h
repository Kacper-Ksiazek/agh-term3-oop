#pragma once
#include "Point.h"
#include "iostream"
#include "cmath"

using namespace std;

#define PI 3.14159265358979

class Segment {
    private:
        Point mPt1; // Start
        Point mPt2; // End

        // 6. Pomocnicze metody
        const Point GetMiddlePoint();

        static double Mean(double a, double b);
        static double ConvertToRadian(double angle);

    public:
        // 1. Gettery
        const Point& getPt1() const;
        const Point& getPt2() const;

        // 2. Settery
        void setPt1(Point pt1);
        void setPt2(Point pt2);
        void setSeg(Point pt1, Point pt2);

       // 3. Operatory
       friend ostream& operator << (ostream& os, const Segment& segment);
       friend istream& operator >> (istream& is, Segment& segment);

       // 4. Konstruktory
       Segment();
       Segment(double x1, double y1, double x2, double y2);

       // 5. Akcje
       void Move(double x, double y);
       void Rotate(double angle);
};

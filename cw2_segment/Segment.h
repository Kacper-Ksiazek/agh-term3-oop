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
        inline const Point& getPt1() const;
        inline const Point& getPt2() const;

        // 2. Settery
        inline void setPt1(Point pt1);
        inline void setPt2(Point pt2);
        inline void setSeg(Point pt1, Point pt2);

       // 3. Operatory
       friend ostream& operator << (ostream& os, const Segment& segment);
       friend istream& operator >> (istream& is, Segment& segment);

       // 4. Konstruktory
       Segment(Point pt1, Point pt2);
       Segment(double x1=0, double y1=0, double x2=0, double y2=0);

       // 5. Akcje
       void Move(double x, double y);
       void Rotate(double angle);
};

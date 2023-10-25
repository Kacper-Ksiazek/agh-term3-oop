#include "Segment.h"
#include "Point.h"

// 1. Gettery

inline const Point& Segment::getPt1() const {
    return mPt1;
}
inline const Point& Segment::getPt2() const {
    return mPt2;
}

// 2. Settery

inline void Segment::setPt1(const Point pt1) {
    mPt1 = pt1;
}

inline void Segment::setPt2(const Point pt2) {
    mPt2 = pt2;
}

inline void Segment::setSeg(const Point pt1, const Point pt2) {
    mPt1 = pt1;
    mPt2 = pt2;
}

// 3. Operatory

ostream& operator << (ostream& os, const Segment& segment) {
    os << segment.getPt1() << "--"<< segment.getPt2();
    return os;
}

istream& operator >> (istream& is, Segment& segment) {
    cout<<"\nPodaj x1: ";
    is >> segment.mPt1.mX;
    cout<<"Podaj y1: ";
    is >> segment.mPt1.mY;
    cout<<"Podaj x2: ";
    is >> segment.mPt2.mX;
    cout<<"Podaj y2: ";
    is >> segment.mPt2.mY;
    cout<<endl;

    return is;
}

// 4. Konstruktory

Segment::Segment(const Point pt1, const Point pt2) {
    setPt1(pt1);
    setPt2(pt2);
}

Segment::Segment(double x1, double y1, double x2, double y2) {
    mPt1.setPoint(x1, y1);
    mPt2.setPoint(x2, y2);
}

// 5. Akcje

void Segment::Move(double x, double y) {
    mPt1.Move(x, y);
    mPt2.Move(x, y);
}

void Segment::Rotate(double angle) {
    // 1. Obliczamy środek odcinka
    Point middlePoint = GetMiddlePoint();
    // 2. Przesuwamy odcinek tak, aby środek był w punkcie (0,0)
    mPt1.Move(-middlePoint.mX, -middlePoint.mY);
    // 3. Obracamy odcinek
    double angleInRad = ConvertToRadian(angle);
    mPt1.Turn(angleInRad);
    mPt2.Turn(angleInRad);
    // 4. Przesuwamy odcinek tak, aby środek był w punkcie (x,y)
    mPt1.Move(middlePoint.mX, middlePoint.mY);
    mPt2.Move(middlePoint.mX, middlePoint.mY);
}


// 6. Pomocnicze metody

double Segment::Mean(double a, double b) {
    return (a + b) / 2;
}

double Segment::ConvertToRadian(double angle) {
    return angle * PI / 180;
}

const Point Segment::GetMiddlePoint() {
    double x = Mean(mPt1.mX, mPt2.mX);
    double y = Mean(mPt1.mY, mPt2.mY);

    Point middlePoint(x, y);
    return middlePoint;
}
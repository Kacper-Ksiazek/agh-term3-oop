#include <iostream>
#include "Point.h"
#include "Segment.h"

using namespace std;

int main() {
//    Segment seg;
//    cout << "Podaj wsp odcinka x1 y1 x2 y2: ";
//    cin >> seg;

    Segment seg(Point(1,5), Point(1,5));
    cout << "Odcinek: " << seg << endl;

    cout << "Podaj kat obrotu w stopniach: " ;
    int alpha = 0;
    cin >> alpha;

    cout << "Obrot odcinka: " << seg << " o kat " << alpha << "stopni";
    seg.Rotate( alpha );
    cout << "= " << seg << endl;

    Segment seg2 = seg;

    cout << endl<<seg2 << " = " << seg;


//    Point a(5,10);
//    cout<<a;
//
//    a.Turn(0.785398163);
//
//    cout<<a;


    return 0;
}

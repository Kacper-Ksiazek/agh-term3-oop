#include <iostream>

using namespace std;

#include "Vector.h"
#include "Matrix.h"

int main() {
//    Vector v1;
//    Vector v2( 4, 1 );
//    Vector v3( 4, 2 );
//    Vector v4( v2 );
//    Vector v5 = v4;
//
//    cout << "v5 = " << v5 << endl;
//
//    cout << "v2+v3 = " << v2+v3 << endl;
//    cout << "3+v3 = " << 3+v3 << endl;

    // ---
    // Testowanie z cwiczen z wektorami

//    Vector v1(2);
//    Vector v2( 4, 2 );
//    Vector v3( 4, 2 );
//    Vector v4(v2);
//
//    cout << "Podaj dwie wspolrzedne wektora v1: ";
//    cin >> v1;
//
//    cout << "v1 = " << v1 << endl;
//    cout << "v2 = " << v2 << endl;
//    cout << "v3 = " << v3 << endl;
//    cout << "v4 = " << v4 << endl;
//
//    cout << "3+v3 = " << 3+v3 << endl;
//    cout << "v2+v3 = " << v2+v3 << endl;
//    cout << "iloczyn skalarny v2*v3 = " << v2*v3 << endl;
//    cout << "-2 * v4" << -2 * v4 << endl;
//
//    double *p = (double*)v3;
//    cout << endl << "rzutowanie na p - p[1] = " <<  *(p+1) << endl<<endl;
//
//    Vector v = v2+ v3;
//    cout << "v = v2 + v3 = " << v << endl;
//
//    v3[0] += 3;
//    cout << "v3[0] += 3; v3 = " << v3 << endl;
//
//    v3[1]=4;
//    cout << "v3[1] = 4; v3 = " << v3 << endl;
//
//    v3[1] = v3[2] + v3[0];
//
//    cout << "-v1" << -v1 << endl;
//    cout << "v3 - 1" << v3-1 << endl;
//    cout << "v3 - v2 = " << v3-v2 << endl;
//
//    if (v2 != v3)
//        cout << " v2 != v3 " << endl;
//    else
//        cout << " v2 == v3 " << endl;
//

    // ---
    // Testowanie z cwiczen z macierzami
    Matrix m1;
    Matrix m2(3, 3, 1);
    Matrix m3(3, 3, 2);

    cout << "m1=\n" << m1 << endl;
    cout << "m2=\n" << m2 << endl;
    cout << "m3=\n" << m3 << endl << endl;
//
    Vector *pVec = (Vector *) m3;
    cout << "pVec[1] = " << pVec[1] << "\n\n";

    m1 = m2;
    cout << "m1=m2=\n" << m1 << endl;

    cout << "m1==m2 : " << ((m1 == m2) ? 1 : 0) << endl;

    m3[0][1] = -2;
    m3[1][1] = -1;
    m3[2][1] = -2;
    cout << "m3=\n" << m3 << endl;

    Vector w5(3, 4);
    cout << "m1*w5=\n" << m1 * w5 << endl;

    m1 = m2 * m3;
    cout << "m1 = m2 * m3 = \n" << m1 << endl;

    return 0;
}

#include "pch.h"
#include "testDll.h"

#include <iostream>

#include "DateTime.h"

using namespace std;

int main() {
    Date d(9,12,2023);
    cout << "d= " << d << endl;

    Time t(22,10,24);
    cout << "t= " << t << endl;

    DateTime dt(d,t);
    cout << "Dt = " << dt << endl;

    DateTime dt2 = dt; // Test operatora podstawiania
    cout << "Dt2 = " << dt2 << endl;

    DateTime dt3;
    cin >> dt3;
    cout << "Dt3 = " << dt3 << endl;

    return 0;
}

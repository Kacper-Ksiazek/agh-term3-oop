#include <iostream>
#include "ThreeNum.h"

using namespace std;

int main() {
    ThreeNum a(1, 2, 3);

    ThreeNum b;
    cin >> b;

    cout << endl << "-------------------" << endl;

    ThreeNum wynikSumy = a + b;
    cout << "Suma a i b: ";
    cout << wynikSumy << endl;

    cout << "Iloczyn a i b: ";
    cout << a * b << endl;

    cout << "Iloczyn b i 2: ";
    cout << b * 2 << endl;

    cout << "Srednia harmoniczna wyniku sumy: ";
    cout << wynikSumy.Ave() << endl;


    return 0;
}

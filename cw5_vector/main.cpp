#include <iostream>
#include "Vector.h"

using namespace std;

int main() {
    Vector v1;
    Vector v2(3, 1);
    Vector v3(4, 2);
    Vector v4(v2);
    Vector v5 = v4;

    cout << "v1: " << v1 << endl;

    return 0;
}

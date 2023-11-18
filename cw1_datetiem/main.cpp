#include <iostream>

#include "DateTime.h"
// #include "time_proc.h"
// #include "time_oop.h"

#include "date.h"

using namespace std;

int main() {
    // 1. Procedural approach

//    Time t1 = {};
//
//    setTime(&t1, 10,21,34);
//    printTime(&t1);
//
//    cout<<endl;
//
//    Time t2 = {};
//    cout << "Enter time in hh:mm:ss format" << endl;
//    readTime(&t2);
//    printTime(&t2);

    // 2. Object-Oriented approach
//    class Time t1(10,21,34);
//    t1.printTime();
//
//    class Time t2;
//    t2.printTime();

    // 3. Task
//    class Date uro(11,8,2002);
//
//    uro.printDate();

    DateTime dt;
    dt.setDate(23, 10, 2023);
    cout << "dt = " << dt << endl;

    DateTime dt2(dt);
    cout << "Podaj date i czas dd/mm/yyyy  hh:mm:ss "<<endl;
    cout<<"Podawanie czasu dt2\n";
    cin >> dt2;
    cout << "dt2 = " << dt2 << endl;

    dt = dt2;
    cout << "dt = " << dt <<endl;

    return 0;
}

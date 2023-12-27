#pragma once
#include "iostream"

using namespace std;

class TESTDLL_API Date {
public:
    Date(int day = 1, int month = 1, int year = 1990);
    Date(const Date& date);

    // Getters
    inline int getDay() const;
    inline int getMonth() const;
    inline int getYear() const;

    // Setters
    inline void setDay(int day);
    inline void setMonth(int month);
    inline void setYear(int year);
    inline void setDate(int day, int month, int year);

    // Other
    void printDate();

    friend TESTDLL_API ostream& operator << (ostream& os, const Date& date);
    friend TESTDLL_API istream& operator >> (istream& is, Date& date);

private:
    int mDay;
    int mMonth;
    int mYear;
};
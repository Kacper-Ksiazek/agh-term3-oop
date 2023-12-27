#include "pch.h"
#include "testDll.h"

#include "Date.h"
#include <iostream>
#include <iomanip>

#include "CUtils.h"

using namespace std;


Date::Date(const Date& date) {
    setDate(date.getDay(), date.getMonth(), date.getYear());
}

Date::Date(int day, int month, int year) {
    setDate(day, month, year);
}

void Date::setDay(int day) {
    if (day < 1 || day > 31) {
        printf("Invalid day value: %d\n", day);
        return;
    }
    mDay = day;
}

void Date::setMonth(int month) {
    if (month < 1 || month > 12) {
        printf("Invalid month value: %d\n", month);
        return;
    }
    mMonth = month;
}

void Date::setYear(int year) {
    if (year < 0 || year > 9999) {
        printf("Invalid year value: %d\n", year);
        return;
    }
    mYear = year;
}

void Date::setDate(int day, int month, int year) {
    setDay(day);
    setMonth(month);
    setYear(year);
}

int Date::getDay() const {
    return mDay;
}

int Date::getMonth() const {
    return mMonth;
}

int Date::getYear() const {
    return mYear;
}

void Date::printDate() {
    printf("%d.%d.%d\n", mDay, mMonth, mYear);
}

ostream& operator<<(ostream& os, const Date& date) {
    os << setfill('0')
        << setw(2) << date.getDay() << ":"
        << setw(2) << date.getMonth() << ":"
        << setw(4) << date.getYear();
    return os;
}

istream& operator>>(istream& is, Date& date) {
    unsigned short* p = Utils::readDateFromUser("Podaj date w formacie dd/mm/yyyy", '/', true);
    date.setDate(p[0], p[1], p[2]);

    return is;
}
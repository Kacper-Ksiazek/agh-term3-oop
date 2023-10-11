#include "date.h"

Date::Date() {
    setDate(1,1,1990);
}

Date::Date(int day, int month, int year) {
    setDate(day, month, year);
}

void Date::setDay(int day) {
    if(day < 1 || day > 31) {
        printf("Invalid day value: %d\n", day);
        return;
    }
    mDay = day;
}

void Date::setMonth(int month) {
    if(month < 1 || month > 12) {
        printf("Invalid month value: %d\n", month);
        return;
    }
    mMonth = month;
}

void Date::setYear(int year) {
    if(year < 0 || year > 9999) {
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

int Date::getYear( ) const {
    return mYear;
}

void Date::printDate() {
    printf("%d.%d.%d\n", mDay, mMonth, mYear);
}

ostream& operator << (ostream& os, const Date& date) {
    os << date.getDay() << "." << date.getMonth() << "." << date.getYear();
    return os;
}

istream& operator >> (istream& is, Date& date) {
    int day, month, year;

    std::cout << "Enter day: ";
    is >> day;
    std::cout << "Enter month: ";
    is >> month;
    std::cout << "Enter year: ";
    is >> year;

    date.setDate(day, month, year);

    return is;
}
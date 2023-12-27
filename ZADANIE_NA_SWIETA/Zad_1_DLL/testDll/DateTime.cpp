#include "pch.h"
#include "testDll.h"

#include "DateTime.h"
#include "Date.h"
#include "CTime.h"

DateTime::DateTime(int hh, int mm, int ss, int dd, int MM, int YYYY) :
        Date(dd, MM, YYYY),
        Time(hh, mm, ss) {}

DateTime::DateTime(const DateTime &dateTime): Date(dateTime), Time(dateTime) {}

DateTime::DateTime(const Date &date, const Time &time): Date(date), Time(time) {}


DateTime &DateTime::operator=(const DateTime &dateTime) {
    if (this == &dateTime) return *this; // Zapobieganie samokopiowaniu

    *this = dateTime;
}

void DateTime::setDataTime(int hh, int mm, int ss, int dd, int MM, int YYYY) {
    Date::setDate(dd, MM, YYYY);
    Time::setTime(hh, mm, ss);
}

istream &operator>>(istream &is, DateTime &dateTime) {
    is >> (Date &) dateTime;
    is >> (Time &) dateTime;
    return is;
}

ostream &operator<<(ostream &os, const DateTime &dateTime) {
    os << (const Date &) dateTime << " " << (const Time &) dateTime;
    return os;
}



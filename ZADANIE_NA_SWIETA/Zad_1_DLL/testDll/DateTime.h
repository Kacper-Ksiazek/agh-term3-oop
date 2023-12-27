#pragma once

#include "Date.h"
#include "CTime.h"
#include "CTime.h"

#include "iostream"

using namespace std;

class TESTDLL_API DateTime : public Date, public Time {
    public:
       DateTime(int hh=0, int mm=0, int ss=0, int dd=1, int MM=1, int YYYY=1990);
       DateTime(const DateTime& dateTime);
       DateTime(const Date& date, const Time& time);

       DateTime& operator = (const DateTime& dateTime);

       void setDataTime(int hh, int mm, int ss, int dd, int MM, int YYYY) ;

       friend TESTDLL_API istream& operator >> (istream& is, DateTime& dateTime);
       friend TESTDLL_API ostream& operator << (ostream& os, const DateTime& dateTime);
};



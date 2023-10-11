#pragma once
#include "iostream"

using namespace std;

class Date {
    public:
        Date();
        Date(int day, int month, int year);

        // Getters
        int getDay() const;
        int getMonth() const;
        int getYear() const;

        // Setters
        void setDay(int day);
        void setMonth(int month);
        void setYear(int year);
        void setDate(int day, int month, int year);

        // Other
        void printDate();

        friend ostream& operator << (ostream& os, const Date& date);
        friend istream& operator >> (istream& is, Date& date);

    private:
        int mDay;
        int mMonth;
        int mYear;
};

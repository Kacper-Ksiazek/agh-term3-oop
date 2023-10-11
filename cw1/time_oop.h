#pragma once
#include "iostream"

using namespace std;

class Time {
    public:
        Time();
        Time(int hour, int minute, int second);

    public:
    // Getters
    void setHour( int hour);
    void setMinute( int minute);
    void setSecond( int second);
    void setTime( int hour, int minute, int second);

    // Getter
    int getHour() const;
    int getMinute() const;
    int getSecond() const;

    // Other
    void printTime();
    void readTime();

    friend ostream& operator << (ostream& os, const Time& time);
    friend istream& operator >> (istream& is, Time& time);

    private:
    int mHour{}; // m- member
    int mMinute{};
    int mSecond{};
};



#pragma once
#include "iostream"

using namespace std;

class TESTDLL_API Time {
    public:
        Time(const Time& time);
        Time(int hour=0, int minute=0, int second=0);

    public:
        // Getters
        inline void setHour( int hour);
        inline void setMinute( int minute);
        inline void setSecond( int second);
        void setTime( int hour, int minute, int second);

        // Getter
        inline int getHour() const;
        inline int getMinute() const;
        inline int getSecond() const;

        // Other
        void printTime();
        void readTime();

        friend TESTDLL_API ostream& operator << (ostream& os, const Time& time);
        friend TESTDLL_API istream& operator >> (istream& is, Time& time);

    private:
        int mHour{}; // m- member
        int mMinute{};
        int mSecond{};
};



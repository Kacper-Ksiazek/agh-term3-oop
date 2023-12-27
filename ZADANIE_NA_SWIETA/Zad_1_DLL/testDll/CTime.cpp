#include "pch.h"
#include "testDll.h"

#include <iostream>
#include <iomanip>
#include "CTime.h"

#include "CUtils.h"

Time::Time(const Time &time) {
    *this = time;
}

Time::Time(int hour, int minute, int second) {
    setTime(hour, minute, second);
}

ostream &operator<<(ostream &os, const Time &time) {
    os << std::setfill('0') << std::setw(2) << time.getHour() << ":"
       << std::setw(2) << time.getMinute() << ":" << std::setw(2) << time.getSecond();
    return os;
}

istream &operator>>(istream &is, Time &time) {
    unsigned short *dataFromUser = Utils::readDateFromUser("Podaj czas w hh:mm:ss formacie", ':', true);

    if ( dataFromUser == nullptr ) throw runtime_error("Invalid time format!");

    int hour, minute, second;
    hour = dataFromUser[0], minute = dataFromUser[1], second = dataFromUser[2];

    time.setTime(hour, minute, second);

    return is;
}

inline void Time::setHour(int hour) {
    if (hour < 0 || hour > 23) {
        printf("Invalid hour value: %d\n", hour);
        return;
    }
    mHour = hour;
}

inline void Time::setMinute(int minute) {
    if (minute < 0 || minute > 59) {
        printf("Invalid minute value: %d\n", minute);
        return;
    }
    mMinute = minute;
}

inline void Time::setSecond(int second) {
    if (second < 0 || second > 59) {
        printf("Invalid second value: %d\n", second);
        return;
    }
    mSecond = second;
}

void Time::setTime(int hour, int minute, int second) {
    // Validate received parameters
    if (hour < 0 || hour > 23) {
        printf("Invalid hour value: %d\n", hour);
        return;
    }
    if (minute < 0 || minute > 59) {
        printf("Invalid minute value: %d\n", minute);
        return;
    }
    if (second < 0 || second > 59) {
        printf("Invalid second value: %d\n", second);
        return;
    }

    setHour(hour);
    setMinute(minute);
    setSecond(second);
}

inline int Time::getHour() const {
    return mHour;
}

inline int Time::getMinute() const {
    return mMinute;
}

inline int Time::getSecond() const {
    return mSecond;
}

void Time::printTime() {
    printf("%02d:%02d:%02d\n", getHour(), getMinute(), getSecond());
}

void Time::readTime() {
    int hour, minute, second;

    std::cout << "Enter hour: ";
    std::cin >> hour;
    std::cout << "Enter minute: ";
    std::cin >> minute;
    std::cout << "Enter second: ";
    std::cin >> second;

    setTime(hour, minute, second);
}


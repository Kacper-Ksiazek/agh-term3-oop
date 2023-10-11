#include "time_oop.h"

#include "stdio.h"
#include "iostream"

Time::Time(){
    setTime(0,0,0);
}
Time::Time(int hour, int minute, int second){
    setTime(hour, minute, second);
}

ostream& operator << (ostream& os, const Time& time){
    os << time.getHour()<< ":" << time.getMinute()<< ":" << time.getSecond();
    return os;
}

istream& operator >> (istream& is, Time& time){
    int hour, minute, second;

    std::cout << "Enter hour: ";
    is >> hour;
    std::cout << "Enter minute: ";
    is >> minute;
    std::cout << "Enter second: ";
    is >> second;

    time.setTime(hour, minute, second);

    return is;
}

void Time::setHour( int hour){
    if(hour < 0 || hour > 23) {
        printf("Invalid hour value: %d\n", hour);
        return;
    }
    mHour= hour;
}

void Time::setMinute( int minute){
    if(minute < 0 || minute > 59) {
        printf("Invalid minute value: %d\n", minute);
        return;
    }
    mMinute= minute;
}

void Time::setSecond( int second){
    if(second < 0 || second > 59) {
        printf("Invalid second value: %d\n", second);
        return;
    }
    mSecond= second;
}

void Time::setTime( int hour, int minute, int second) {
    // Validate received parameters
    if(hour < 0 || hour > 23) {
        printf("Invalid hour value: %d\n", hour);
        return;
    }
    if(minute < 0 || minute > 59) {
        printf("Invalid minute value: %d\n", minute);
        return;
    }
    if(second < 0 || second > 59) {
        printf("Invalid second value: %d\n", second);
        return;
    }

    setHour(hour);
    setMinute(minute);
    setSecond(second);
}

int Time::getHour() const{
    return mHour;
}

int Time::getMinute() const{
    return mMinute;
}

int Time::getSecond() const{
    return mSecond;
}

void Time::printTime(){
    printf("%02d:%02d:%02d\n", getHour(), getMinute(), getSecond());
}

void Time::readTime(){
    int hour, minute, second;

    std::cout << "Enter hour: ";
    std::cin >> hour;
    std::cout << "Enter minute: ";
    std::cin >> minute;
    std::cout << "Enter second: ";
    std::cin >> second;

    setTime(hour, minute, second);
}

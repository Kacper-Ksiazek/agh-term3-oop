#include "stdio.h"
#include "iostream"
#include "time_proc.h"

void setHour(Time *time, int hour){
    if(hour < 0 || hour > 23) {
        printf("Invalid hour value: %d\n", hour);
        return;
    }
    time->mHour= hour;
}

void setMinute(Time *time, int minute){
    if(minute < 0 || minute > 59) {
        printf("Invalid minute value: %d\n", minute);
        return;
    }
    time->mMinute= minute;
}

void setSecond(Time *time, int second){
    if(second < 0 || second > 59) {
        printf("Invalid second value: %d\n", second);
        return;
    }
    time->mSecond= second;
}

void setTime(Time *time, int hour, int minute, int second) {
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

    setHour(time, hour);
    setMinute(time, minute);
    setSecond(time, second);
}

int getHour(Time *time){
    return time->mHour;
}

int getMinute(Time *time){
    return time->mMinute;
}

int getSecond(Time *time){
    return time->mSecond;
}

void printTime(Time *time){
    printf("%02d:%02d:%02d\n", getHour(time), getMinute(time), getSecond(time));
}

void readTime(Time *time){
    int hour, minute, second;

    std::cout << "Enter hour: ";
    std::cin >> hour;
    std::cout << "Enter minute: ";
    std::cin >> minute;
    std::cout << "Enter second: ";
    std::cin >> second;

    setTime(time, hour, minute, second);
}
#pragma once

typedef struct {
    int mHour; // m- member
    int mMinute;
    int mSecond;
} Time;

// Setters

void setHour( Time *time, int hour );
void setMinute( Time *time, int minute );
void setSecond( Time *time, int second );

void setTime( Time *time, int hour, int minute, int second );

// Getters

int getHour( Time *time );
int getMinute( Time *time );
int getSecond( Time *time );

// Other

void printTime( Time *time );

void readTime( Time *time );
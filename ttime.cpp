#include<ctime>
//#include<iostream>
#include<stdio.h>

#include"ttime.h"

using namespace std;

TTime::TTime()
{
    TTime::setCurrentTime();
}

TTime::TTime(int hour, int minute)
{
    TTime::setTime(hour, minute);
}

TTime::~TTime()
{
    printf( "Object TTime is freed\n" );
}

void TTime::setTime(int hour, int minute)
{
    if ( hour >= 0 and hour <=23 and minute >= 0 and minute <=59 )
    {
        TTime::hour = hour;
        TTime::minute = minute;
    }
    else
        TTime::setCurrentTime();
}

void TTime::setCurrentTime()
{
    // get current date from operator system
    time_t now = time(0);
    tm *ltm = localtime(&now);

    TTime::hour = ltm->tm_hour;
    TTime::minute = ltm->tm_min;
}

int TTime::getHour()
{
    return TTime::hour;
}

int TTime::getMinute()
{
    return TTime::minute;
}

void TTime::print()
{
    printf( "%2i:%2i",TTime::hour, TTime::minute);
}

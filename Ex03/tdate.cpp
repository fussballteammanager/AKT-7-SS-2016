#include <iostream>
#include <iomanip>
#include <ctime>
#include "tdate.h"

using namespace std;


TDate::TDate()
{
    TDate::setCurrentDate();
}

TDate::TDate(short day, short month, short year)
{
    TDate::setDate(day, month, year);
}

void TDate::setDate(short day, short month, short year)
{
    if ( day > 0 and day <=31 and month > 0 and month <=12 and
        year > 1900 and year < 3000 )
    {
        TDate::day = day;
        TDate::month = month;
        TDate::year = year;
    }
    else
        TDate::setCurrentDate();
}

void TDate::setCurrentDate()
{
    // get current date from operator system
    time_t now = time(0);
    tm *ltm = localtime(&now);

    TDate::day = ltm->tm_mday;
    TDate::month = 1 + ltm->tm_mon;
    TDate::year = 1900 + ltm->tm_year;
}

short TDate::getDay()
{
    return TDate::day;
}

short TDate::getMonth()
{
    return TDate::month;
}

short TDate::getYear()
{
    return TDate::year;
}

void TDate::print()
{
    cout << setw(2) << setfill('0') << this->day << "."
        << setw(2) << setfill('0') <<  this->month << "." << this->year;
}

int TDate::load(string line)
{
    cout << "found Date Tag: " << line << endl;
    return 0;
}

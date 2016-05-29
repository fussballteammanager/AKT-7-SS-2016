#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <ctime>
#include "tdate.h"
#include "ttools.h"

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
    cout << setw(2) << setfill('0') << this->day << "." << setw(2) << setfill('0') <<  this->month << "." << this->year;
}

int TDate::load(std::ifstream &ifs)
{
    string line;
    while(ifs.good())
    {
        line = TTools::ReadUnspaced(ifs);
        if (line == "</Birthday>")
        {
            return 1;
        }else if(TTools::strcontain(line,"<Day>"))
        {
            std::string tag1 = "<Day>",tag2 = "</Day>";
            line = TTools::tagremove(line, tag1);
            line = TTools::tagremove(line, tag2);
            this->day = atoi(line.c_str());
        }else if(TTools::strcontain(line,"<Month>"))
        {
            std::string tag1 = "<Month>",tag2 = "</Month>";
            line = TTools::tagremove(line, tag1);
            line = TTools::tagremove(line, tag2);
            this->month = atoi(line.c_str());
        }else if(TTools::strcontain(line,"<Year>"))
        {
            std::string tag1 = "<Year>",tag2 = "</Year>";
            line = TTools::tagremove(line, tag1);
            line = TTools::tagremove(line, tag2);
            this->year = atoi(line.c_str());
        }
    }
    return 0;
}

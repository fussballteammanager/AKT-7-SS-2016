#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

#include "ttools.h"
#include "ttime.h"

using namespace std;

TTime::TTime()
{
    #ifdef DEBUG
        cout << "Constr: TTime" << endl;
    #endif
    TTime::setCurrentTime();
}

TTime::TTime(short hour, short minute)
{
    TTime::setTime(hour, minute);
}

TTime::~TTime()
{
    #ifdef DEBUG
        cout << "Destr: TTime" << endl;
    #endif
}

void TTime::setTime(short hour, short minute)
{
    if ( hour >= 0 and hour <=23 and minute >= 0 and minute <=59 )
    {
        TTime::hour = hour;
        TTime::minute = minute;
    }else
    {
        TTime::setCurrentTime();
    }
}

void TTime::setCurrentTime()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    TTime::hour = ltm->tm_hour;
    TTime::minute = ltm->tm_min;
}

short TTime::getHour()
{
    return TTime::hour;
}

short TTime::getMinute()
{
    return TTime::minute;
}

void TTime::print()
{
    cout << setw(2) << setfill('0') << this->hour
        << ":" << setw(2) << setfill('0') << this->minute;
}


int TTime::load(std::ifstream &ifs)
{
    string line;
    while(ifs.good())
    {
        line = TTools::ReadUnspaced(ifs);

        if ( TTools::strcontain( line, "</Time>" ) )
        {
            #ifdef DEBUG
                cout << line << endl;
            #endif
            return 1;
        }
        else if( TTools::strcontain( line,"<Hour>" ) )
        {
            #ifdef DEBUG
                cout << line << endl;
            #endif
            string tag1 = "<Hour>",tag2 = "</Hour>";
            line = TTools::tagremove(line, tag1);
            line = TTools::tagremove(line, tag2);
            this->hour = atoi(line.c_str());
        }
        else if( TTools::strcontain( line, "<Minute>" ) )
        {
            #ifdef DEBUG
                cout << line << endl;
            #endif
            string tag1 = "<Minute>",tag2 = "</Minute>";
            line = TTools::tagremove(line, tag1);
            line = TTools::tagremove(line, tag2);
            this->minute = atoi(line.c_str());
        }
    }
    return 0;
}

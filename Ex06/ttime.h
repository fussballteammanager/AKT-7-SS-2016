#ifndef TTIME_H
#define TTIME_H TTIME_H

#include <iostream>
#include <iomanip>

using namespace std;

class TTime
{
    private:
        short hour;
        short minute;
        void setCurrentTime();

    public:
        TTime();
        TTime(short hour, short minute);
        ~TTime();

        void setTime(short hour, short minute);
        short getHour();
        short getMinute();
        int load(ifstream &ifs);
        void print();
        friend ostream& operator<<(ostream& os, TTime& Time)
        {
            return os  << setw(2) << setfill('0') << Time.getHour()
                << ":" << setw(2) << setfill('0') << Time.getMinute();
        }
};

#endif


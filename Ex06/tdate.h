#ifndef TDATE_H
#define TDATE_H TDATE_H

#include <iostream>
#include <iomanip>

using namespace std;

class TDate
{
    private:
        short day;
        short month;
        short year;

    public:
        TDate();
        TDate(short day, short month, short year);
        ~TDate();

        void setDate(short day, short month, short year);
        void setCurrentDate();
        short getDay();
        short getMonth();
        short getYear();
        int load(ifstream &ifs);

        friend ostream& operator<<(ostream& os, TDate& Date)
        {
            return os << setw(2) << setfill('0') << Date.getDay()
            << "." << setw(2) << Date.getMonth()
            << "."<<  setw(4) << Date.getYear();
        }
};

#endif

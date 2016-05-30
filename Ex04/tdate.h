#ifndef TDATE_H
#define TDATE_H TDATE_H

/******************************************************
 * FUNKTION: Date  class
 *-----------------------------------------------------
 * BESCHREIBUNG: class definition
 * GELTUNGSBEREICH: Global
 * PARAMETER: Constructor with or without parameters (default values)
 --------------------------------------------------
 * ERSTELLT VON: ts
 *           AM: 10.04.2016
 * ÄNDERUNGEN  : -
 ******************************************************/


class TDate
{
    private:
        short day;
        short month;
        short year;

    public:
        TDate();
        TDate(short day, short month, short year);
        void setDate(short day, short month, short year);
        void setCurrentDate();
        short getDay();
        short getMonth();
        short getYear();
        int load(std::ifstream &ifs);
        void print();
};

#endif

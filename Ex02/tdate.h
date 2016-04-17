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
            void setDate(short day, short month, short year);
            /* set date of today */
            void setCurrentDate();
            short getDay();
            short getMonth();
            short getYear();
            /* prshort date */
            void print();
    };

#endif

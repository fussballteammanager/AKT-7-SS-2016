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

#ifndef tdate_h
    #define tdate_h tdate_h

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
            /* print date */
            void print();
    };

#endif

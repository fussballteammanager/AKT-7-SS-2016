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
    #define tdate_h

    class TDate
    {
        private:
            int day;
            int month;
            int year;

        public:
            TDate();
            TDate(int day, int month, int year);
            ~TDate();
            void setDate(int day, int month, int year);
            /* set date of today */
            void setCurrentDate();
            int getDay();
            int getMonth();
            int getYear();
            /* print date */
            void print();
    };

#endif

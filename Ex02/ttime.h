/******************************************************
 * FUNKTION: Time class
 *-----------------------------------------------------
 * BESCHREIBUNG: class definition
 * GELTUNGSBEREICH: Global
 * PARAMETER: Constructor with or without parameters (default values)
 --------------------------------------------------
 * ERSTELLT VON: ts
 *           AM: 10.04.2016
 * ÄNDERUNGEN  : -
 ******************************************************/

#ifndef TTIME_H
    #define TTIME_H TTIME_H
    using namespace std;

    class TTime
    {
        private:
            int hour;
            int minute;
            void setCurrentTime();

        public:
            TTime();
            TTime(int hour, int minute);
            void setTime(int hour, int minute);
            int getHour();
            int getMinute();
            /* print time */
            void print();
    };

#endif


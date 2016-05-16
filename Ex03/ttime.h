#ifndef TTIME_H
    #define TTIME_H TTIME_H

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


    class TTime
    {
        private:
            short hour;
            short minute;
            void setCurrentTime();

        public:
            TTime();
            TTime(short hour, short minute);
            void setTime(short hour, short minute);
            short getHour();
            short getMinute();
            /* print time */
            void print();
    };

#endif


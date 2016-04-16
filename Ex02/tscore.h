/******************************************************
 * FUNKTION: Score class
 *-----------------------------------------------------
 * BESCHREIBUNG: class definition
 * GELTUNGSBEREICH: Global
 * PARAMETER: Constructor with or without parameters (default values)
 --------------------------------------------------
 * ERSTELLT VON: ts
 *           AM: 10.04.2016
 * ÄNDERUNGEN  : -
 ******************************************************/

#ifndef tscore_h
    #define tscore_h tscore_h

    class TScore
    {
        private:
            short goalsHome;
            short goalsGuest;

        public:
            TScore();
            TScore(short goalsHome, short goalsGuest);
            void setGoals(short goalsHome, short goalsGuest);
            short getPointsHome();
            short getPointsGuest();
            /* print goals */
            void print();
    };

#endif

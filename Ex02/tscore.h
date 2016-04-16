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

#ifndef TSCORE_H
    #define TSCORE_H TSCORE_H
    using namespace std;

    class TScore
    {
        private:
            int goalsHome;
            int goalsGuest;

        public:
            TScore();
            TScore(int goalsHome, int goalsGuest);
            void setGoals(int goalsHome, int goalsGuest);
            int  getPointsHome();
            int  getPointsGuest();
            /* print goals */
            void print();
    };

#endif

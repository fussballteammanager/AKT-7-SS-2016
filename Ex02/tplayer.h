/******************************************************
 * FUNKTION: Player class
 *-----------------------------------------------------
 * BESCHREIBUNG: class definition
 * GELTUNGSBEREICH: Global
 * PARAMETER: Constructor with parameters
 --------------------------------------------------
 * ERSTELLT VON: ts
 *           AM: 16.04.2016
 * ÄNDERUNGEN  : -
 ******************************************************/

#include"tdate.h"

#ifndef tplayer_h
    #define tplayer_h tplayer_h

    class TPlayer
    {
        private:
            string Name;
            short TricotNr;
            TDate Birthday;
            string Position;
            int NumberOfGoals;
            int NumberOfPasses;
            int NumberOfGames;
            int NumberOfYellowCards;
            int NumberOfRedCards;
        public:
            TPlayer();
            //Functions here
            /* print goals */
            void print();
    };

#endif

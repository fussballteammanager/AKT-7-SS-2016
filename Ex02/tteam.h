/******************************************************
 * FUNKTION: Team class
 *-----------------------------------------------------
 * BESCHREIBUNG: class definition
 * GELTUNGSBEREICH: Global
 * PARAMETER: Constructor with parameters
 --------------------------------------------------
 * ERSTELLT VON: ts
 *           AM: 16.04.2016
 * ÄNDERUNGEN  : -
 ******************************************************/

#include"tscore.h"
#include"tplayer.h"

#ifndef tteam_h
    #define tteam_h tteam_h

    class TTeam
    {
        private:
            string Name;
            string Trainer;
            int NumberOfGames;
            TScore Goals;
            int NumberOfPoints;
            int NumberOfPlayers;
            TPlayer *Players[];
        public:
            TTeam();
            //Functions here
            /* print goals */
            void print();
    };

#endif

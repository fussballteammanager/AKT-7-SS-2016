#ifndef TTOURNAMENT_H
#define TTOURNAMENT_H TTOURNAMENT_H

#include "tteam.h"
#include "tstadium.h"
#include "tmatch.h"

#define MAXTEAMS 12
#define MAXSTADIUMS 12
#define MAXMATCHES 12

using namespace std;

class TTournament
{
    private:
        string TName;
        int NumberOfTeams;
        TTeam *Team[MAXTEAMS];
        int NumberOfMatches;
        TMatch *Matches[MAXMATCHES];
        int NumberOfStadiums;
        TStadium *Stadium[MAXSTADIUMS];

    public:
        TTournament(string DName);
        virtual ~TTournament();

        string GetTName() { return TName; }
        void SetTName(string val) { TName = val; }

        int GetNumberOfTeams() { return NumberOfTeams; }
        void SetNumberOfTeams(int val) { NumberOfTeams = val; }
        TTeam *GetTeam(int index) { return Team[index]; }
        void setTeam(TTeam val, int index) { *Team[index] = val; }

        int GetNumberOfMatches() { return NumberOfMatches; }
        void SetNumberOfMatches(int val) { NumberOfMatches = val; }
        TMatch *GetMatch(int index) { return Matches[index]; }
        void SetMatch(TMatch val, int index) { *Matches[index] = val; }

        int GetNumberOfStadiums() { return NumberOfStadiums; }
        void SetNumberOfStadiums(int val) { NumberOfStadiums = val; }
        TStadium *GetStadium(int index) { return Stadium[index]; }
        void SetStadium(TStadium val, int index) { *Stadium[index] = val; }

        int load(ifstream &ifs);
        void print();
        friend ostream& operator<<(ostream& os, TTournament& Tournament)
        {
            int i;
            os << "Turnier: " << Tournament.GetTName() << endl << endl << "Stadien:" << endl;
            for( i = 0; i < Tournament.GetNumberOfStadiums(); i++ )
            {
                os << "- ";
                Tournament.GetStadium(i)->print();
            }

            os << endl << "Teams:" << endl;
            for( i = 0; i < Tournament.GetNumberOfTeams(); i++)
                Tournament.GetTeam(i)->print();

            os << endl << "Spiele:" << endl;

            /* overload << operator in Match! */
//            for( i = 0; i < Tournament.GetNumberOfMatches(); i++)
//                Tournament.GetMatch(i)->print();
            return os;
        }

    protected:
};

#endif // TTOURNAMENT_H


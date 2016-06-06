#ifndef TTOURNAMENT_H
#define TTOURNAMENT_H TTOURNAMENT_H

#include "tteam.h"
#include "tstadium.h"
#include "tmatch.h"

#define MAXTEAMS 12
#define MAXSTADIUMS 12
#define MAXMATCHES 12


class TTournament
{
    private:
        std::string TName;
        int NumberOfTeams;
        TTeam *Team[MAXTEAMS];
        int NumberOfMatches;
        TMatch *Matches[MAXMATCHES];
        int NumberOfStadiums;
        TStadium *Stadium[MAXSTADIUMS];

    public:
        TTournament(std::string DName);
        virtual ~TTournament();

        std::string GetTName() { return TName; }
        void SetTName(std::string val) { TName = val; }

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

        int load(std::ifstream &ifs);
        void print();

    protected:
};

#endif // TTOURNAMENT_H

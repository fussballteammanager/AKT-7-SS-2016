#ifndef TTEAM_H
#define TTEAM_H TTEAM_H

#include"tscore.h"
#include"tplayer.h"
#include <string>


const int MAXPLAYER = 30;

class TTeam
{
    private:
        std::string name;
        std::string trainer;
        unsigned int NumberOfGames;
        TScore Goals;
        int NumberOfPoints;
        static int NumberOfPlayers;
        TPlayer *Players[MAXPLAYER];

    public:
        TTeam();
        TTeam(std::string name, std::string trainer);
        virtual ~TTeam();
        std::string Getname() { return name; }
        void Setname(std::string val) { name = val; }
        std::string Gettrainer() { return trainer; }
        void Settrainer(std::string val) { trainer = val; }
        unsigned int GetNumberOfGames() { return NumberOfGames; }
        void SetNumberOfGames(unsigned int val) { NumberOfGames = val; }
        TScore GetGoals() { return Goals; }
        void SetGoals(TScore val) { Goals = val; }
        int GetNumberOfPoints() { return NumberOfPoints; }
        void SetNumberOfPoints(int val) { NumberOfPoints = val; }
        static int GetNumberOfPlayers() { return NumberOfPlayers; }
        TPlayer *GetPlayers(int index) { return Players[index]; }
        void SetPlayers(TPlayer *val, int index) { Players[index] = val; }
        int load(std::ifstream &ifs);
        bool addPlayer(TPlayer Player);
        bool removePlayer(TPlayer &Player);
        void print();

    protected:

};

#endif // TTEAM_H

#ifndef TTEAM_H
#define TTEAM_H TTEAM_H
using namespace std;

const int MAXPLAYER = 30;

class TTeam
{
    private:
        string name;
        string trainer;
        unsigned int NumberOfGames;
        TScore Goals;
        int NumberOfPoints;
        int NumberOfPlayers;
        TPlayer *Players[MAXPLAYER];
    public:
        TTeam(string name, string trainer);
        virtual ~TTeam();
        string Getname() { return name; }
        void Setname(string val) { name = val; }
        string Gettrainer() { return trainer; }
        void Settrainer(string val) { trainer = val; }
        unsigned int GetNumberOfGames() { return NumberOfGames; }
        void SetNumberOfGames(unsigned int val) { NumberOfGames = val; }
        TScore GetGoals() { return Goals; }
        void SetGoals(TScore val) { Goals = val; }
        int GetNumberOfPoints() { return NumberOfPoints; }
        void SetNumberOfPoints(int val) { NumberOfPoints = val; }
        int GetNumberOfPlayers() { return NumberOfPlayers; }
        void SetNumberOfPlayers(int val) { NumberOfPlayers = val; }
        TPlayer GetPlayers() { return **Players; }
        void SetPlayers(TPlayer val) { **Players = val; }

        bool addPlayer(TPlayer Player);
        bool removePlayer(TPlayer Player);
        void print();

    protected:

};

#endif // TTEAM_H

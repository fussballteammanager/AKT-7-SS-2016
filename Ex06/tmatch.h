#ifndef TMATCH_H
#define TMATCH_H TMATCH_H

#include "tteam.h"
#include "tteam.h"
#include "tevent.h"
#include "tscore.h"
#include "tdate.h"
#include "tplayer.h"
#include "ttime.h"
#include "tstadium.h"


#include <vector>
#include <string>

#define MAXTEAMMEMBER 11

using namespace std;

class TMatch
{
    private:
        TDate Date;
        TTime Time;
        TTeam *HomeTeam;
        TTeam *GuestTeam;
        vector<TPlayer*> HomePlayer;
        vector<TPlayer*> GuestPlayer;
        vector<TEvent*> Events;
        TScore Score;
        string Referee;
        TStadium *Stadium;

    public:
        TMatch();
        ~TMatch();

        TDate GetDate() { return Date; }
        void SetDate(TDate val) { Date = val; }
        TTime GetTime() { return Time; }
        void SetTime(TTime val) { Time = val; }
        TTeam *GetHomeTeam() { return HomeTeam; }
        void SetHomeTeam(TTeam *val) { HomeTeam = val; }
        TTeam *GetGuestTeam() { return GuestTeam; }
        void SetGuestTeam(TTeam *val) { GuestTeam = val; }

        void AddHomePlayer( TPlayer* HPlayer);
        void AddGuestPlayer( TPlayer* GPlayer);
        void AddEvent( TEvent* NewEvent ) { Events.push_back(NewEvent); }
        void SubstituteHomePlayer( TPlayer* exhaustedPlayer, TPlayer* replacementPlayer );
        void SubstituteGuestPlayer( TPlayer* exhaustedPlayer, TPlayer* replacementPlayer );

        TScore GetScore() { return Score; }
        void SetScore(TScore val) { Score = val; }
        std::string GetReferee() { return Referee; }
        void SetReferee(std::string val) { Referee = val; }
        TStadium *GetStadium() { return Stadium; }
        void SetStadium(TStadium *val) { Stadium = val; }
        int load(std::ifstream &ifs, TTeam **Team, TStadium **Stadium );
        void print();
};

#endif // TMATCH_H


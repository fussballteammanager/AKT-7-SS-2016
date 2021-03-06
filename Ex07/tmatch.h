#ifndef TMATCH_H
#define TMATCH_H TMATCH_H

#include "tlist.h"
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
        TList<TEvent*> Events;
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
        //void AddEvent( TEvent* NewEvent ) { Events.push_back(NewEvent); }
        TMatch operator+= (TEvent* NewEvent)
        {

            Events.push_back(NewEvent);
            return *this;
        }

        TScore GetScore() { return Score; }
        void SetScore(TScore val) { Score = val; }
        string GetReferee() { return Referee; }
        void SetReferee(string val) { Referee = val; }
        TStadium *GetStadium() { return Stadium; }
        void SetStadium(TStadium *val) { Stadium = val; }
        int load(ifstream &ifs, TTeam **Team, TStadium **Stadium );

        friend ostream& operator<<(ostream& os, TMatch& Match)
        {
            unsigned int i;
            TDate Date = Match.GetDate();
            TTime Time = Match.GetTime();
            TStadium *Stadium = Match.GetStadium();

            os << "Spiel am " << Date << " um " << Time << endl << "Austragungsort: "
                << *Stadium << endl << "Schiedsrichter: " << Match.GetReferee() << endl << endl
                << "Heimmannschaft: " << Match.GetHomeTeam()->GetName()
                << " (Trainer: " << Match.GetHomeTeam()->Gettrainer() << ")" << endl
                << "Gastmannschaft: " << Match.GetGuestTeam()->GetName()
                << " (Trainer: " << Match.GetGuestTeam()->Gettrainer() << ")" << endl << endl;

            os << "Spieleraufstellung Heimmannschaft: " << endl;
            for( i = 0; i < Match.HomePlayer.size(); i++ )
            {
                os.setf(ios::right, ios::adjustfield);
                os << setw(2) << setfill(' ') << i+1 << ".: "
                    << Match.HomePlayer.at(i)->Getname() << endl;
            }

            os << endl << "Spieleraufstellung Gastmannschaft: " << endl;

            for(std::vector<TPlayer*>::iterator iter = Match.GuestPlayer.begin() ; iter != Match.GuestPlayer.end(); ++iter )
            {
                os << setw(2) << setfill(' ') << i+1 << ".: "
                    << **iter << endl;
            }
            os << endl;
            for(TList<TEvent*>::Iterator iter = Match.Events.begin(); iter != Match.Events.end(); ++iter )
            {
                os << **iter << endl;
            }
            os << endl << "Spielstand: ";

            TScore Score = Match.GetScore();
            os << Score << endl;

            return os;
        }
};

#endif // TMATCH_H


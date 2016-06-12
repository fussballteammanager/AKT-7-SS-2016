#ifndef TEVENT_H
#define TEVENT_H TEVENT_H

#include <string>
#include <iostream>
#include <vector>

#include "tplayer.h"
#include "tteam.h"
#include "tscore.h"

using namespace std;

class TEvent
{
    private:
        int MinuteOfPlay;
        TPlayer *Player;

    public:
        TEvent() : MinuteOfPlay(0), Player(0) {}
        TEvent( int Minute, TPlayer *Player) :MinuteOfPlay(Minute), Player(Player)
        {
            cout << "Constr: TEvent" << endl;
        }
        virtual ~TEvent()
        {
            cout << "Destr: TEvent" << endl;
        }

        int GetMinuteOfPlay() { return MinuteOfPlay; }
        void SetMinuteOfPlay(int val) { MinuteOfPlay = val; }
        virtual void SetPlayer( TPlayer *RefPlayer ) {  Player = RefPlayer; }
        virtual TPlayer* GetPlayer() { return Player; }
        virtual int load( ifstream &ifs, vector<TPlayer*> &HomePlayer, vector<TPlayer*> &GuestPlayer ) { return 0; }
        virtual int load( ifstream &ifs, vector<TPlayer*> &HomePlayer, vector<TPlayer*> &GuestPlayer,
            TTeam* &HomeTeam, TTeam* &GuestTeam ) { return 0;}
        virtual int load( ifstream &ifs, vector<TPlayer*> &HomePlayer, vector<TPlayer*> &GuestPlayer, TScore &Score ) { return 0;}
        virtual void print() {}

        virtual ostream& print( ostream& ostr )
        {
            ostr << "was here 222222222222222222222" << endl;
//            ostr << setfill(' ') << setw(2)
//                << TEvent::GetMinuteOfPlay() <<". Spielminute: ";
            return ostr;
        }

        friend ostream& operator<<(ostream& ostr, TEvent& Event)
        {
            cout << "was here 111111111111111111111111" << endl;
            return Event.print( ostr );
        }

    protected:

};


#endif // TTOOLS_H

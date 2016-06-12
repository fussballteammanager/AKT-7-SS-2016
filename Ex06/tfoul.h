#ifndef TFOUL_H
#define TFOUL_H TFOUL_H

#include <iostream>
#include <vector>

//#include "tplayer.h"
#include "tevent.h"

using namespace std;

class TFoul: public TEvent
{
    private:
        TPlayer *FouledPlayer;

    public:
        TFoul(): TEvent(), FouledPlayer(0) {}
        TFoul( int Minute, TPlayer *suspect, TPlayer *victim):
            TEvent( Minute, suspect), FouledPlayer(victim)
            {
                cout << "Constr: TFoul" << endl;
            }
        ~TFoul()
        {
            cout << "Destr: TFoul" << endl;
        }

        void SetPlayer( TPlayer *Player) { FouledPlayer = Player; }
        TPlayer* GetPlayer() { return FouledPlayer; }
        int load( ifstream &ifs, vector<TPlayer*> &HomePlayer, vector<TPlayer*> &GuestPlayer );
        void print();

        ostream& print( ostream& ostr )
        {
            if ( GetPlayer() == 0 || TEvent::GetPlayer() == 0 )
                ostr << "Kein Spielereintrag für Faul!" << endl;
            else
                TEvent::print( ostr ) << "FOUL an " << FouledPlayer->Getname() << " von "
                    << TEvent::GetPlayer()->Getname();

            return ostr;
        }

//        friend ostream& operator<<(ostream& ostr, TFoul& Foul)
//        {
//        cout << "in Foul ***********************" << endl;
//            return Foul.print( ostr );
//        }

};

#endif // TFOUL_H

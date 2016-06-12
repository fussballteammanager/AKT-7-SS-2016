#ifndef TCARD_H
#define TCARD_H TCARD_H

#include <iostream>

#include "tevent.h"

using namespace std;

class TCard: public TEvent
{
    private:
        bool yellow;
        bool red;

    public:
        TCard(): yellow(0), red(0) {}
        TCard( int Minute, TPlayer *Player, bool yellow, bool red ):
            TEvent( Minute, Player ),  yellow(yellow), red(red)
        {
            cout << "Constr: TCard" << endl;
        }

        ~TCard()
        {
            cout << "Destr: TCard" << endl;
        }

        void SetYellowCard( bool card ) { yellow = card; }
        bool GetYellowCard() { return yellow; }
        void SetRedCard( bool card ) { red = card; }
        bool GetRedCard() { return red; }
        int load( ifstream &ifs, vector<TPlayer*> &HomePlayer, vector<TPlayer*> &GuestPlayer );
        void print();

        ostream& print( ostream& ostr )
        {
            TEvent::print( ostr);

            if ( TEvent::GetPlayer() == 0 )
                ostr << "Kein Spielereintrag für gelbe oder rote Karte!" << endl;
            else
            {
                if ( yellow == true && red == false )
                    ostr << "GELBE KARTE fuer " << TEvent::GetPlayer()->Getname();
                else if ( yellow == false && red == true )
                    ostr << "ROTE KARTE fuer " << TEvent::GetPlayer()->Getname();
                else if ( yellow == true && red == true )
                    ostr << "GELB/ROTE KARTE fuer " << TEvent::GetPlayer()->Getname();
                else
                    ostr << "Schiedsrichter Entscheidung aufgehoben, KEINE KARTE fuer "
                        << TEvent::GetPlayer()->Getname();
            }

            return ostr;
        }

};

#endif // TCARD_H

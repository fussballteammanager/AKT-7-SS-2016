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
        //    return ostr << setfill(' ') << setw(2)
        //        << TEvent::GetMinuteOfPlay() <<". Spielminute: ";

            cout << "was her 1111 *******************" << endl;
#if 0
            if ( TEvent::GetPlayer() == 0 )
                ostr << "Kein Spielereintrag für gelbe oder rote Karte!" << endl;
            else
            {
                ostr.setf(ios::right, ios::adjustfield);
                if ( yellow == true && red == false )
                    ostr << setfill(' ') << setw(2) << TEvent::GetMinuteOfPlay()
                        <<". Spielminute: GELBE KARTE fuer " << TEvent::GetPlayer()->Getname() << endl;
                else if ( yellow == false && red == true )
                    ostr << setfill(' ') << setw(2) << TEvent::GetMinuteOfPlay()
                        <<". Spielminute: ROTE KARTE fuer " << TEvent::GetPlayer()->Getname() << endl;
                else if ( yellow == true && red == true )
                    ostr << setfill(' ') << setw(2) << TEvent::GetMinuteOfPlay()
                        <<". Spielminute: GLEB/ROTE KARTE fuer " << TEvent::GetPlayer()->Getname() << endl;
                else
                    ostr << setfill(' ') << setw(2) << TEvent::GetMinuteOfPlay()
                        <<". Spielminute: Schiedsrichter Entscheidung aufgehoben, KEINE KARTE fuer " << TEvent::GetPlayer()->Getname() << endl;
            }
#endif
            return ostr;
        }

//        friend ostream& operator<<(ostream& ostr, TEvent& Event )
//        {
//            ostr << "war auch here :) *&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;
//            return Event::print( ostr );
//        }
};

#endif // TCARD_H

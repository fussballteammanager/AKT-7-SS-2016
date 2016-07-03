#ifndef TFREEKICK_H
#define TFREEKICK_H TFREEKICK_H

#include <iostream>

#include "tmatch.h"
#include "tevent.h"


class TFreeKick: public TEvent
{
    private:
        int Distance;

    public:
        TFreeKick(): Distance(0) {}
        TFreeKick( int Minute, TPlayer *Player, int Dist ):
            TEvent( Minute, Player ), Distance(Dist)
        {
            std::cout << "Constr: TFreeKick" << std::endl;
        }

        ~TFreeKick()
        {
            std::cout << "Destr: TFreeKick" << std::endl;
        }

        void SetDistance( int Dist ) { Distance = Dist; }
        int GetDistance() { return Distance; }
        int load( ifstream &ifs, vector<TPlayer*> &HomePlayer, vector<TPlayer*> &GuestPlayer );

        ostream& print( ostream& ostr )
        {

            if ( TEvent::GetPlayer() == 0 )
                ostr << "Kein Spielereintrag für Freistoß!" << endl;
            else
            {
                TEvent::print( ostr ) << "FREISTOSS (Abstand zum Tor: " << Distance << " m)!" << endl;
                ostr <<  "\t\t Wird ausgeführt von " << TEvent::GetPlayer()->Getname();
            }

            return ostr;
        }
};


#endif // TFREEKICK_H

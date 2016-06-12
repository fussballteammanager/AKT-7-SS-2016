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
        virtual void print();

//        friend ostream& operator<<(ostream& os, TEvent& Event)
//        {
//            return TEvent::print(os, Event);
//        }
};


#endif // TFREEKICK_H

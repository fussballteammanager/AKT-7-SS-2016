#ifndef TCARD_H
#define TCARD_H TCARD_H

#include <iostream>

#include "tevent.h"


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
            std::cout << "Constr: TCard" << std::endl;
        }

        ~TCard()
        {
            std::cout << "Destr: TCard" << std::endl;
        }

        void SetYellowCard( bool card ) { yellow = card; }
        bool GetYellowCard() { return yellow; }
        void SetRedCard( bool card ) { red = card; }
        bool GetRedCard() { return red; }
        int load( ifstream &ifs, vector<TPlayer*> &HomePlayer, vector<TPlayer*> &GuestPlayer );
        void print();
};

#endif // TCARD_H

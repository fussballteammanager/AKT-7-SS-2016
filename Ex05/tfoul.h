#ifndef TFOUL_H
#define TFOUL_H TFOUL_H

#include <iostream>

#include "tmatch.h"
#include "tevent.h"


class TFoul: public TEvent, public TMatch
{
    private:
        TPlayer *FouledPlayer;

    public:
        TFoul(): TEvent(), FouledPlayer(0) {}
        TFoul( int Minute, TPlayer *suspect, TPlayer *victim):
            TEvent( Minute, suspect), FouledPlayer(victim)
            {
                std::cout << "Constr: TFoul" << std::endl;
            }
        ~TFoul()
        {
            std::cout << "Destr: TFoul" << std::endl;
        }

        void SetPlayer( TPlayer *Player) { FouledPlayer = Player; }
        TPlayer* GetPlayer() { return FouledPlayer; }
        int load(std::ifstream &ifs, TMatch* Match);
        void print();
};

#endif // TFOUL_H

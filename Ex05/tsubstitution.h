#ifndef TSUBSTITUTING_H
#define TSUBSTITUTING_H TSUBSTITUTING_H

#include <iostream>

#include "tevent.h"


class TSubstituting: public TEvent
{
    private:
        /* player to replace the other */
        TPlayer *subPlayer;

    public:
        TSubstituting(): subPlayer(0) {}
        TSubstituting( int Minute, TPlayer *old, TPlayer *exchange):
            TEvent( Minute, old), subPlayer(exchange)
        {
            std::cout << "Constr: TSubstituting" << std::endl;
        }

        ~TSubstituting()
        {
            std::cout << "Destr: TSubstituting" << std::endl;
        }

        void SetPlayer( TPlayer *Player) { subPlayer = Player; }
        TPlayer* GetPlayer() { return subPlayer; }

        void print();
};

#endif // TSUBSTITUTING_H

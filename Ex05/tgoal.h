#ifndef TGOAL_H
#define TGOAL_H TGOAL_H

#include <iostream>

#include "tmatch.h"
#include "tevent.h"


class TGoal: public TEvent
{
    private:
        TPlayer *PassPlayer;
        bool Owngoal;

    public:
        TGoal(): PassPlayer(0) {}
        TGoal( int Minute, TPlayer *GPlayer, TPlayer *PassPlayer, bool Owngoal):
            TEvent( Minute, GPlayer), PassPlayer(PassPlayer), Owngoal(Owngoal)
        {
            std::cout << "Constr: TGoal" << std::endl;
        }

        ~TGoal()
        {
            std::cout << "Destr: TGoal" << std::endl;
        }

        void SetPlayer( TPlayer *Player) { PassPlayer = Player; }
        TPlayer* GetPlayer() { return PassPlayer; }

        void print();
};

#endif // TGOAL_H

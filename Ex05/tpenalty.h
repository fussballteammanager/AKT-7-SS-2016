#ifndef TPENALTY_H
#define TPENALTY_H TPENALTY_H

#include <iostream>

#include "tfreekick.h"


class TPenalty: public TFreeKick
{
    private:
        bool Goal;

    public:
        TPenalty():  Goal( false ) {}
        TPenalty( int Minute, TPlayer *Player, bool Goal):
            TFreeKick( Minute, Player, 11 ),  Goal(Goal)
        {
            std::cout << "Constr: TPenalty" << std::endl;
        }

        ~TPenalty()
        {
            std::cout << "Destr: TPenalty" << std::endl;
        }

        void SetGoal( bool Success ) { Goal = Success; }
        bool GetGoal() { return Goal; }
        int load( ifstream &ifs, vector<TPlayer*> &HomePlayer, vector<TPlayer*> &GuestPlayer );

        void print();
};

#endif // TPENALTY_H

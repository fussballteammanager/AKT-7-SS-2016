#ifndef TEVENT_H
#define TEVENT_H TEVENT_H

#include <string>
#include <iostream>

#include "tplayer.h"

class TEvent
{
    private:
        int MinuteOfPlay;
        TPlayer *Player;

    public:
        TEvent() : MinuteOfPlay(0), Player(0) {}
        TEvent( int Minute, TPlayer *Player) :MinuteOfPlay(Minute), Player(Player)
        {
            std::cout << "Constr: TEvent" << std::endl;
        }
        virtual ~TEvent()
        {
            std::cout << "Destr: TEvent" << std::endl;
        }

        int GetMinuteOfPlay() { return MinuteOfPlay; }
        void SetMinuteOfPlay(int val) { MinuteOfPlay = val; }
        virtual void SetPlayer( TPlayer *RefPlayer ) {  Player = RefPlayer; }
        virtual TPlayer* GetPlayer() { return Player; }
        virtual int load(std::ifstream &ifs) { return 0; }
        virtual void print() {}

    protected:

};


#endif // TTOOLS_H

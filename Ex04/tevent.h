#ifndef TEVENT_H
#define TEVENT_H TEVENT_H

#include <string>
#include "tplayer.h"

class TEvent
{
    private:
        int MinuteOfPlay;
        TPlayer *Player;

    public:
        TEvent();
        virtual ~TEvent();

        int GetMinuteOfPlay() { return MinuteOfPlay; }
        void SetMinuteOfPlay(int val) { MinuteOfPlay = val; }
        virtual void SetPlayer( TPlayer *RefPlayer ) {  Player = RefPlayer; }
        virtual TPlayer* GetPlayer() { return Player; }
        virtual void print() {}
    protected:

};

class TFoul: public TEvent
{
    private:
        TPlayer *FouledPlayer;

    public:
        TFoul();
        TFoul( int Minute, TPlayer *suspect, TPlayer *victim);

        TPlayer* GetPlayer() { return FouledPlayer; }
        void print();
};












#endif // TTOOLS_H

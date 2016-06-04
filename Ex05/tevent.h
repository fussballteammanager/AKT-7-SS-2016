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
        TEvent();
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
        virtual void print() {}
    protected:

};

class TFoul: public TEvent
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
        void print();
};

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
        virtual void print();
};

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
        void print();
};

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

        void print();
};

#endif // TTOOLS_H

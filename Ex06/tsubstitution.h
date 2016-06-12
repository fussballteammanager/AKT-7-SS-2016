#ifndef TSUBSTITUTING_H
#define TSUBSTITUTING_H TSUBSTITUTING_H

#include <iostream>

#include "tevent.h"
#include "tteam.h"


class TSubstitution: public TEvent
{
    private:
        /* player to replace the other */
        TPlayer *subPlayer;

    public:
        TSubstitution(): subPlayer(0) {}
        TSubstitution( int Minute, TPlayer *old, TPlayer *exchange):
            TEvent( Minute, old), subPlayer(exchange)
        {
            std::cout << "Constr: TSubstituting" << std::endl;
        }

        ~TSubstitution()
        {
            std::cout << "Destr: TSubstituting" << std::endl;
        }

        void SetPlayer( TPlayer *Player) { subPlayer = Player; }
        TPlayer* GetPlayer() { return subPlayer; }
        int load( ifstream &ifs, vector<TPlayer*> &HomePlayer, vector<TPlayer*> &GuestPlayer,
        TTeam* &HomeTeam, TTeam* &GuestTeam );

        ostream& print( ostream& ostr )
        {
            if ( TEvent::GetPlayer() == 0 || GetPlayer() == 0 )
                ostr << "Kein Spielername vorhanden für Torschuss!" << endl;
            else
            {
                TEvent::print( ostr ) << "WECHSEL! Fuer " << TEvent::GetPlayer()->Getname() << " kommt "
                    << subPlayer->Getname();
            }

            return ostr;
        }
};

#endif // TSUBSTITUTING_H

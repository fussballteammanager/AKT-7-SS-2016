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
        TGoal(): PassPlayer(0), Owngoal(false) {}
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
        int load( ifstream &ifs, vector<TPlayer*> &HomePlayer, vector<TPlayer*> &GuestPlayer, TScore &Score );
        void print();

        ostream& print( ostream& ostr )
        {
            TEvent::print( ostr );

            if ( TEvent::GetPlayer() == 0 )
                ostr << "Kein Spielername vorhanden für Torschuss!" << endl;
            else if ( GetPlayer() == 0 && Owngoal == false )
            {
                /* not an owngoal */
                ostr << "TOR!!! Torschuetze: "
                    << TEvent::GetPlayer()->Getname();
            }
            else if ( GetPlayer() == 0 && Owngoal == true )
            {
                /* owngoal */
                ostr << "EIGENTOR!!! Torschuetze: "
                    << TEvent::GetPlayer()->Getname();
            }
            else if ( GetPlayer() != 0 && Owngoal == false )
            {
                /* not an own goal, but with pass  */
                ostr << "TOR!!! Torschuetze: "
                    << TEvent::GetPlayer()->Getname() << endl;
                ostr << "\t\t (Vorlage: " << PassPlayer->Getname() << " )";
            }
            else /* pass and owngoal :) */
            {
                /* not an own goal, but with pass  */
                ostr << "EIGENTOR!!! Torschuetze: "
                    << TEvent::GetPlayer()->Getname() << endl;
                ostr << "\t\t (Vorlage: " << PassPlayer->Getname() << " )";
            }

            return ostr;
        }
};

#endif // TGOAL_H

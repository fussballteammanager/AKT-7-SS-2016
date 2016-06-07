#include <iomanip>

#include "tgoal.h"


void TGoal::print()
{
    if ( TEvent::GetPlayer() == 0 )
        cout << "Kein Spielername vorhanden für Torschuss!" << endl;
    else if ( GetPlayer() == 0 && Owngoal == false )
    {
        /* not an owngoal */
        cout.setf(ios::right, ios::adjustfield);
        cout << setfill(' ') << setw(2)
            << TEvent::GetMinuteOfPlay() <<". Spielminute: TOR!!! Torschütze: "
            << TEvent::GetPlayer()->Getname() << endl;
    }
    else if ( GetPlayer() == 0 && Owngoal == true )
    {
        /* owngoal */
        cout.setf(ios::right, ios::adjustfield);
        cout << setfill(' ') << setw(2)
            << TEvent::GetMinuteOfPlay() <<". Spielminute: EIGENTOR!!! Torschütze: "
            << TEvent::GetPlayer()->Getname() << endl;
    }
    else if ( GetPlayer() != 0 && Owngoal == false )
    {
        /* not an own goal, but with pass  */
        cout.setf(ios::right, ios::adjustfield);
        cout << setfill(' ') << setw(2)
            << TEvent::GetMinuteOfPlay() <<". Spielminute: TOR!!! Torschütze: "
            << TEvent::GetPlayer()->Getname() << endl;
        cout << "\t\t (Vorlage: " << PassPlayer->Getname() << " )" << endl;
    }
    else /* pass and owngoal :) */
    {
        /* not an own goal, but with pass  */
        cout.setf(ios::right, ios::adjustfield);
        cout << setfill(' ') << setw(2)
            << TEvent::GetMinuteOfPlay() <<". Spielminute: EIGENTOR!!! Torschütze: "
            << TEvent::GetPlayer()->Getname() << endl;
        cout << "\t\t (Vorlage: " << PassPlayer->Getname() << " )" << endl;
    }
}

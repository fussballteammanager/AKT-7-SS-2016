#include <iomanip>
#include <iostream>

#include "tsubstitution.h"

using namespace std;


void TSubstituting::print()
{
    if ( TEvent::GetPlayer() == 0 || GetPlayer() == 0 )
        cout << "Kein Spielername vorhanden für Torschuss!" << endl;
    else
    {
        cout.setf(ios::right, ios::adjustfield);
        cout << setfill(' ') << setw(2)
            << TEvent::GetMinuteOfPlay() <<". Spielminute: WECHSEL! Fuer "
            << TEvent::GetPlayer()->Getname() << " kommt "
            << subPlayer->Getname() << endl;
    }
}

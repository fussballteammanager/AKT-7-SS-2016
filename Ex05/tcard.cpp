#include <iomanip>
#include <iostream>

#include "tcard.h"

using namespace std;

void TCard::print()
{
    if ( TEvent::GetPlayer() == 0 )
        cout << "Kein Spielereintrag für gelbe oder rote Karte!" << endl;
    else
    {
        cout.setf(ios::right, ios::adjustfield);
        if ( yellow == true && red == false )
            cout << setfill(' ') << setw(2) << TEvent::GetMinuteOfPlay()
                <<". Spielminute: GELBE KARTE fuer " << TEvent::GetPlayer()->Getname() << endl;
        else if ( yellow == false && red == true )
            cout << setfill(' ') << setw(2) << TEvent::GetMinuteOfPlay()
                <<". Spielminute: ROTE KARTE fuer " << TEvent::GetPlayer()->Getname() << endl;
        else if ( yellow == true && red == true )
            cout << setfill(' ') << setw(2) << TEvent::GetMinuteOfPlay()
                <<". Spielminute: GLEB/ROTE KARTE fuer " << TEvent::GetPlayer()->Getname() << endl;
        else
            cout << setfill(' ') << setw(2) << TEvent::GetMinuteOfPlay()
                <<". Spielminute: Schiedsrichter Entscheidung aufgehoben, KEINE KARTE fuer " << TEvent::GetPlayer()->Getname() << endl;
    }
}

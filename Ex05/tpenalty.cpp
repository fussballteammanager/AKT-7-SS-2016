#include <iomanip>
#include <iostream>

#include "tpenalty.h"

void TPenalty::print()
{
    if ( TEvent::GetPlayer() == 0 )
        std::cout << "Kein Spielername vorhanden für Elfmeter!" << std::endl;
    else
    {
        std::cout.setf(ios::right, ios::adjustfield);
        std::cout << setfill(' ') << setw(2)
            << TEvent::GetMinuteOfPlay() <<". Spielminute: ELFMETER! Ausgeführt von "
            << TEvent::GetPlayer()->Getname() << std::endl;
    }
}

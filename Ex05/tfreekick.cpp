#include <iomanip>

#include "tfreekick.h"


void TFreeKick::print()
{
    if ( TEvent::GetPlayer() == 0 )
        cout << "Kein Spielereintrag für Freistoß!" << endl;
    else
    {
        cout.setf(ios::right, ios::adjustfield);
        cout << setfill(' ') << setw(2)
            << TEvent::GetMinuteOfPlay()
            <<". Spielminute: FREISTOSS (Abstand zum Tor: " << Distance << " m)!" << endl;
        cout <<  "\t\t Wird ausgeführt von " << TEvent::GetPlayer()->Getname() << endl;
    }
}

#include <iomanip>

#include "tfoul.h"


void TFoul::print()
{
    if ( GetPlayer() == 0 || TEvent::GetPlayer() == 0 )
        cout << "Keine Spielereintrag für Faul!" << endl;
    else
    {
        cout.setf(ios::right, ios::adjustfield);
        cout << setfill(' ') << setw(2)
            << TEvent::GetMinuteOfPlay() <<". Spielminute: FOUL an "
            << FouledPlayer->Getname() << " von "
            << TEvent::GetPlayer()->Getname() << endl;
    }
}

int TFoul::load(std::ifstream &ifs, TMatch* Match)
{
    cout << "WAS HERE **********************************************" << endl;
    TTeam *team;
    team =  Match->GetHomeTeam();

    return 0;
}

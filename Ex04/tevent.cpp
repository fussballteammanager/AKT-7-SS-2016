#include <iomanip>
#include <algorithm>
#include <fstream>

#include "tplayer.h"
#include "tevent.h"
#include "ttools.h"
#include <iostream>

using namespace std;

TEvent::TEvent()
{
      MinuteOfPlay = 0;
      Player = NULL;
}

TEvent::~TEvent()
{
   #ifdef DEBUG
        std::cout << "Destr: TEvent" << std::endl;
   #endif
}


/* ********************* TFoul **************************** */
TFoul::TFoul( int Minute, TPlayer *suspect, TPlayer *victim )
{
    TEvent::SetMinuteOfPlay( Minute );
    TEvent::SetPlayer( suspect );
    FouledPlayer = victim;
}

void TFoul::print()
{
//    TPlayer* test = GetPlayer();
//    std::cout << "Name: " << test->Getname() << std::endl;
//    test = TEvent::GetPlayer();
//    std::cout << "Name: " << test->Getname() << "Minute" << TEvent::GetMinuteOfPlay()  << std::endl;

    if ( GetPlayer() == 0 || TEvent::GetPlayer() == 0 )
        cout << "Keine Eintraege für Faul!" << endl;
    else
    {
        cout.setf(ios::right, ios::adjustfield);
        cout << setfill(' ') << setw(2)
            << TEvent::GetMinuteOfPlay() <<". Spielminute: FOUL an "
        //    << GetPlayer()->Getname() <<            endl;
            << FouledPlayer->Getname() << " von "
            << TEvent::GetPlayer()->Getname() << endl;
    }
}

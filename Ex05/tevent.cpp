#include <iomanip>
#include <algorithm>
#include <fstream>
#include <iostream>

#include "tplayer.h"
#include "tevent.h"
#include "ttools.h"

using namespace std;

/* ********************* TFoul **************************** */
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

/* ********************* TFreeKick **************************** */
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

/* ********************* TCard **************************** */
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

/* ********************* TSubstitute **************************** */
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

/* ********************* TGoal **************************** */
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

/* ********************* TPenalty **************************** */
void TPenalty::print()
{
    if ( TEvent::GetPlayer() == 0 )
        cout << "Kein Spielername vorhanden für Elfmeter!" << endl;
    else
    {
        cout.setf(ios::right, ios::adjustfield);
        cout << setfill(' ') << setw(2)
            << TEvent::GetMinuteOfPlay() <<". Spielminute: ELFMETER! Ausgeführt von "
            << TEvent::GetPlayer()->Getname() << endl;
    }



}

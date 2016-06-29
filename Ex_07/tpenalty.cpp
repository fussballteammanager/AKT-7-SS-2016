#include <iomanip>
#include <iostream>
#include <fstream>
#include <algorithm>

#include "ttools.h"
#include "tpenalty.h"

void TPenalty::print()
{
    if ( TEvent::GetPlayer() == 0 )
        std::cout << "Kein Spielername vorhanden für Elfmeter!" << std::endl;
    else
    {
        std::cout.setf(ios::right, ios::adjustfield);
        std::cout << setfill(' ') << setw(2)
            << TEvent::GetMinuteOfPlay() <<". Spielminute: ELFMETER! Ausgefuehrt von "
            << TEvent::GetPlayer()->Getname() << std::endl;
    }
}

int TPenalty::load( ifstream &ifs, vector<TPlayer*> &HomePlayer, vector<TPlayer*> &GuestPlayer )
{
    unsigned int i;
    string line;
    while(ifs.good())
    {
        line = TTools::ReadUnspaced(ifs);
        if ( TTools::strcontain( line,"</Penalty>" ) )
        {
            #ifdef DEBUG
                cout << line << endl;
            #endif
            return 1;
        }
        else if( TTools::strcontain( line,"<MinuteOfPlay>" ) )
        {
            #ifdef DEBUG
                cout << line << endl;
            #endif
            std::string tag1 = "<MinuteOfPlay>",tag2 = "</MinuteOfPlay>";
            line = TTools::tagremove(line, tag1);
            line = TTools::tagremove(line, tag2);
            TEvent::SetMinuteOfPlay( atoi(line.c_str()) );
        }
        else if( TTools::strcontain( line,"<Goal>" ) )
        {
            #ifdef DEBUG
                cout << line << endl;
            #endif
            std::string tag1 = "<Goal>",tag2 = "</Goal>";
            line = TTools::tagremove(line, tag1);
            line = TTools::tagremove(line, tag2);
            if ( line == "true" )
            {
                Goal = true;

                if ( TEvent::GetPlayer() != NULL )
                {
                    /* add card to player account */
                    #ifdef DEBUG
                        cout << TEvent::GetPlayer()->Getname() << " made a goal on penalty: " << Goal << endl;
                    #endif
                }
            }
        }
        else if ( TTools::strcontain(line,"PlayerTricotNr" ) )
        {
            #ifdef DEBUG
                cout << line << endl;
            #endif
            vector<TPlayer*> Player = GuestPlayer;
            string S_Team = "Guest"; /* "Guest" or "Home" */
            if  (  TTools::strcontain(line,"PlayerTricotNr Team=\"Home\">" ) ) /* Home: TFoul or TEvent player */
            {
                Player = HomePlayer;
                S_Team = "Home";
            }

            std::string tag1 = "<PlayerTricotNr Team=\""+S_Team+"\">",tag2 = "</PlayerTricotNr>";
            //cout << "Reconstructed Tag1: " << tag1 << endl;
            line = TTools::tagremove(line, tag1);
            line = TTools::tagremove(line, tag2);
            for ( i = 0; i < Player.size(); i++ )
                if( Player.at(i)->GettricotNr() == atoi(line.c_str()) )
                {
                    TEvent::SetPlayer( Player.at(i) );
                    #ifdef DEBUG
                        cout << "Added " << S_Team << " player to TEvent from TFreeKick: "<< TEvent::GetPlayer()->Getname() << " Nr.: " << TEvent::GetPlayer()->GettricotNr() << endl;
                    #endif
                    break;
                 }
        }
    }
    return 0;
}

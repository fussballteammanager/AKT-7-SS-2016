#include <iomanip>
#include <iostream>
#include <fstream>
#include <algorithm>

#include "ttools.h"

#include "tsubstitution.h"

using namespace std;


void TSubstitution::print()
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

int TSubstitution::load( ifstream &ifs, vector<TPlayer*> &HomePlayer, vector<TPlayer*> &GuestPlayer,
    TTeam* &HomeTeam, TTeam* &GuestTeam )
{
    unsigned int i;
    string line;
    while(ifs.good())
    {
        line = TTools::ReadUnspaced(ifs);
        if ( TTools::strcontain( line,"</Substitution>" ) )
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
        else if ( TTools::strcontain(line,"PlayerTricotNr" ) )
        {
            #ifdef DEBUG
                cout << line << endl;
            #endif
            TTeam* Team = GuestTeam;
            vector<TPlayer*> Player = GuestPlayer;
            string S_Team = "Guest"; /* "Guest" or "Home" */
            string S_New = ""; /* New or "" */
            if  (  TTools::strcontain(line,"PlayerTricotNr Team=\"Home\">" ) ) /* Home: TFoul or TEvent player */
            {
                Team = HomeTeam;
                Player = HomePlayer;
                S_Team = "Home";
            }

            if ( TTools::strcontain(line,"<NewPlayerTricotNr Team=" ) )
                S_New = "New";

            std::string tag1 = "<"+S_New+"PlayerTricotNr Team=\""+S_Team+"\">",tag2 = "</"+S_New+"PlayerTricotNr>";
            #ifdef DEBUG
                cout << "Reconstructed Tags: " << tag1 << tag2 << endl;
            #endif
            line = TTools::tagremove(line, tag1);
            line = TTools::tagremove(line, tag2);

            /* new player is in Team list, not in match list!!! */
            for ( i = 0; Team->GetPlayer(i) != NULL; i++ )
                if( Team->GetPlayer(i)->GettricotNr() == atoi(line.c_str()) )
                {
                    if (S_New == "New" )
                    {
                        subPlayer = Team->GetPlayer(i);
                        #ifdef DEBUG
                            cout << "Added " << S_Team << " subplayer to TSubstitionen: "<< subPlayer->Getname() << " Nr.: " << subPlayer->GettricotNr() << endl;
                        #endif
                    }
                    else
                    {
                        TEvent::SetPlayer( Team->GetPlayer(i));
                        #ifdef DEBUG
                            cout << "Added " << S_Team << " player to TEvent from TSubstition: "<< TEvent::GetPlayer()->Getname() << " Nr.: " << TEvent::GetPlayer()->GettricotNr() << endl;
                        #endif
                    }
                    break;
                }

            if ( subPlayer != NULL && TEvent::GetPlayer() != 0 )
            {
                #ifdef DEBUG
                    cout << "Both added to TSubstitution class, now replace active player vectors" << endl;
                #endif
                for ( i = 0; i < Player.size(); i++ )
                {
                    #ifdef DEBUG
                        cout << Player.at(i)->Getname() << endl;
                    #endif
                    if ( HomePlayer.at(i)->GettricotNr() == TEvent::GetPlayer()->GettricotNr() )
                    {
                        if ( S_Team == "Home" )
                            HomePlayer.at(i) = subPlayer;
                        else
                            GuestPlayer.at(i) = subPlayer;
                    }
                }

                #ifdef DEBUG
                    for ( i = 0; i < Player.size(); i++ )
                    {
                        cout << "Vorher: " << Player.at(i)->Getname() << endl << "Nach Austausch Home: "
                        << HomePlayer.at(i)->Getname() << " Guest: "
                        << GuestPlayer.at(i)->Getname() << endl;
                    }
                #endif
            }
        }
    }
    return 0;
}


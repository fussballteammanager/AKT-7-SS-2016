#include <iomanip>

#include <fstream>
#include <algorithm>

#include "tfoul.h"
#include "ttools.h"

int TFoul::load( ifstream &ifs, vector<TPlayer*> &HomePlayer, vector<TPlayer*> &GuestPlayer )
{
    unsigned int i;
    string line;
    while(ifs.good())
    {
        line = TTools::ReadUnspaced(ifs);
        if ( TTools::strcontain( line,"</Foul>" ) )
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
        else if (  TTools::strcontain(line,"PlayerTricotNr" ) )
        {
            #ifdef DEBUG
                cout << line << endl;
            #endif
            vector<TPlayer*> Player = GuestPlayer;
            string S_Team = "Guest"; /* "Guest" or "Home" */
            string S_Fouled = ""; /* Fouled or "" */
            if  (  TTools::strcontain(line,"PlayerTricotNr Team=\"Home\">" ) ) /* Home: TFoul or TEvent player */
            {
                Player = HomePlayer;
                S_Team = "Home";
            }

            if ( TTools::strcontain(line,"<FouledPlayerTricotNr Team=" ) )
                S_Fouled = "Fouled";

            std::string tag1 = "<"+S_Fouled+"PlayerTricotNr Team=\""+S_Team+"\">",tag2 = "</"+S_Fouled+"PlayerTricotNr>";
            //cout << "Reconstructed Tag1: " << tag1 << endl;
            line = TTools::tagremove(line, tag1);
            line = TTools::tagremove(line, tag2);
            /* add correct player to vector, check tricot numbers :) push_back */
            for ( i = 0; i < Player.size(); i++ )
            {
                //cout << "Nr: " << i << " " << S_Team << " " << S_Fouled << "Tricot Nr.: " << Player.at(i)->GettricotNr() <<  endl;
                if( Player.at(i)->GettricotNr() == atoi(line.c_str()) )
                {
                    //cout << "Found nr.: " << Player.at(i)->GettricotNr() << endl;
                    if ( S_Fouled == "Fouled" )
                    {
                        FouledPlayer = Player.at(i);
                        #ifdef DEBUG
                            cout << "Added " << S_Team << " player to TFoul: "<< FouledPlayer->Getname() << " Nr.: " << FouledPlayer->GettricotNr() << endl;
                        #endif
                    }
                    else
                    {
                        TEvent::SetPlayer( Player.at(i) );
                        #ifdef DEBUG
                            cout << "Added " << S_Team << " player to TEvent from TFoul: "<< TEvent::GetPlayer()->Getname() << " Nr.: " << TEvent::GetPlayer()->GettricotNr() << endl;
                        #endif
                    }
                    break;
                 }
            }
        }
    }
    return 0;
}

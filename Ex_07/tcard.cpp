#include <iomanip>
#include <fstream>
#include <algorithm>

#include "ttools.h"
#include "tcard.h"

using namespace std;

int TCard::load( ifstream &ifs, vector<TPlayer*> &HomePlayer, vector<TPlayer*> &GuestPlayer )
{
    unsigned int i;
    string line;
    while(ifs.good())
    {
        line = TTools::ReadUnspaced(ifs);
        if ( TTools::strcontain( line,"</Card>" ) )
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
        else if( TTools::strcontain( line,"<Yellow>" ) )
        {
            #ifdef DEBUG
                cout << line << endl;
            #endif
            std::string tag1 = "<Yellow>",tag2 = "</Yellow>";
            line = TTools::tagremove(line, tag1);
            line = TTools::tagremove(line, tag2);
            if ( line == "true" )
            {
                yellow = true;

                if ( TEvent::GetPlayer() != NULL )
                {
                    /* add card to player account */
                    TEvent::GetPlayer()->SetNumberOfYellowCards( TEvent::GetPlayer()->GetNumberOfYellowCards() +1 );
                    #ifdef DEBUG
                        cout << TEvent::GetPlayer()->Getname() << " new number of yellow cards (TCard): " << TEvent::GetPlayer()->GetNumberOfYellowCards() << endl;
                    #endif
                }
            }
        }
        else if( TTools::strcontain( line,"<Red>" ) )
        {
            #ifdef DEBUG
                cout << line << endl;
            #endif
            std::string tag1 = "<Red>",tag2 = "</Red>";
            line = TTools::tagremove(line, tag1);
            line = TTools::tagremove(line, tag2);
            if ( line == "true" )
            {
                red = true;

                if ( TEvent::GetPlayer() != NULL )
                {
                    /* add card to player account */
                    TEvent::GetPlayer()->SetNumberOfYellowCards( TEvent::GetPlayer()->GetNumberOfYellowCards() +1 );
                    #ifdef DEBUG
                        cout << TEvent::GetPlayer()->Getname() << " new number of red cards (TCard): " << TEvent::GetPlayer()->GetNumberOfYellowCards() << endl;
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

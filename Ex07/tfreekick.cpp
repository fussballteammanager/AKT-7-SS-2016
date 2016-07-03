#include <iomanip>
#include <fstream>
#include <algorithm>

#include "ttools.h"
#include "tfreekick.h"


int TFreeKick::load( ifstream &ifs, vector<TPlayer*> &HomePlayer, vector<TPlayer*> &GuestPlayer )
{
    unsigned int i;
    string line;
    while(ifs.good())
    {
        line = TTools::ReadUnspaced(ifs);
        if ( TTools::strcontain( line,"</Freekick>" ) )
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
        else if( TTools::strcontain( line,"<Distance>" ) )
        {
            #ifdef DEBUG
                cout << line << endl;
            #endif
            std::string tag1 = "<Distance>",tag2 = "</Distance>";
            line = TTools::tagremove(line, tag1);
            line = TTools::tagremove(line, tag2);
            Distance =  atoi( line.c_str() );
        }
        else if (  TTools::strcontain(line,"PlayerTricotNr" ) )
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

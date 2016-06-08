#include <iostream>
#include <fstream>
#include <cstdlib>

#include "tmatch.h"
#include "ttools.h"
#include "ttournament.h"

//#include "tgoal.h"
//#include "tpenalty.h"
//#include "tfreekick.h"
//#include "tsubstitution.h"
//#include "tfoul.h"

using namespace std;

TMatch::TMatch()
{
    #ifdef DEBUG
        cout << "Constr: TMatch" << endl;
    #endif
    HomeTeam = NULL;
    GuestTeam = NULL;
    this->Score.setGoals(0,0);
    string Referee = "";
    Stadium = NULL;
}

TMatch::~TMatch()
{
    #ifdef DEBUG
        cout << "Destr: TMatch" << endl;
    #endif
}

void AddHomePlayer( TPlayer* HPlayer)
{

}

void AddGuestPlayer( TPlayer* GPlayer)
{

}

void SubstituteHomePlayer( TPlayer* exhaustedPlayer, TPlayer* replacementPlayer )
{

}

void SubstituteGuestPlayer( TPlayer* exhaustedPlayer, TPlayer* replacementPlayer )
{

}


int TMatch::load(std::ifstream &ifs, void* ptr ) // void pointer, so header does not need ttournament.h header
{
    int i;
    // cast pointer back from void*
    TTournament *Tournament = (TTournament*)ptr;

    string line;
    while(ifs.good())
    {
        line = TTools::ReadUnspaced(ifs);

        if ( TTools::strcontain( line, "</Match>" ) )
        {
            #ifdef DEBUG
                cout << line << endl;
            #endif
            return 1;
        }
        else if ( TTools::strcontain( line,"<Date>" ) )
        {
            #ifdef DEBUG
                cout << line << endl;
            #endif
            this->Date.load(ifs);
        }
        else if ( TTools::strcontain( line,"<Time>" ) )
        {
            #ifdef DEBUG
                cout << line << endl;
            #endif
            this->Time.load(ifs);
        }
        else if( TTools::strcontain( line,"<HomeTeam>" ) )
        {
            #ifdef DEBUG
                cout << line << endl;
            #endif
            string tag1 = "<HomeTeam>",tag2 = "</HomeTeam>";
            line = TTools::tagremove(line, tag1);
            line = TTools::tagremove(line, tag2);
            for ( i = 0; i < Tournament->GetNumberOfTeams(); i++ )
                if ( Tournament->GetTeam(i)->GetName() == line )
                {
                    cout << "found team equal: " << Tournament->GetTeam(i)->GetName() << " to " << line << endl;
                    this->HomeTeam = Tournament->GetTeam(i);
                    cout << "Home team pointer points to: " << this->HomeTeam->GetName() << endl;
                }

            /* Insert pointer to a team !!! */
           // this-> = line;
        }
        else if( TTools::strcontain( line,"<GuestTeam>" ) )
        {
            #ifdef DEBUG
                cout << line << endl;
            #endif
            string tag1 = "<GuestTeam>",tag2 = "</GuestTeam>";
            line = TTools::tagremove(line, tag1);
            line = TTools::tagremove(line, tag2);
            /* Insert pointer to a team !!! */
            //this->SetGuestTeam(line);
        }
        else if( TTools::strcontain( line,"<Stadium>" ) )
        {
            #ifdef DEBUG
                cout << line << endl;
            #endif
            string tag1 = "<Stadium>",tag2 = "</Stadium>";
            line = TTools::tagremove(line, tag1);
            line = TTools::tagremove(line, tag2);
            /* Insert pointer to a team !!! */
            //this->SetStadium(line);
        }
        else if( TTools::strcontain( line,"<Referee>" ) )
        {
            #ifdef DEBUG
                cout << line << endl;
            #endif
            std::string tag1 = "<Referee>",tag2 = "</Referee>";
            line = TTools::tagremove(line, tag1);
            line = TTools::tagremove(line, tag2);
            /* Insert pointer to a team !!! */
            this->SetReferee(line);
        }
        else if (  TTools::strcontain(line,"<PlayerTricotNr Team=\"Home\">" ) )
        {
            #ifdef DEBUG
                cout << line << endl;
            #endif
            std::string tag1 = "<PlayerTricotNr Team=\"Home\">",tag2 = "</PlayerTricotNr>";
            line = TTools::tagremove(line, tag1);
            line = TTools::tagremove(line, tag2);
            /* add correct player to vector :) push_back */
    //        HomePlayer.push_back()
            #ifdef DEBUG
                std::cout <<  atoi(line.c_str()) << std::endl;
            #endif // DEBUG
        }
        else if (  TTools::strcontain(line,"<PlayerTricotNr Team=\"Guest\">" ) )
        {
            #ifdef DEBUG
                cout << line << endl;
            #endif
            std::string tag1 = "<PlayerTricotNr Team=\"Guest\">",tag2 = "</PlayerTricotNr>";
            line = TTools::tagremove(line, tag1);
            line = TTools::tagremove(line, tag2);
            /* add correct player to vector :) push_back */
    //        HomePlayer.push_back()
            #ifdef DEBUG
                std::cout <<  atoi(line.c_str()) << std::endl;
            #endif // DEBUG
        }
            else if ( TTools::strcontain( line,"<Foul>" ) )
        {
            #ifdef DEBUG
                cout << line << endl;
            #endif
            //this->Events.push_back(new TFoul);
//            this->Events.at(Events.size()-1)->load(ifs);
            //this->Time.load(ifs);
        }
        else if ( TTools::strcontain( line,"<Freekick>" ) )
        {
            #ifdef DEBUG
                cout << line << endl;
            #endif
            //this->Time.load(ifs);
        }
        else if ( TTools::strcontain( line,"<Card>" ) )
        {
            #ifdef DEBUG
                cout << line << endl;
            #endif
            //this->Time.load(ifs);
        }
        else if ( TTools::strcontain( line,"<Substitution>" ) )
        {
            #ifdef DEBUG
                cout << line << endl;
            #endif
            //this->Time.load(ifs);
        }
        else if ( TTools::strcontain( line,"<Penalty>" ) )
        {
            #ifdef DEBUG
                cout << line << endl;
            #endif
            //this->Time.load(ifs);
        }
    }

    return 0;
}

void TMatch::print()
{
    cout << "TMatch print" << endl;
}

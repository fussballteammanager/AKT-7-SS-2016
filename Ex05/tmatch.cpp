#include <iostream>
#include <fstream>
#include <cstdlib>

#include "tmatch.h"
#include "ttools.h"

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


int TMatch::load(std::ifstream &ifs)
{
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
            std::string tag1 = "<HomeTeam>",tag2 = "</HomeTeam>";
            line = TTools::tagremove(line, tag1);
            line = TTools::tagremove(line, tag2);
            /* Insert pointer to a team !!! */
           // this-> = line;
        }
        /* insert pointer to teamnames */
        /* ... */

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
            std::cout <<  atoi(line.c_str()) << std::endl;
        }
//        else if ( TTools::strcontain( line,"<Foul>" ) )
//        {
//            #ifdef DEBUG
//                cout << line << endl;
//            #endif
//            this->Events.push_back(new TFoul);
//            this->Events.at(Events.size()-1)->load(ifs);
//        }

    /* continue with events !!! */

    }
    return 0;
}

void TMatch::print()
{
    cout << "TMatch print" << endl;
}

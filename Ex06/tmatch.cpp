#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstdlib>

#include "tmatch.h"
#include "ttools.h"
#include "ttournament.h"

#include "tgoal.h"
#include "tpenalty.h"
#include "tfreekick.h"
#include "tsubstitution.h"
#include "tfoul.h"
#include "tcard.h"


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

int TMatch::load(std::ifstream &ifs, TTeam **Team, TStadium **StadiumN )
{
    int i;

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

            for ( i = 0; *(Team+i) != NULL; i++ )
                if( (*(Team+i))->GetName() == line )
                {
                    HomeTeam = *(Team+i);
                    #ifdef DEBUG
                        cout << "HomeTeam in match: " << HomeTeam->GetName() << endl;
                    #endif
                    break;
                }
        }
        else if( TTools::strcontain( line,"<GuestTeam>" ) )
        {
            #ifdef DEBUG
                cout << line << endl;
            #endif
            string tag1 = "<GuestTeam>",tag2 = "</GuestTeam>";
            line = TTools::tagremove(line, tag1);
            line = TTools::tagremove(line, tag2);
            for ( i = 0; *(Team+i) != NULL; i++ )
                if( (*(Team+i))->GetName() == line )
                {
                    GuestTeam = *(Team+i);
                    #ifdef DEBUG
                        cout << "GuestTeam in match: " << GuestTeam->GetName() << endl;
                    #endif
                    break;
                }
        }
        else if( TTools::strcontain( line,"<Stadium>" ) )
        {
            #ifdef DEBUG
                cout << line << endl;
            #endif
            string tag1 = "<Stadium>",tag2 = "</Stadium>";
            line = TTools::tagremove(line, tag1);
            line = TTools::tagremove(line, tag2);
            for ( i = 0; *(StadiumN+i) != NULL; i++ )
                if( (*(StadiumN+i))->GetStName() == line )
                {
                    Stadium = *(StadiumN+i);
                    #ifdef DEBUG
                        cout << "Stadium entry in match: " << Stadium->GetStName() << endl;
                    #endif
                    break;
                }
        }
        else if( TTools::strcontain( line,"<Referee>" ) )
        {
            #ifdef DEBUG
                cout << line << endl;
            #endif
            std::string tag1 = "<Referee>",tag2 = "</Referee>";
            line = TTools::tagremove(line, tag1);
            line = TTools::tagremove(line, tag2);
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
            /* add correct player to vector, check tricot numbers :) push_back */
            for ( i = 0; HomeTeam->GetPlayer(i) != NULL; i++ )
                if( HomeTeam->GetPlayer(i)->GettricotNr() == atoi(line.c_str()) )
                {
                    HomePlayer.push_back( HomeTeam->GetPlayer(i) );
                    #ifdef DEBUG
                        cout << "Added player to home team: "<< HomeTeam->GetName() << " Nr.: " << HomePlayer.at( HomePlayer.size()-1 )->GettricotNr()
                            << " " << HomePlayer.at( HomePlayer.size()-1 )->Getname() <<  endl;
                    #endif
                    break;
                }
        }
        else if (  TTools::strcontain(line,"<PlayerTricotNr Team=\"Guest\">" ) )
        {
            #ifdef DEBUG
                cout << line << endl;
            #endif
            std::string tag1 = "<PlayerTricotNr Team=\"Guest\">",tag2 = "</PlayerTricotNr>";
            line = TTools::tagremove(line, tag1);
            line = TTools::tagremove(line, tag2);
            /* add correct player to vector, check tricot numbers :) push_back */
            for ( i = 0; GuestTeam->GetPlayer(i) != NULL; i++ )
                if( GuestTeam->GetPlayer(i)->GettricotNr() == atoi(line.c_str()) )
                {
                    GuestPlayer.push_back( GuestTeam->GetPlayer(i) );
                    #ifdef DEBUG
                        cout << "Added player to guest team: "<< GuestTeam->GetName() << " Nr.: " << GuestPlayer.at( GuestPlayer.size()-1 )->GettricotNr()
                            << " " << GuestPlayer.at( GuestPlayer.size()-1 )->Getname() <<  endl;
                    #endif
                    break;
                }
        }
        else if ( TTools::strcontain( line,"<Foul>" ) )
        {
            #ifdef DEBUG
                cout << line << endl;
            #endif
            this->Events.push_back(new TFoul);
            this->Events.at( Events.size()-1 )->load(ifs, HomePlayer, GuestPlayer );
        }
        else if ( TTools::strcontain( line,"<Freekick>" ) )
        {
            #ifdef DEBUG
                cout << line << endl;
            #endif
            this->Events.push_back(new TFreeKick);
            this->Events.at( Events.size()-1 )->load(ifs, HomePlayer, GuestPlayer );
        }
        else if ( TTools::strcontain( line,"<Card>" ) )
        {
            #ifdef DEBUG
                cout << line << endl;
            #endif
            this->Events.push_back(new TCard);
            this->Events.at( Events.size()-1 )->load(ifs, HomePlayer, GuestPlayer );
        }
        else if ( TTools::strcontain( line,"<Substitution>" ) )
        {
            #ifdef DEBUG
                cout << line << endl;
            #endif
            this->Events.push_back(new TSubstitution);
            this->Events.at( Events.size()-1 )->load(ifs, HomePlayer, GuestPlayer, HomeTeam, GuestTeam);
        }
        else if ( TTools::strcontain( line,"<Penalty>" ) )
        {
            #ifdef DEBUG
                cout << line << endl;
            #endif
            this->Events.push_back(new TPenalty);
            this->Events.at( Events.size()-1 )->load(ifs, HomePlayer, GuestPlayer );
        }
        else if ( TTools::strcontain( line,"<Goal>" ) )
        {
            #ifdef DEBUG
                cout << line << endl;
            #endif
            this->Events.push_back(new TGoal);
            this->Events.at( Events.size()-1 )->load(ifs, HomePlayer, GuestPlayer, Score);
        }
    }

    return 0;
}


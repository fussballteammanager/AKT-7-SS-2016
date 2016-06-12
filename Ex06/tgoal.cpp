#include <iomanip>
#include <iostream>
#include <fstream>
#include <algorithm>

#include "ttools.h"
#include "tgoal.h"


void TGoal::print()
{
    if ( TEvent::GetPlayer() == 0 )
        cout << "Kein Spielername vorhanden für Torschuss!" << endl;
    else if ( GetPlayer() == 0 && Owngoal == false )
    {
        /* not an owngoal */
        cout.setf(ios::right, ios::adjustfield);
        cout << "TOR!!! Torschuetze: "
            << TEvent::GetPlayer()->Getname() << endl;
    }
    else if ( GetPlayer() == 0 && Owngoal == true )
    {
        /* owngoal */
        cout.setf(ios::right, ios::adjustfield);
        cout << "EIGENTOR!!! Torschuetze: "
            << TEvent::GetPlayer()->Getname() << endl;
    }
    else if ( GetPlayer() != 0 && Owngoal == false )
    {
        /* not an own goal, but with pass  */
        cout.setf(ios::right, ios::adjustfield);
        cout << "TOR!!! Torschuetze: "
            << TEvent::GetPlayer()->Getname() << endl;
        cout << "\t\t (Vorlage: " << PassPlayer->Getname() << " )" << endl;
    }
    else /* pass and owngoal :) */
    {
        /* not an own goal, but with pass  */
        cout.setf(ios::right, ios::adjustfield);
        cout << "EIGENTOR!!! Torschuetze: "
            << TEvent::GetPlayer()->Getname() << endl;
        cout << "\t\t (Vorlage: " << PassPlayer->Getname() << " )" << endl;
    }
}

int TGoal::load( ifstream &ifs, vector<TPlayer*> &HomePlayer, vector<TPlayer*> &GuestPlayer, TScore &Score )
{
    unsigned int i;
    string line;
    while(ifs.good())
    {
        line = TTools::ReadUnspaced(ifs);
        if ( TTools::strcontain( line,"</Goal>" ) )
        {
            /* time to add goal to Score of Match */
            if ( TEvent::GetPlayer() == NULL )
            {
                cout << "No player added to goal!" << endl;
                return 1;
            }

            int playerGuest = 0;
            /* Search if player is home or guest ! */
            for ( i = 0; i < HomePlayer.size(); i++ )
            {
                if ( HomePlayer.at(i)->GettricotNr() == TEvent::GetPlayer()->GettricotNr() )
                {
                    playerGuest = 0;
                    break;
                }
                else if ( GuestPlayer.at(i)->GettricotNr() == TEvent::GetPlayer()->GettricotNr() )
                {
                    playerGuest = 1;
                    break;
                }
             }

            int GoalHome  = Score.getGoalsHome();
            int GoalGuest = Score.getGoalsGuest();

            if (      Owngoal == true  && playerGuest == 0 ) // owngoal of home player
                Score.setGoals( GoalHome,   GoalGuest+1 );
            else if ( Owngoal == false && playerGuest == 0 ) // goal of home player
                Score.setGoals( GoalHome+1, GoalGuest );
            else if ( Owngoal == true  && playerGuest == 1 ) // owngoal of guest player
                Score.setGoals( GoalHome+1, GoalGuest );
            else if ( Owngoal == false && playerGuest == 1 ) // goal of guest player
                Score.setGoals( GoalHome,   GoalGuest+1 );

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
        else if( TTools::strcontain( line,"<OwnGoal>" ) )
        {
            #ifdef DEBUG
                cout << line << endl;
            #endif
            std::string tag1 = "<OwnGoal>",tag2 = "</OwnGoal>";
            line = TTools::tagremove(line, tag1);
            line = TTools::tagremove(line, tag2);

            if ( line == "true" )
            {
                Owngoal = true;
            }

            if ( TEvent::GetPlayer() != NULL )
            {
                /* add card to player account */
                #ifdef DEBUG
                    string SGoal = Owngoal?"an owngoal.":"a goal.";
                    cout << TEvent::GetPlayer()->Getname() << " made " <<  SGoal << endl;
                #endif
            }
        }
        else if ( TTools::strcontain(line,"PlayerTricotNr" ) )
        {
                      #ifdef DEBUG
                cout << line << endl;
            #endif
            vector<TPlayer*> Player = GuestPlayer;
            string S_Team = "Guest"; /* "Guest" or "Home" */
            string S_Pass = ""; /* Pass or "" */
            if  (  TTools::strcontain(line,"PlayerTricotNr Team=\"Home\">" ) ) /* Home: TFoul or TEvent player */
            {
                Player = HomePlayer;
                S_Team = "Home";
            }

            if ( TTools::strcontain(line,"<PassPlayerTricotNr Team=" ) )
                S_Pass = "Pass";

            std::string tag1 = "<"+S_Pass+"PlayerTricotNr Team=\""+S_Team+"\">",tag2 = "</"+S_Pass+"PlayerTricotNr>";
            //cout << "Reconstructed Tag1: " << tag1 << endl;
            line = TTools::tagremove(line, tag1);
            line = TTools::tagremove(line, tag2);
            /* add correct player to vector, check tricot numbers :) push_back */
            for ( i = 0; i < Player.size(); i++ )
                if( Player.at(i)->GettricotNr() == atoi(line.c_str()) )
                {
                    if ( S_Pass == "Pass" )
                    {
                        PassPlayer = Player.at(i);
                        #ifdef DEBUG
                            cout << "Added " << S_Team << " pass player to TGoal: "<< PassPlayer->Getname() << " Nr.: " << PassPlayer->GettricotNr() << endl;
                        #endif
                    }
                    else
                    {
                        TEvent::SetPlayer( Player.at(i) );
                        #ifdef DEBUG
                            cout << "Added " << S_Team << " player to TEvent from TGoal: "<< TEvent::GetPlayer()->Getname() << " Nr.: " << TEvent::GetPlayer()->GettricotNr() << endl;
                        #endif
                    }
                    break;
                 }
        }
    }
    return 0;
}

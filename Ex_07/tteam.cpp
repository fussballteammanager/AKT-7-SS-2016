#include <iomanip>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdio>

#include "tteam.h"
#include "ttools.h"

using namespace std;

TTeam::TTeam()
{
    this->name = "";
    this->trainer = "";
    this->NumberOfGames = 0;
    this->Goals.setGoals(0,0);
    this->NumberOfPoints = 0;
    this->NumberOfPlayers = 0;
    for (int i = 0; i < MAXPLAYER; i++){
        Players[i] = NULL;
    }
}

TTeam::TTeam(string name, string trainer)
{
    this->name = name;
    this->trainer = trainer;
    this->NumberOfGames = 0;
    this->Goals.setGoals(0,0);
    this->NumberOfPoints = 0;
    this->NumberOfPlayers = 0;
    for (int i = 0; i < MAXPLAYER; i++){
        Players[i] = NULL;
    }
}

TTeam::~TTeam()
{
    #ifdef DEBUG
        cout << "Destr: TTeam" << endl;
    #endif
    for ( int i = 0; i < NumberOfPlayers; i++ )
        delete this->Players[i];
}

bool TTeam::addPlayer(TPlayer Player)
{
    if ( NumberOfPlayers < MAXPLAYER )
    {
        Players[NumberOfPlayers] = new TPlayer;
         /* copy player class object into space of TPlayer */
        *Players[NumberOfPlayers] = Player;
        NumberOfPlayers++;
        return true;
    }
    else
        std::cout << "Team reached maximum of " << MAXPLAYER
            << "players. Kick one out before adding a new :) " << std::endl;

    return false;
}

bool TTeam::removePlayer(TPlayer &Player)
{
    for (int i = 0; i < NumberOfPlayers; i++){
        if ( this->Players[i]->Getname() == Player.Getname() )
        {
            delete this->Players[i];
             /* replace with last in list */
            this->Players[i] = this->Players[NumberOfPlayers-1];
            this->Players[NumberOfPlayers-1] = NULL;
            NumberOfPlayers--;
            return true;
        }
    }
    return false;
}

void TTeam::print()
{
    cout << this->GetName() << endl;
    cout << "Trainer: " << this->Gettrainer() << endl << endl;

    if ( NumberOfPlayers == 0 )
        cout << "Keine Spieler!" << endl;
    else
    {
        cout << "Spieler                 | Nr | Spiele | Tore | Vorl. | Gelb |  Rot | Geburtstag" << endl;
        cout << "------------------------|----|--------|------|-------|------|------|-----------" << endl;
        for (int i = 0; i < NumberOfPlayers; i++)
            Players[i]->print();
        cout << "------------------------|----|--------|------|-------|------|------|-----------" << endl << endl;
    }
}

int TTeam::load(std::ifstream &ifs)
{
    string line;
    while(ifs.good())
    {
        line = TTools::ReadUnspaced(ifs);

        if ( TTools::strcontain( line,"</Team>") )
        {
            #ifdef DEBUG
                cout << line << endl;
            #endif
            return 1;
        }
        else if ( TTools::strcontain( line,"<Player>" ) )
        {
            #ifdef DEBUG
                cout << line << endl;
            #endif
            this->Players[NumberOfPlayers] = new TPlayer;
            this->Players[NumberOfPlayers]->load(ifs);
            NumberOfPlayers++;
            #ifdef DEBUG
                cout << "Team: " << this->name << "Number player: "
                    << NumberOfPlayers << endl;
            #endif

        }
        else if( TTools::strcontain( line,"<Name>" ) )
        {
            #ifdef DEBUG
                cout << line << endl;
            #endif
            std::string tag1 = "<Name>",tag2 = "</Name>";
            line = TTools::tagremove(line, tag1);
            line = TTools::tagremove(line, tag2);
            this->name = line;
        }
        else if( TTools::strcontain( line,"<Trainer>" ) )
        {
            #ifdef DEBUG
                cout << line << endl;
            #endif
            std::string tag1 = "<Trainer>",tag2 = "</Trainer>";
            line = TTools::tagremove(line, tag1);
            line = TTools::tagremove(line, tag2);
            this->trainer = line;
        }

    }
    return 0;
}


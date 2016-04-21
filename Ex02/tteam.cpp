#include <iostream>
#include <iomanip>
#include "tteam.h"

using namespace std;

int TTeam::NumberOfPlayers = 0;

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
    for (int i = 0; i < MAXPLAYER; i++){
        delete this->Players[i];
    }
}

bool TTeam::addPlayer(TPlayer Player)
{
    bool ret = false;
    for (int i = 0; i < MAXPLAYER-1; i++){
        if (Players[i] == NULL){
            Players[i] = new TPlayer;
            *Players[i] = Player;
            ret = true;
            break;
        }
    }
    if (ret){
        NumberOfPlayers++;
    }
    return ret;
}

bool TTeam::removePlayer(TPlayer &Player)
{
    for (int i = 0; i < MAXPLAYER; i++){
        if (this->Players[i] != NULL){
            if (this->Players[i]->Getname() == Player.Getname()){
                delete this->Players[i];
                this->Players[i] = NULL;
                NumberOfPlayers--;
            }
            else
                return false;
        }
    }
    return true;
}

void TTeam::print()
{
    int j = 1;
    cout << this->Getname() << endl << this->Gettrainer() << endl << endl;

    for (int i = 0; i < MAXPLAYER; i++){
        //cout << i << "=i ";
        if (Players[i] != NULL){
            j++;

        }
    //cout << j << "=j ";
    }

    if (j == 1){
        cout << "Keine Spieler!" << endl;
    }else{
        cout << "Spieler                 | Nr | Spiele | Tore | Vorl. | Gelb |  Rot | Geburtstag" << endl;
        cout << "------------------------|----|--------|------|-------|------|------|-----------" << endl;
        for (int i = 0; i < MAXPLAYER; i++){
            if (Players[i] != NULL){
                cout.setf(ios::left, ios::adjustfield);
                cout << setw(23) << setfill(' ') << Players[i]->Getname();
                cout.setf(ios::right, ios::adjustfield);
                cout << " | " << setw(2) << Players[i]->GettricotNr()
                << " | " << setw(6) << Players[i]->GetNumberOfGames()
                << " | " << setw(4) << Players[i]->GetNumberOfGoals()
                << " | " << setw(5) << Players[i]->GetNumberOfPasses()
                << " | " << setw(4) << Players[i]->GetNumberOfYellowCards()
                << " | " << setw(4) << Players[i]->GetNumberOfRedCards()
                << " | " << setw(2) << setfill('0') << Players[i]->GetBirthday().getDay()
                << "." << setw(2) << Players[i]->GetBirthday().getMonth()
                << "."<<  setw(4) << Players[i]->GetBirthday().getYear()
                << setfill(' ') << endl;
            }
        }
    }
}

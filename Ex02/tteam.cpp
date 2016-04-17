#include <iostream>
#include <iomanip>
#include "TDate.h"
#include "TTime.h"
#include "TScore.h"
#include "TPlayer.h"
#include "TTeam.h"
using namespace std;



TTeam::TTeam(string name, string trainer)
{
    this->name = name;
    this->trainer = trainer;
    this->NumberOfGames = 0;
    this->Goals.setGoals(0,0);
    this->NumberOfPoints = 0;
    this->NumberOfPlayers = 0;
    for (int i = 0; i < MAXPLAYER-1; i++){
        Players[i] = NULL;
    }
}

TTeam::~TTeam()
{
    for (int i = 0; i < MAXPLAYER; i++){
        delete this->Players[i];
    }
}

bool TTeam::addPlayer(TPlayer Player){
    bool rturn = false;
    for (int i = 0; i < MAXPLAYER-1; i++){
        if (Players[i] == NULL){
            Players[i] = new TPlayer;
            *Players[i] = Player;
            rturn = true;
            break;
        }
    }


    return rturn;
}

bool TTeam::removePlayer(TPlayer &Player){
    bool rturn = false;
    for (int i = 0; i < MAXPLAYER; i++){
        if (this->Players[i] != NULL){
            if (this->Players[i]->Getname() == Player.Getname()){
                delete this->Players[i];
                this->Players[i] = NULL;
            }
        }
    }
    return rturn;
}

void TTeam::print(){
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
                cout.setf(std::ios::left, std::ios::adjustfield);
                cout << std::setw(23) << std::setfill(' ') << Players[i]->Getname();
                cout.setf(std::ios::right, std::ios::adjustfield);
                cout << " | " << std::setw(2) << std::setfill(' ') << Players[i]->GettricotNr()
                << " | " << std::setw(6) << std::setfill(' ') << Players[i]->GetNumberOfGames()
                << " | " << std::setw(4) << std::setfill(' ') << Players[i]->GetNumberOfGoals()
                << " | " << std::setw(5) << std::setfill(' ') << Players[i]->GetNumberOfPasses()
                << " | " << std::setw(4) << std::setfill(' ') << Players[i]->GetNumberOfYellowCards()
                << " | " << std::setw(4) << std::setfill(' ') << Players[i]->GetNumberOfRedCards()
                << " | " << std::setw(2) << std::setfill('0') << Players[i]->GetBirthday().getDay()
                << "." << std::setw(2) << std::setfill('0') << Players[i]->GetBirthday().getMonth()
                << "."<<  std::setw(4) << std::setfill('0') << Players[i]->GetBirthday().getYear()
                << endl;
            }
        }
    }
}

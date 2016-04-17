#include <iostream>
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
    //dtor
}

bool TTeam::addPlayer(TPlayer Player){
    bool rturn = false;
    for (int i = 0; i < MAXPLAYER-1; i++){
        if (Players[i] == NULL){
            Players[i] = new TPlayer;
            Players[i] = &Player;
            rturn = true;
            break;
        }
    }


    return rturn;
}

bool TTeam::removePlayer(TPlayer Player){
    bool rturn = false;

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
        cout << "Spieler          | Nr | Spiele | Tore | Vorl. | Gelb |  Rot | Geburtstag" << endl;
        cout << "________________________________________________________________________" << endl;
        for (int i = 0; i < MAXPLAYER; i++){
            if (Players[i] != NULL){
                cout << Players[i]->Getname() << " | " << Players[i]->GettricotNr() << " | " << Players[i]->GetNumberOfGames() << " | " << Players[i]->GetNumberOfGoals()  << " | " <<
                        Players[i]->GetNumberOfPasses()  << " | " << Players[i]->GetNumberOfYellowCards()  << " | " << Players[i]->GetNumberOfRedCards() <<
                        " | " << Players[i]->GetBirthday().getDay() << "."<<Players[i]->GetBirthday().getMonth() << "."<< Players[i]->GetBirthday().getYear() << endl;
            }
        }
    }
}

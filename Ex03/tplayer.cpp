#include <iostream>
#include "tplayer.h"

using namespace std;


TPlayer::TPlayer()
{
    this->name = "";
    this->position = "";
    this->tricotNr = 0;
    this->Birthday.setDate(0,0,0);
    this->NumberOfGames = 0;
    this->NumberOfPasses = 0;
    this->NumberOfGoals = 0;
    this->NumberOfYellowCards = 0;
    this->NumberOfRedCards = 0;
}

TPlayer::TPlayer(string name, string position, short tricotNr, unsigned int NumberOfGoals,
    unsigned int NumberOfPasses, unsigned int NumberOfGames, unsigned int NumberOfYellowCards,
    unsigned int NumberOfRedCards, unsigned int Day, unsigned int Month, unsigned int Year)
{
    this->name = name;
    this->position = position;
    this->tricotNr = tricotNr;
    this->Birthday.setDate(Day, Month, Year);
    this->NumberOfGames = NumberOfGames;
    this->NumberOfPasses = NumberOfPasses;
    this->NumberOfGoals = NumberOfGoals;
    this->NumberOfYellowCards = NumberOfYellowCards;
    this->NumberOfRedCards = NumberOfRedCards;
}

TPlayer::~TPlayer()
{
    //dtor
}

void TPlayer::print(){
    cout << this->Getname() << " (Trikot-Nr. " << this->GettricotNr() << ")";
}

int TPlayer::load(string line)
{
    cout << "found Player Tag: " << line << endl;
    return 0;
}

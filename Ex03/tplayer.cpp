#include <iostream>
#include <fstream>
#include <algorithm>

#include "tplayer.h"
#include "ttools.h"

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

int TPlayer::load(std::ifstream &ifs)
{
    string line;
    while(ifs.good())
    {
        line = TTools::ReadUnspaced(ifs);
        if (line == "</Player>")
        {
            return 1;
        }else if (line == "<Birthday>")
        {
            this->Birthday.load(ifs);
        }else if(TTools::strcontain(line,"<Name>"))
        {
            std::string tag1 = "<Name>",tag2 = "</Name>";
            line = TTools::tagremove(line, tag1);
            line = TTools::tagremove(line, tag2);
            this->name = line;
        }else if(TTools::strcontain(line,"<Position>"))
        {
            std::string tag1 = "<Position>",tag2 = "</Position>";
            line = TTools::tagremove(line, tag1);
            line = TTools::tagremove(line, tag2);
            this->position = line;
        }else if(TTools::strcontain(line,"<TricotNr>"))
        {
            std::string tag1 = "<TricotNr>",tag2 = "</TricotNr>";
            line = TTools::tagremove(line, tag1);
            line = TTools::tagremove(line, tag2);
            this->tricotNr = atoi(line.c_str());
        }else if(TTools::strcontain(line,"<NumberOfGames>"))
        {
            std::string tag1 = "<NumberOfGames>",tag2 = "</NumberOfGames>";
            line = TTools::tagremove(line, tag1);
            line = TTools::tagremove(line, tag2);
            this->NumberOfGames = atoi(line.c_str());
        }else if(TTools::strcontain(line,"<NumberOfYellowCards>"))
        {
            std::string tag1 = "<NumberOfYellowCards>",tag2 = "</NumberOfYellowCards>";
            line = TTools::tagremove(line, tag1);
            line = TTools::tagremove(line, tag2);
            this->NumberOfYellowCards = atoi(line.c_str());
        }else if(TTools::strcontain(line,"<NumberOfRedCards>"))
        {
            std::string tag1 = "<NumberOfRedCards>",tag2 = "</NumberOfRedCards>";
            line = TTools::tagremove(line, tag1);
            line = TTools::tagremove(line, tag2);
            this->NumberOfRedCards = atoi(line.c_str());
        }else if(TTools::strcontain(line,"<NumberOfGoals>"))
        {
            std::string tag1 = "<NumberOfGoals>",tag2 = "</NumberOfGoals>";
            line = TTools::tagremove(line, tag1);
            line = TTools::tagremove(line, tag2);
            this->NumberOfGoals = atoi(line.c_str());
        }else if(TTools::strcontain(line,"<NumberOfPasses>"))
        {
            std::string tag1 = "<NumberOfPasses>",tag2 = "</NumberOfPasses>";
            line = TTools::tagremove(line, tag1);
            line = TTools::tagremove(line, tag2);
            this->NumberOfPasses = atoi(line.c_str());
        }
    }
    return 0;
}

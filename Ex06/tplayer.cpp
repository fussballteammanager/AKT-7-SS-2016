#include <iomanip>
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
    #ifdef DEBUG
        cout << "Destr: TPlayer" << endl;
    #endif
}

void TPlayer::print()
{
    cout.setf(ios::left, ios::adjustfield);
    cout << setw(23) << setfill(' ') << *this;
    //or:
    //operator<< (cout, *this);

    cout.setf(ios::right, ios::adjustfield);
    cout << " | " << setw(2) << tricotNr
         << " | " << setw(6) << NumberOfGames
         << " | " << setw(4) << NumberOfGoals
         << " | " << setw(5) << NumberOfPasses
         << " | " << setw(4) << NumberOfYellowCards
         << " | " << setw(4) << NumberOfRedCards
         << " | ";
    GetBirthday().print();
    cout  << setfill(' ') << endl;
}

int TPlayer::load(std::ifstream &ifs)
{
    string line;
    while(ifs.good())
    {
        line = TTools::ReadUnspaced(ifs);
        if ( TTools::strcontain( line,"</Player>" ) )
        {
            #ifdef DEBUG
                cout << line << endl;
            #endif
            return 1;
        }
        else if ( TTools::strcontain( line,"<Birthday>" ) )
        {
            #ifdef DEBUG
                cout << line << endl;
            #endif
            this->Birthday.load(ifs);
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
        else if( TTools::strcontain( line,"<Position>" ) )
        {
            #ifdef DEBUG
                cout << line << endl;
            #endif
            std::string tag1 = "<Position>",tag2 = "</Position>";
            line = TTools::tagremove(line, tag1);
            line = TTools::tagremove(line, tag2);
            this->position = line;
        }
        else if( TTools::strcontain( line,"<TricotNr>" ) )
        {
            #ifdef DEBUG
                cout << line << endl;
            #endif
            std::string tag1 = "<TricotNr>",tag2 = "</TricotNr>";
            line = TTools::tagremove(line, tag1);
            line = TTools::tagremove(line, tag2);
            this->tricotNr = atoi(line.c_str());
        }
        else if( TTools::strcontain( line,"<NumberOfGames>" ) )
        {
            #ifdef DEBUG
                cout << line << endl;
            #endif
            std::string tag1 = "<NumberOfGames>",tag2 = "</NumberOfGames>";
            line = TTools::tagremove(line, tag1);
            line = TTools::tagremove(line, tag2);
            this->NumberOfGames = atoi(line.c_str());
        }
        else if( TTools::strcontain( line,"<NumberOfYellowCards>" ) )
        {
            #ifdef DEBUG
                cout << line << endl;
            #endif
            std::string tag1 = "<NumberOfYellowCards>",tag2 = "</NumberOfYellowCards>";
            line = TTools::tagremove(line, tag1);
            line = TTools::tagremove(line, tag2);
            this->NumberOfYellowCards = atoi(line.c_str());
        }
        else if( TTools::strcontain( line,"<NumberOfRedCards>" ) )
        {
            #ifdef DEBUG
                cout << line << endl;
            #endif
            std::string tag1 = "<NumberOfRedCards>",tag2 = "</NumberOfRedCards>";
            line = TTools::tagremove(line, tag1);
            line = TTools::tagremove(line, tag2);
            this->NumberOfRedCards = atoi(line.c_str());
        }
        else if(TTools::strcontain( line,"<NumberOfGoals>" ) )
        {
            #ifdef DEBUG
                cout << line << endl;
            #endif
            std::string tag1 = "<NumberOfGoals>",tag2 = "</NumberOfGoals>";
            line = TTools::tagremove(line, tag1);
            line = TTools::tagremove(line, tag2);
            this->NumberOfGoals = atoi(line.c_str());
        }
        else if( TTools::strcontain( line,"<NumberOfPasses>" ) )
        {
            #ifdef DEBUG
                cout << line << endl;
            #endif
            std::string tag1 = "<NumberOfPasses>",tag2 = "</NumberOfPasses>";
            line = TTools::tagremove(line, tag1);
            line = TTools::tagremove(line, tag2);
            this->NumberOfPasses = atoi(line.c_str());
        }
    }
    return 0;
}

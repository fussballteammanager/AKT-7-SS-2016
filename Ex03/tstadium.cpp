#include "tstadium.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include "tdate.h"
#include "tteam.h"
#include "tplayer.h"
#include "tstadium.h"
#include "ttournament.h"
using namespace std;

TStadium::TStadium()
{
    this->StName = "dummy";
    this->Town = "dummy";
    this->Country = "dummy";
    this->NumberOfSeats = 0;
    this->YearOfConstruction = 0;
}

TStadium::TStadium(string name, string town, string country, int seats, int year)
{
    this->StName = name;
    this->Town = town;
    this->Country = country;
    this->NumberOfSeats = seats;
    this->YearOfConstruction = year;
}

TStadium::~TStadium()
{
    //dtor
}

int TStadium::load(std::ifstream &ifs)
{
    string line;
    while(ifs.good())
    {
        line = TTournament::ReadUnspaced(ifs);
        //getline(ifs,line);
        //line.erase(std::remove( line.begin(), line.end(), ' ' ), line.end() );
        if (line == "</Stadium>")
        {
            return 1;
        }else if(TTournament::strcontain(line,"<Name>"))
        {

            std::string tag1 = "<Name>",tag2 = "</Name>";
            line = TTournament::tagremove(line, tag1);
            line = TTournament::tagremove(line, tag2);
            this->StName = line;
            //cout << this->StName << " ";
        }else if(TTournament::strcontain(line,"<Town>"))
        {
            std::string tag1 = "<Town>",tag2 = "</Town>";
            line = TTournament::tagremove(line, tag1);
            line = TTournament::tagremove(line, tag2);
            this->Town = line;
            //cout << this->Town << " ";
        }else if(TTournament::strcontain(line,"<Country>"))
        {
            std::string tag1 = "<Country>",tag2 = "</Country>";
            line = TTournament::tagremove(line, tag1);
            line = TTournament::tagremove(line, tag2);
            this->Country = line;
            //cout << this->Country << " ";
        }else if(TTournament::strcontain(line,"<NumberOfSeats>"))
        {
            std::string tag1 = "<NumberOfSeats>",tag2 = "</NumberOfSeats>";
            line = TTournament::tagremove(line, tag1);
            line = TTournament::tagremove(line, tag2);
            this->NumberOfSeats = atoi(line.c_str());
            //cout << this->NumberOfSeats << " ";
        }else if(TTournament::strcontain(line,"<YearOfConstruction>"))
        {
            std::string tag1 = "<YearOfConstruction>",tag2 = "</YearOfConstruction>";
            line = TTournament::tagremove(line, tag1);
            line = TTournament::tagremove(line, tag2);
            this->YearOfConstruction = atoi(line.c_str());
            //cout << this->YearOfConstruction << " " << endl;
        }
    }
    return 0;
}

void TStadium::print()
{
    cout << "- " << this->StName << " (" << this->NumberOfSeats << " Sitzplaetze) in " << this->Town << "; " << this->Country << endl;
}


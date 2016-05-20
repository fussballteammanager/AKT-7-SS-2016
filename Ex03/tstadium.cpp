#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>

#include "tstadium.h"
#include "ttools.h"

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
        line = TTools::ReadUnspaced(ifs);
        if (line == "</Stadium>")
        {
            return 1;
        }else if(TTools::strcontain(line,"<Name>"))
        {

            std::string tag1 = "<Name>",tag2 = "</Name>";
            line = TTools::tagremove(line, tag1);
            line = TTools::tagremove(line, tag2);
            this->StName = line;
        }else if(TTools::strcontain(line,"<Town>"))
        {
            std::string tag1 = "<Town>",tag2 = "</Town>";
            line = TTools::tagremove(line, tag1);
            line = TTools::tagremove(line, tag2);
            this->Town = line;
        }else if(TTools::strcontain(line,"<Country>"))
        {
            std::string tag1 = "<Country>",tag2 = "</Country>";
            line = TTools::tagremove(line, tag1);
            line = TTools::tagremove(line, tag2);
            this->Country = line;
        }else if(TTools::strcontain(line,"<NumberOfSeats>"))
        {
            std::string tag1 = "<NumberOfSeats>",tag2 = "</NumberOfSeats>";
            line = TTools::tagremove(line, tag1);
            line = TTools::tagremove(line, tag2);
            this->NumberOfSeats = atoi(line.c_str());
        }else if(TTools::strcontain(line,"<YearOfConstruction>"))
        {
            std::string tag1 = "<YearOfConstruction>",tag2 = "</YearOfConstruction>";
            line = TTools::tagremove(line, tag1);
            line = TTools::tagremove(line, tag2);
            this->YearOfConstruction = atoi(line.c_str());
        }
    }
    return 0;
}

void TStadium::print()
{
    cout << "- " << this->StName << " (" << this->NumberOfSeats << " Sitzplaetze) in " << this->Town << "; " << this->Country << endl;
}


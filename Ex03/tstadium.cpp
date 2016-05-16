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
    //ctor
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
        //line = TTournament.ReadUnspaced(ifs);
        getline(ifs,line);
        line.erase(std::remove( line.begin(), line.end(), ' ' ), line.end() );
        if (line == "</Stadium>")
        {
            return 1;
        }
    }
    return 0;
}

void TStadium::print()
{
    cout << "- " << this->StName << " (" << this->NumberOfSeats << " Sitzplaetze) in " << this->Town << "; " << this->Country << endl;
}

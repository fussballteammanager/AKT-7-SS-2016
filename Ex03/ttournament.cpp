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

TTournament::TTournament(string DName)
{
    NumberOfTeams = 0;
    std::ifstream ifs, &r_ifs = ifs;
    ifs.open(DName.c_str(), std::ifstream::in);
    if(!ifs.is_open())
    {
        cout << "Keine Datei...!" << endl;
    }else{
        cout << "Datei offen...!" << endl;
        load(r_ifs);
    }
    ifs.close();
    if(!ifs.is_open())
    {
        cout << "Datei geschlossen...!" << endl << endl;
    }

}

TTournament::~TTournament()
{
    //dtor
}

void TTournament::print()
{
    cout << "Turnier: " << TName << endl << endl << "Stadien:" << endl;
    for(int i = 0; i < this->NumberOfStadiums; i++)
    {
        this->Stadium[i]->print();
    }

}

int TTournament::load(std::ifstream &ifs)
{
    cout << "Lese aus Datei...!" << endl;
    string line = ReadUnspaced(ifs);
    if (line == "<Tournament>")
    {
        while(ifs.good())
        {

            line = ReadUnspaced(ifs);
            if (line == "<Team>")
            {
                this->Team[NumberOfTeams]->load(ifs);
            }else if (line == "<Stadium>")
            {
                this->Stadium[NumberOfStadiums]->load(ifs);
            }else if (line == "</Tournament>")
            {
                return 1;
            }else
            {
                std::string tag1 = "<Name>",tag2 = "</Name>";
                line = tagremove(line, tag1);
                line = tagremove(line, tag2);
                this->TName = line;
                //cout << line << endl;
            }
        }
    }
    return 0;
}

bool TTournament::strcontain(std::string in, std::string tag)
{
    if (in.find(tag) != std::string::npos)
    {
        return true;
    }else
    {
        return false;
    }
}

string TTournament::tagremove(std::string in, std::string tag)
{
    std::string::size_type i = in.find(tag);
    if (i != std::string::npos)
    {
        in.erase(i, tag.length());
    }
    return in;
}

string TTournament::ReadUnspaced(std::ifstream &in)
{
    std::string line;
    getline(in,line);
    line.erase(std::remove( line.begin(), line.end(), ' ' ), line.end() );
    return line;
}

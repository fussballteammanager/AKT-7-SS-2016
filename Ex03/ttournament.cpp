#include <string>
#include <iostream>
#include <iomanip>
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
    NumberOfStadiums = 0;
    NumberOfMatches = 0;
    /*
    for(int i = 0; i < MAXSTADIUMS; i++)
    {
        TStadium newStadium("dummy","dummy","dummy",0,0);
        Stadium[i] = &newStadium;
    }
    */
    std::ifstream ifs, &r_ifs = ifs;
    ifs.open(DName.c_str(), std::ifstream::in);
    if(!ifs.is_open())
    {
        cout << "Keine Datei...!" << endl;
    }else{
        //cout << "Datei offen...!" << endl;
        load(r_ifs);
    }
    ifs.close();
    if(!ifs.is_open())
    {
        //cout << "Datei geschlossen...!" << endl << endl;
    }

}

TTournament::~TTournament()
{
    //dtor
}

void TTournament::print()
{
    cout << "Turnier: " << TName << endl << endl << "Stadien:" << endl;

    for(int i = 0; i < NumberOfStadiums; i++)
    {
        //cout << this->Stadium[i] << endl;
        cout << "- " << this->Stadium[i]->GetStName() << " (" << this->Stadium[i]->GetNumberOfSeats() << " Sitzplaetze) in " << this->Stadium[i]->GetTown() << "; " << this->Stadium[i]->GetCountry() << endl;
    }

    cout << endl << "Teams:" << endl;
    for(int i = 0; i < this->GetNumberOfTeams(); i++)
    {
        cout << this->Team[i]->Getname() << endl << this->Team[i]->Gettrainer() << endl << endl;

        if (this->Team[i]->GetNumberOfPlayers() <= 0){

            cout << "Keine Spieler!" << endl;

        }else{

            cout << "Spieler                 | Nr | Spiele | Tore | Vorl. | Gelb |  Rot | Geburtstag" << endl;
            cout << "------------------------|----|--------|------|-------|------|------|-----------" << endl;

            for (int j = 0; j < this->Team[i]->GetNumberOfPlayers(); j++){

                if (this->Team[i]->GetPlayers(j) != NULL){
                    cout.setf(ios::left, ios::adjustfield);
                    cout << setw(23) << setfill(' ') << this->Team[i]->GetPlayers(j)->Getname();
                    cout.setf(ios::right, ios::adjustfield);
                    cout << " | " << setw(2) << this->Team[i]->GetPlayers(j)->GettricotNr()
                    << " | " << setw(6) << this->Team[i]->GetPlayers(j)->GetNumberOfGames()
                    << " | " << setw(4) << this->Team[i]->GetPlayers(j)->GetNumberOfGoals()
                    << " | " << setw(5) << this->Team[i]->GetPlayers(j)->GetNumberOfPasses()
                    << " | " << setw(4) << this->Team[i]->GetPlayers(j)->GetNumberOfYellowCards()
                    << " | " << setw(4) << this->Team[i]->GetPlayers(j)->GetNumberOfRedCards()
                    << " | " << setw(2) << setfill('0') << this->Team[i]->GetPlayers(j)->GetBirthday().getDay()
                    << "." << setw(2) << this->Team[i]->GetPlayers(j)->GetBirthday().getMonth()
                    << "."<<  setw(4) << this->Team[i]->GetPlayers(j)->GetBirthday().getYear()
                    << setfill(' ') << endl;
                }
            }
            cout << "------------------------|----|--------|------|-------|------|------|-----------" << endl;
        }
    }
}

int TTournament::load(std::ifstream &ifs)
{
    //cout << "Lese aus Datei...!" << endl;
    string line = ReadUnspaced(ifs);
    if (line == "<Tournament>")
    {
        while(ifs.good())
        {

            line = ReadUnspaced(ifs);
            if (line == "<Team>")
            {
                this->Team[NumberOfTeams] = new TTeam;
                this->Team[NumberOfTeams]->load(ifs);
                NumberOfTeams++;
            }else if (line == "<Stadium>")
            {
                this->Stadium[NumberOfStadiums] = new TStadium;
                this->Stadium[NumberOfStadiums]->load(ifs);
                NumberOfStadiums++;
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
    //unsigned int g = isChar(' ', line);
    line.erase(line.begin(), std::find_if(line.begin(), line.end(), std::bind1st(std::not_equal_to<char>(), ' ')));
    //line.erase(std::remove( line.begin(), g, ' ' ), line.end() );
    return line;
}

unsigned int TTournament::isChar(char charakter, std::string line)
{
    unsigned int i;
    for(i = 0; i < line.length(); i++)
    {
        if(line.at(i) == charakter)
        {

        }else{
            break;
        }
    }
    return i;
}




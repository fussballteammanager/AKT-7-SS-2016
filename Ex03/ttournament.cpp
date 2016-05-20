#include <iomanip>
#include <iostream>
#include <fstream>

#include "ttournament.h"
#include "ttools.h"

using namespace std;

TTournament::TTournament(string DName)
{
    NumberOfTeams = 0;
    NumberOfStadiums = 0;
    NumberOfMatches = 0;
    std::ifstream ifs, &r_ifs = ifs;
    ifs.open(DName.c_str(), std::ifstream::in);
    if(!ifs.is_open())
    {
        cout << "Keine Datei...!" << endl;
    }else{
        load(r_ifs);
    }
    ifs.close();

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
    string line = TTools::ReadUnspaced(ifs);
    if (line == "<Tournament>")
    {
        while(ifs.good())
        {

            line = TTools::ReadUnspaced(ifs);
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
                line = TTools::tagremove(line, tag1);
                line = TTools::tagremove(line, tag2);
                this->TName = line;
            }
        }
    }
    return 0;
}





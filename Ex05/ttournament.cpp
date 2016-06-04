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
    #ifdef DEBUG
        cout << "TTournament destructor" << endl;
    #endif
    for ( int i = 0; i < NumberOfTeams; i++ )
        delete this->Team[i];
    for ( int i = 0; i < NumberOfStadiums; i++ )
        delete this->Stadium[i];
}

void TTournament::print()
{
    cout << "Turnier: " << TName << endl;

    cout << endl << "Stadien:" << endl;
    for( int i = 0; i < NumberOfStadiums; i++ )
        this->Stadium[i]->print();

    cout << endl << "Teams:" << endl;
    for(int i = 0; i < NumberOfTeams; i++)
        this->Team[i]->print();
}

int TTournament::load( std::ifstream &ifs )
{
    string line = TTools::ReadUnspaced(ifs);

    while(ifs.good())
    {
        if ( TTools::strcontain( line,"<Tournament>" ) )
        {
            #ifdef DEBUG
                cout << line << endl;
            #endif
            break;
        }
        else if ( ifs.eof() )
            return 1;
    }

    while( ifs.good() )
    {
        line = TTools::ReadUnspaced(ifs);

        if ( TTools::strcontain( line,"<Team>" ) )
        {
            #ifdef DEBUG
                cout << line << endl;
            #endif
            this->Team[NumberOfTeams] = new TTeam;
            this->Team[NumberOfTeams]->load(ifs);
            NumberOfTeams++;
        }
        else if ( TTools::strcontain( line,"<Stadium>" ) )
        {
            #ifdef DEBUG
                cout << line << endl;
            #endif
            this->Stadium[NumberOfStadiums] = new TStadium;
            this->Stadium[NumberOfStadiums]->load(ifs);
            NumberOfStadiums++;
        }
        else if (  TTools::strcontain(line,"<Name>" ) )
        {
            #ifdef DEBUG
                cout << line << endl;
            #endif
            std::string tag1 = "<Name>",tag2 = "</Name>";
            line = TTools::tagremove(line, tag1);
            line = TTools::tagremove(line, tag2);
            this->TName = line;
        }
        else if ( TTools::strcontain(line,"</Tournament>" ) )
        {
            #ifdef DEBUG
                cout << line << endl;
            #endif
            return 1;
        }
        else if ( ifs.eof() )
        {
            #ifdef DEBUG
                cout << "end of file" << endl;
            #endif
            return 0;
        }
        else
            return 1; // error

    } // while

    return 0;
}

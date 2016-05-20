#include <iostream>
#include "tplayer.h"
#include "tteam.h"
#include "ttournament.h"

using namespace std;

int main()
{
     TTournament Bundesliga("fussball.xml");
     Bundesliga.print();
     cout << endl;
     cout << "Erster und letzter Spieler in der Liste:" << endl;
     ((Bundesliga.getTeam(0))->GetPlayers(0))->print();
     cout << endl;
     ((Bundesliga.getTeam(0))->GetPlayers((Bundesliga.getTeam(0))->GetNumberOfPlayers() - 1))->print();
     cout << endl;

//     cout << "How many teams:" << endl;
//     cout << Bundesliga.GetNumberOfTeams() << endl;


     return 0;
}

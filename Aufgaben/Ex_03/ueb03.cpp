#include <iostream>

using namespace std;

#include "ttournament.h"

int main()
{
   TTournament Bundesliga("fussball.xml");

   Bundesliga.print();
   cout << endl;

   cout << "Erster und letzter Spieler in der Liste:" << endl;
   ((Bundesliga.getTeam(0))->getPlayer(0))->print();
   cout << endl;
   ((Bundesliga.getTeam(0))->getPlayer((Bundesliga.getTeam(0))->getNumberOfPlayers() - 1))->print();
   cout << endl;

   return 0;
}

#include <iostream>
#include <vector>

using namespace std;

#include "tdate.h"
#include "ttournament.h"
#include "tevent.h"

int main()
{
   TTournament Bundesliga("fussball.xml");
   vector<TEvent *> Spielverlauf;
   TDate Spieltag(23, 4, 2016);

   Bundesliga.print();

   Spielverlauf.push_back(new TFoul        ( 7, Bundesliga.getTeam(0)->getPlayer( 5),
                                                Bundesliga.getTeam(1)->getPlayer( 9)));
   Spielverlauf.push_back(new TFreeKick    ( 7, Bundesliga.getTeam(1)->getPlayer( 9),
                                                26));
   Spielverlauf.push_back(new TFreeKick    (25, Bundesliga.getTeam(0)->getPlayer( 7),
                                                17));
   Spielverlauf.push_back(new TCard        (41, Bundesliga.getTeam(1)->getPlayer(11),
                                                true, false));
   Spielverlauf.push_back(new TSubstituting(51, Bundesliga.getTeam(0)->getPlayer( 5),
                                                Bundesliga.getTeam(0)->getPlayer( 3)));
   Spielverlauf.push_back(new TFoul        (64, Bundesliga.getTeam(1)->getPlayer( 4),
                                                Bundesliga.getTeam(0)->getPlayer(10)));
   Spielverlauf.push_back(new TPenalty     (64, Bundesliga.getTeam(0)->getPlayer(13),
                                                true));
   Spielverlauf.push_back(new TGoal        (64, Bundesliga.getTeam(0)->getPlayer(13),
                                                nullptr, false));
   Spielverlauf.push_back(new TGoal        (78, Bundesliga.getTeam(1)->getPlayer( 5),
                                                nullptr, true));
   Spielverlauf.push_back(new TGoal        (85, Bundesliga.getTeam(0)->getPlayer(14),
                                                Bundesliga.getTeam(0)->getPlayer(11),
                                                false));

   cout << "Spiel zwischen "
        << Bundesliga.getTeam(0)->getName() << " und "
        << Bundesliga.getTeam(1)->getName() << " am ";
   Spieltag.print();
   cout << ":" << endl;

   for (unsigned i = 0; i < Spielverlauf.size(); i++)
      Spielverlauf[i]->print();
   cout << endl;

   return 0;
}

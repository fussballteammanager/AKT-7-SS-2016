#include <iostream>
#include <vector>

using namespace std;

#include "tdate.h"
#include "ttournament.h"
//#include "tevent.h"

int main()
{
    TTournament Bundesliga("fussball.xml");
//    vector<TEvent *> Spielverlauf;
    TDate Spieltag(23, 4, 2016);

    Bundesliga.print();

#if 0 /* Ex04 main.c */
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
#endif

#if 0 /* add and delete player test */
    TPlayer Jarstein ("Rune Jarstein", "Torwart", 22, 0, 0, 25, 1, 0, 29, 9, 1984);
    TPlayer Kraft ("Thomas Kraft", "Torwart", 1, 0, 0, 5, 0, 0, 22, 7, 1988);
    TPlayer Plattenhardt("Marvin Plattenhardt", "Abwehr", 21, 2, 5, 29, 4, 0, 26, 1, 1992);
    TPlayer Weiser ("Mitchell-Elijah Weiser", "Abwehr", 20, 2, 4, 25, 5, 0, 21, 4, 1994);
    TPlayer Brooks ("John Brooks", "Abwehr", 25, 1, 1, 20, 3, 0, 28, 1, 1993);
    TPlayer Langkamp ("Sebastian Langkamp", "Abwehr", 15, 0, 1, 19, 7, 0, 15, 1, 1988);
    TPlayer Skjelbred ("Per Skjelbred", "Mittelfeld", 3, 0, 1, 28, 8 ,0, 16, 6, 1987);
    TPlayer Darida ("VladimYr Darida", "Mittelfeld", 6, 4, 3, 28, 6, 0, 8, 8, 1990);
    TPlayer Haraguchi ("Genki Haraguchi", "Mittelfeld", 24, 2, 4, 28, 4, 0, 9, 5, 1991);
    TPlayer Lustenberger("Fabian Lustenberger", "Mittelfeld", 28, 1, 0, 25, 3, 0, 2, 5, 1988);
    TPlayer Baumjohann ("Alexander Baumjohann", "Mittelfeld", 9, 1, 2, 21, 0, 0, 23, 1, 1987);
    TPlayer Stocker ("Valentin Stocker", "Mittelfeld", 14, 1, 0, 19, 2, 0, 12, 4, 1989);
    TPlayer Kalou ("Salomon Kalou", "Angriff", 11, 14, 2, 27, 2, 0, 5, 8, 1985);
    TPlayer Ibisevic ("Vedad Ibisevic", "Angriff", 19, 9, 3, 22, 3, 1, 6, 8, 1984);

    TTeam Hertha("Hertha BSC", "Pal Dardai");

    Kraft.print(); cout << endl;
    Lustenberger.print(); cout << endl << endl;
    Hertha.print(); cout << endl;

    Hertha.addPlayer(Jarstein);
    Hertha.addPlayer(Kraft);
    Hertha.addPlayer(Plattenhardt);
    Hertha.addPlayer(Weiser);
    Hertha.addPlayer(Brooks);
    Hertha.addPlayer(Langkamp);
    Hertha.addPlayer(Skjelbred);
    Hertha.addPlayer(Darida);
    Hertha.addPlayer(Haraguchi);
    Hertha.addPlayer(Lustenberger);
    Hertha.addPlayer(Baumjohann);
    Hertha.addPlayer(Stocker);
    Hertha.addPlayer(Kalou);
    Hertha.addPlayer(Ibisevic);

    Hertha.print();
    Hertha.removePlayer(Baumjohann);
    Hertha.print();
#endif // 0

   return 0;
}

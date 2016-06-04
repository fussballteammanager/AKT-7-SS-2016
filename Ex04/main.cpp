#include <iostream>
#include <vector>
#include <string>

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

//    TEvent Ev1;
//    TPlayer Jarstein("Rune Jarstein", "Torwart", 22, 0, 0, 25, 1, 0, 29, 9, 1984);
//    Jarstein.print();
//    Ev1.SetPlayer( &Jarstein );
//    Ev1.SetMinuteOfPlay( 60 );
//    cout << "Min of play: " << Ev1.GetMinuteOfPlay() << endl;
//    TPlayer* test = Ev1.GetPlayer();
//
//    if ( test != 0 )
//        cout << "Tricot nr: " <<test->GettricotNr() << endl;

   Spielverlauf.push_back(new TFoul        ( 7, Bundesliga.GetTeam(0)->GetPlayer( 5),
                                                Bundesliga.GetTeam(1)->GetPlayer( 9)));
#if 0 /* Ex04 main.c */
   Spielverlauf.push_back(new TFreeKick    ( 7, Bundesliga.GetTeam(1)->GetPlayer( 9),
                                                26));
   Spielverlauf.push_back(new TFreeKick    (25, Bundesliga.GetTeam(0)->GetPlayer( 7),
                                                17));
   Spielverlauf.push_back(new TCard        (41, Bundesliga.GetTeam(1)->GetPlayer(11),
                                                true, false));
   Spielverlauf.push_back(new TSubstituting(51, Bundesliga.GetTeam(0)->GetPlayer( 5),
                                                Bundesliga.GetTeam(0)->GetPlayer( 3)));
   Spielverlauf.push_back(new TFoul        (64, Bundesliga.GetTeam(1)->GetPlayer( 4),
                                                Bundesliga.GetTeam(0)->GetPlayer(10)));
   Spielverlauf.push_back(new TPenalty     (64, Bundesliga.GetTeam(0)->GetPlayer(13),
                                                true));
   Spielverlauf.push_back(new TGoal        (64, Bundesliga.GetTeam(0)->GetPlayer(13),
                                                nullptr, false));
   Spielverlauf.push_back(new TGoal        (78, Bundesliga.GetTeam(1)->GetPlayer( 5),
                                                nullptr, true));
   Spielverlauf.push_back(new TGoal        (85, Bundesliga.GetTeam(0)->GetPlayer(14),
                                                Bundesliga.GetTeam(0)->GetPlayer(11),
                                                false));
#endif

   cout << "Spiel zwischen "
        << Bundesliga.GetTeam(0)->GetName() << " und "
        << Bundesliga.GetTeam(1)->GetName() << " am ";
   Spieltag.print();
   cout << ":" << endl;

   for (unsigned i = 0; i < Spielverlauf.size(); i++)
      Spielverlauf[i]->print();
   cout << endl;

   return 0;
}

#include <iostream>

using namespace std;

#include "tplayer.h"
#include "tteam.h"

int main()
{
   // Parameter: Name, Position, TricotNr, CountGoals, CountPass, CountGames, CountYellowCards, CountRedCards, Geburtstag
   TPlayer Jarstein    ("Rune Jarstein",          "Torwart",    22,  0, 0, 25, 1, 0, 29,  9, 1984);
   TPlayer Kraft       ("Thomas Kraft",           "Torwart",     1,  0, 0,  5, 0, 0, 22,  7, 1988);

   TPlayer Plattenhardt("Marvin Plattenhardt",    "Abwehr",     21,  2, 5, 29, 4, 0, 26,  1, 1992);
   TPlayer Weiser      ("Mitchell-Elijah Weiser", "Abwehr",     20,  2, 4, 25, 5, 0, 21,  4, 1994);
   TPlayer Brooks      ("John Brooks",            "Abwehr",     25,  1, 1, 20, 3, 0, 28,  1, 1993);
   TPlayer Langkamp    ("Sebastian Langkamp",     "Abwehr",     15,  0, 1, 19, 7, 0, 15,  1, 1988);

   TPlayer Skjelbred   ("Per Skjelbred",          "Mittelfeld",  3,  0, 1, 28, 8 ,0, 16,  6, 1987);
   TPlayer Darida      ("Vladim�r Darida",        "Mittelfeld",  6,  4, 3, 28, 6, 0,  8,  8, 1990);
   TPlayer Haraguchi   ("Genki Haraguchi",        "Mittelfeld", 24,  2, 4, 28, 4, 0,  9,  5, 1991);
   TPlayer Lustenberger("Fabian Lustenberger",    "Mittelfeld", 28,  1, 0, 25, 3, 0,  2,  5, 1988);
   TPlayer Baumjohann  ("Alexander Baumjohann",   "Mittelfeld",  9,  1, 2, 21, 0, 0, 23,  1, 1987);
   TPlayer Stocker     ("Valentin Stocker",       "Mittelfeld", 14,  1, 0, 19, 2, 0, 12,  4, 1989);

   TPlayer Kalou       ("Salomon Kalou",          "Angriff",    11, 14, 2, 27, 2, 0,  5,  8, 1985);
   TPlayer Ibisevic    ("Vedad Ibisevic",         "Angriff",    19,  9, 3, 22, 3, 1,  6,  8, 1984);

   TTeam Hertha("Hertha BSC", "Pal Dardai");

   Kraft.print();             cout << endl;
   Lustenberger.print();      cout << endl << endl;

   Hertha.print();   cout << endl;

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

   Hertha.print();   cout << endl;

   return 0;
}

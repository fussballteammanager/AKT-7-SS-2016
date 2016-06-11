#include <iostream>

using namespace std;

#include "ttournament.h"

int main()
{
   TTournament Bundesliga("fussball.xml");

    /* funkst erst nach überladen, siehe Aufgabe 6 pdf */
    cout << Bundesliga << endl;

    //Bundesliga.print();

   return 0;
}

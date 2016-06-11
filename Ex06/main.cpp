#include <iostream>

using namespace std;

#include "ttournament.h"

int main()
{
   TTournament Bundesliga("fussball.xml");

   Bundesliga.print();
   cout << endl;

   return 0;
}

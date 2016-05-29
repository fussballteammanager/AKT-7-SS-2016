#include <iostream>

using namespace std;

#include "tdate.h"
#include "ttime.h"
#include "tscore.h"

int main()
{
   TDate D1, D2(27, 3, 2016);
   TTime T1, T2(14, 15);
   TScore S1, S2(4, 2);

   cout << "\nKlasse TDate:" << endl;
   cout << "Standardkonstruktor Heutiges Datum D1:     ";   D1.print();   cout << endl;
   cout << "Konstruktor         Ostersonntag (D2):     ";   D2.print();   cout << endl;

   cout << "\nKlasse TTime:" << endl;
   cout << "Standardkonstruktor Aktuelle Uhrzeit T1:   ";   T1.print();   cout << endl;
   cout << "Konstruktor         Vorlesungsbeginn (T2): ";   T2.print();   cout << endl;

   cout << "\nKlasse TScore:" << endl;
   cout << "Standardkonstruktor 0:0 S1:                ";   S1.print();   cout << endl;
   cout << "Konstruktor         4:2 (S2):              ";   S2.print();   cout << endl;

   cout << "\nPunkte für den Torstand S1 (";   S1.print();
   cout << ")           " << S1.getPointsHome() << ":" << S1.getPointsGuest() << endl;
   cout << "Punkte für den Torstand S2 (";   S2.print();
   cout << ")           " << S2.getPointsHome() << ":" << S2.getPointsGuest() << endl;

   return 0;
}

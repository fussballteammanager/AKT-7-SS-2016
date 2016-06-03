/******************************************************
 ******************************************************
 *** PROGRAMM: Cpp Übung
 *** MODUL: main.cpp
 *** VERSION: 1
 *** BESCHREIBUNG: Cpp class exercises
 *** GLOBALE FKT.: -
 *** LOKALE FKT.: -
 ***---------------------------------------------------
 *** ERSTELLT VON: ts
 *** DATUM BEGINN: 11.04.2016
 ***         ENDE: 12.04.2016
 *** ÄNDERUNGEN  : -
 ******************************************************
 ******************************************************/

/*
umlaute in hex:
Ä xC4,Ö xD6,Ü xDC,
ä xE4,ö xF6,ü xFC,
*/
#include <iostream>
#include "tdate.h"
#include "ttime.h"
#include "tscore.h"

using namespace std;

int main()
{
   TDate D1, D2(27, 3, 2016);
   TTime T1, T2(14, 15);
   TScore S1, S2(4, 2);

    cout << "\nKlasse TDate:";
    cout << "\nStandardkonstruktor Heutiges Datum D1:     ";
    D1.print();
    cout << "\nKonstruktor         Ostersonntag (D2):     ";
    D2.print();
    cout << "\n\nKlasse TTime:";
    cout << "\nStandardkonstruktor Aktuelle Uhrzeit T1:   ";
    T1.print();
    cout << "\nKonstruktor         Vorlesungsbeginn (T2): ";
    T2.print();

    cout << "\n\nKlasse TScore:";
    cout << "\nStandardkonstruktor 0:0 S1:                ";
    S1.print();
    cout << "\nKonstruktor         4:2 (S2):              ";
    S2.print();

    cout << "\n\nPunkte fuer den Torstand S1 (";
    S1.print();
    cout << ")          " << S1.getPointsHome() << ":" << S1.getPointsGuest();
    cout << "\nPunkte fuer den Torstand S2 (";   S2.print();
    cout << ")          " << S2.getPointsHome() << ":" << S2.getPointsGuest() << "\n";

   return 0;
}

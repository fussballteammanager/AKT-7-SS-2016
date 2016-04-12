//#include<iostream>
#include<stdio.h>

#include"tscore.h"

using namespace std;


static void setDefault( void );

TScore::TScore()
{
    TScore::setGoals(0, 0);
}

TScore::TScore(int goalsHome, int goalsGuest)
{
    TScore::setGoals(goalsHome, goalsGuest);
}

TScore::~TScore()
{
    printf( "Object TScore is freed\n" );
}

void TScore::setGoals(int goalsHome, int goalsGuest)
{
    if ( goalsHome >= 0 and goalsHome <= 100 and goalsGuest >= 0 and goalsGuest <= 100 )
    {
        TScore::goalsHome  = goalsHome;
        TScore::goalsGuest = goalsGuest;
    }
    else
    {
        TScore::goalsHome  = 0;
        TScore::goalsGuest = 0;
    }
}

static int calcPoints(int first, int second)
{
    if (first == second)
        return 1;
    else if (first > second)
        return 3;
    else
        return 0;
}

int TScore::getPointsHome()
{
   return calcPoints(TScore::goalsHome, TScore::goalsGuest);
}

int TScore::getPointsGuest()
{
    return calcPoints(TScore::goalsGuest, TScore::goalsHome);
}

void TScore::print()
{
    printf( "%i:%i",TScore::goalsHome, TScore::goalsGuest);
}

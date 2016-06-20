#include <iostream>

#include "tscore.h"

using namespace std;


TScore::TScore()
{
    TScore::setGoals(0, 0);
}

TScore::TScore(short goalsHome, short goalsGuest)
{
    TScore::setGoals(goalsHome, goalsGuest);
}

void TScore::setGoals(short goalsHome, short goalsGuest)
{
    if ( goalsHome >= 0 and goalsHome <= 100 and goalsGuest >= 0 and goalsGuest <= 100 )
    {
        TScore::goalsHome  = goalsHome;
        TScore::goalsGuest = goalsGuest;
    }else
    {
        TScore::goalsHome  = 0;
        TScore::goalsGuest = 0;
    }
}

static short calcPoints(short first, short second)
{
    if (first == second)
        return 1;
    else if (first > second)
        return 3;
    else
        return 0;
}

short TScore::getPointsHome()
{
   return calcPoints(TScore::goalsHome, TScore::goalsGuest);
}

short TScore::getPointsGuest()
{
    return calcPoints(TScore::goalsGuest, TScore::goalsHome);
}


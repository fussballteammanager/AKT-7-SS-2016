#ifndef TSCORE_H
#define TSCORE_H TSCORE_H

#include <iostream>
#include <iomanip>

using namespace std;

class TScore
{
    private:
        short goalsHome;
        short goalsGuest;

    public:
        TScore();
        TScore(short goalsHome, short goalsGuest);
        void setGoals(short goalsHome, short goalsGuest);
        short getGoalsHome() { return goalsHome; }
        short getGoalsGuest() { return goalsGuest; }
        short getPointsHome();
        short getPointsGuest();

        friend ostream& operator<<(ostream& os, TScore& Score)
        {
            return os << Score.getGoalsHome() << ":" << Score.getGoalsGuest();
        }
};

#endif

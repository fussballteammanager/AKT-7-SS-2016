#ifndef TPLAYER_H
#define TPLAYER_H TPLAYER_H

#include <string>

#include "tdate.h"

class TPlayer
{
    private:
        std::string name;
        std::string position;
        short tricotNr;
        TDate Birthday;
        unsigned int NumberOfGames;
        unsigned int NumberOfPasses;
        unsigned int NumberOfGoals;
        unsigned int NumberOfYellowCards;
        unsigned int NumberOfRedCards;

    public:
        TPlayer();
        TPlayer(std::string name, std::string position, short tricotNr, unsigned int NumberOfGoals,
            unsigned int NumberOfPasses, unsigned int NumberOfGames, unsigned int NumberOfYellowCards,
            unsigned int NumberOfRedCards, unsigned int Day, unsigned int Month, unsigned int Yea);
        virtual ~TPlayer();
        std::string Getname() { return name; }
        void Setname(std::string val) { name = val; }
        std::string Getposition() { return position; }
        void Setposition(std::string val) { position = val; }
        short GettricotNr() { return tricotNr; }
        void SettricotNr(short val) { tricotNr = val; }
        TDate GetBirthday() { return Birthday; }
        void SetBirthday(TDate val) { Birthday = val; }
        unsigned int GetNumberOfGames() { return NumberOfGames; }
        void SetNumberOfGames(unsigned int val) { NumberOfGames = val; }
        unsigned int GetNumberOfPasses() { return NumberOfPasses; }
        void SetNumberOfPasses(unsigned int val) { NumberOfPasses = val; }
        unsigned int GetNumberOfGoals() { return NumberOfGoals; }
        void SetNumberOfGoals(unsigned int val) { NumberOfGoals = val; }
        unsigned int GetNumberOfYellowCards() { return NumberOfYellowCards; }
        void SetNumberOfYellowCards(unsigned int val) { NumberOfYellowCards = val; }
        unsigned int GetNumberOfRedCards() { return NumberOfRedCards; }
        void SetNumberOfRedCards(unsigned int val) { NumberOfRedCards = val; }
        int load(std::ifstream &ifs);
        void print();
    protected:

};

#endif // TPLAYER_H

#ifndef TPLAYER_H
    #define TPLAYER_H TPLAYER_H

    #include "tdate.h"

    using namespace std;

    class TPlayer
    {
        private:
            string name;
            string position;
            short tricotNr;
            TDate Birthday;
            unsigned int NumberOfGames;
            unsigned int NumberOfPasses;
            unsigned int NumberOfGoals;
            unsigned int NumberOfYellowCards;
            unsigned int NumberOfRedCards;

        public:
            TPlayer();
            TPlayer(string name, string position, short tricotNr, unsigned int NumberOfGoals,
                unsigned int NumberOfPasses, unsigned int NumberOfGames, unsigned int NumberOfYellowCards,
                unsigned int NumberOfRedCards, unsigned int Day, unsigned int Month, unsigned int Yea);
            virtual ~TPlayer();
            string Getname() { return name; }
            void Setname(string val) { name = val; }
            string Getposition() { return position; }
            void Setposition(string val) { position = val; }
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

            void print();
        protected:

    };

#endif // TPLAYER_H

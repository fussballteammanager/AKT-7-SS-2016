#ifndef TSTADIUM_H
#define TSTADIUM_H TSTADIUM_H
#include <string>


class TStadium
{
    public:
        TStadium();
        ~TStadium();
        std::string GetStName() { return StName; }
        void SetStName(std::string val) { StName = val; }
        std::string GetTown() { return Town; }
        void SetTown(std::string val) { Town = val; }
        std::string GetCountry() { return Country; }
        void SetCountry(std::string val) { Country = val; }
        int GetNumberOfSeats() { return NumberOfSeats; }
        void SetNumberOfSeats(int val) { NumberOfSeats = val; }
        int GetYearOfConstruction() { return YearOfConstruction; }
        void SetYearOfConstruction(int val) { YearOfConstruction = val; }
        int load(std::ifstream &ifs);
        void print();
    protected:
    private:
        std::string StName;
        std::string Town;
        std::string Country;
        int NumberOfSeats;
        int YearOfConstruction;
};

#endif // TSTADIUM_H

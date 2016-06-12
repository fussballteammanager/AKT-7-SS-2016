#ifndef TSTADIUM_H
#define TSTADIUM_H TSTADIUM_H

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class TStadium
{
    private:
        string StName;
        string Town;
        string Country;
        int NumberOfSeats;
        int YearOfConstruction;

    public:
        TStadium();
        TStadium(string name, string town, string country, int seats, int year);
        ~TStadium();

        string GetStName() { return StName; }
        void SetStName(string val) { StName = val; }
        string GetTown() { return Town; }
        void SetTown(string val) { Town = val; }
        string GetCountry() { return Country; }
        void SetCountry(string val) { Country = val; }
        int GetNumberOfSeats() { return NumberOfSeats; }
        void SetNumberOfSeats(int val) { NumberOfSeats = val; }
        int GetYearOfConstruction() { return YearOfConstruction; }
        void SetYearOfConstruction(int val) { YearOfConstruction = val; }
        int load(ifstream &ifs);
        void print();
        friend ostream& operator<<(ostream& os, TStadium& Stadium)
        {
            return os << Stadium.GetStName() << " (" << Stadium.GetNumberOfSeats()
                << " Sitzplaetze) in " << Stadium.GetTown() << "; "
                << Stadium.GetCountry() << endl;
        }

    protected:
};

#endif // TSTADIUM_H

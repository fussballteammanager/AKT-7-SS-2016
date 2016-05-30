#ifndef READDATA_H
#define READDATA_H READDATA_H

#include <iostream>
#include <fstream>
#include <string>


class readdata
{
    public:
        readdata();
        virtual ~readdata();
        static std::string readunspaced(std::ifstream &ifs);

    protected:
    private:
};

#endif // READDATA_H

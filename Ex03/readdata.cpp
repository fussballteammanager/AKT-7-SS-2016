#include "readdata.h"

readdata::readdata()
{
    //ctor
}

readdata::~readdata()
{
    //dtor
}

static string readdata::readunspaced(std::ifstream &ifs)
{
    string line;
    getline(ifs,line);
    line.erase(std::remove( line.begin(), line.end(), ' ' ), line.end() );
    return line;
}

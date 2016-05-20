#include <algorithm>
#include <fstream>

#include "ttools.h"

TTools::TTools()
{
    //ctor
}

TTools::~TTools()
{
    //dtor
}

bool TTools::strcontain(std::string in, std::string tag)
{
    if (in.find(tag) != std::string::npos)
    {
        return true;
    }else
    {
        return false;
    }
}

std::string TTools::tagremove(std::string in, std::string tag)
{
    std::string::size_type i = in.find(tag);
    if (i != std::string::npos)
    {
        in.erase(i, tag.length());
    }
    return in;
}

std::string TTools::ReadUnspaced(std::ifstream &in)
{
    std::string line;
    getline (in,line);
    line.erase(line.begin(), std::find_if(line.begin(), line.end(), std::bind1st(std::not_equal_to<char>(), ' ')));
    return line;
}

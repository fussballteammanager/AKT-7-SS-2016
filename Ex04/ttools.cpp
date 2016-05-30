#include <algorithm>
#include <fstream>

#include "ttools.h"
#include <iostream>

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

std::string TTools::tagremove(std::string line, std::string tag)
{
    int pos;
    std::string::size_type i = line.find(tag);
    if (i != std::string::npos)
    {
        line.erase(i, tag.length());
    }

    // exchange 'Umlaute'
    pos =  line.find("ü");
    if ( pos > 0 )
        line.replace(line.find("ü"), sizeof("ue")-1, "ue");

    pos =  line.find("ä");
    if ( pos > 0 )
        line.replace(line.find("ä"), sizeof("ae")-1, "ae");

    pos =  line.find("ö");
    if ( pos > 0 )
        line.replace(line.find("ö"), sizeof("oe")-1, "oe");

    return line;
}

std::string TTools::ReadUnspaced(std::ifstream &in)
{
    std::string line;
    getline (in,line);
    line.erase(line.begin(), std::find_if(line.begin(), line.end(), std::bind1st(std::not_equal_to<char>(), ' ')));

    // remove all ascii signs after last bracket
    unsigned int pos = line.find_last_of('>');
    if ( pos > 0 and ( pos+1 != line.length() ) )
    {
        #ifdef DEBUG
            std::cout << "Last letter has to be removed, length of string: " << line.length() << " Position of last bracket: " << pos+1 <<  std::endl;
        #endif

        while ( line.length() > pos+1)
            line.erase( line.end()-1 );

        #ifdef DEBUG
            std::cout << "New length: " << line.length() << " String: " << line <<  std::endl;
        #endif
    }


    return line;
}

#ifndef TTOOLS_H
#define TTOOLS_H

#include <string>

class TTools
{
    public:
        TTools();
        virtual ~TTools();
        static std::string ReadUnspaced(std::ifstream &in);
        static std::string tagremove(std::string in, std::string tag);
        static bool strcontain(std::string in, std::string tag);
    protected:
    private:
};

#endif // TTOOLS_H

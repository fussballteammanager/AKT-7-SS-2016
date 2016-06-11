#ifndef TTIME_H
#define TTIME_H TTIME_H


class TTime
{
    private:
        short hour;
        short minute;
        void setCurrentTime();

    public:
        TTime();
        TTime(short hour, short minute);
        ~TTime();

        void setTime(short hour, short minute);
        short getHour();
        short getMinute();
        int load(std::ifstream &ifs);
        void print();
};

#endif


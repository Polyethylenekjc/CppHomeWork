#ifndef TIMETABLE
#define TIMETABLE

class Time{
    private:
        int dd,hh,mm,ss;
    public:
        Time():dd(-1),hh(-1),mm(-1),ss(-1){};
        Time(int a,int b,int c,int d):dd(a),hh(b),mm(c),ss(d){};
        bool operator==(const Time& t);
        bool operator!=(const Time& t);
        bool operator<(const Time& t);
        bool operator>(const Time& t);
        bool operator<=(const Time& t);
        bool operator>=(const Time& t);
};

class TimeTable{
    private:
        Time start,end;
    public:
        TimeTable(){};
        TimeTable(int a1,int b1,int c1,int d1,int a2,int b2,int c2,int d2):start(a1,b1,c1,d1),end(a2,b2,c2,d2){};
        bool intersect(const TimeTable&  tb);
};

#endif
#ifndef TIMETABLE
#define TIMETABLE
#include<string>
#include<iostream>
using namespace std;

class Time{
    private:
        string yy,MM,dd,hh,mm,ss;
    public:
        Time(){};
        Time(string yy,string mm,string a,string b,string c,string d):yy(yy),MM(mm),dd(a),hh(b),mm(c),ss(d){
            if(mm.length()==1)
                mm="0"+mm;
            if(MM.length()==1)
                MM="0"+MM;
            if(hh.length()==1)
                hh="0"+hh;
            if(ss.length()==1)
                ss="0"+ss;
            if(MM.length()==1)
                MM="0"+MM;
        };
        bool operator==(const Time& t);
        bool operator!=(const Time& t);
        bool operator<(const Time& t);
        bool operator>(const Time& t);
        bool operator<=(const Time& t);
        bool operator>=(const Time& t);
        friend ostream& operator<<(ostream& out,Time& tb){
            return out<<tb.yy<<"/"<<tb.MM<<" "<<tb.dd<<":"<<tb.hh<<":"<<tb.mm<<":"<<tb.ss<<endl;
        }
};

class TimeTable{
    private:
        Time _start,_end;
        string name;
    public:
        TimeTable(){};
        TimeTable(string n1,string y1,string m1,string a1,string b1,string c1,string d1,string y2,string m2,string a2,string b2,string c2,string d2):name(n1),_start(y1,m1,a1,b1,c1,d1),_end(y2,m2,a2,b2,c2,d2){};
        bool intersect(const TimeTable&  tb);
        bool operator<=(const TimeTable& tb);
        friend ostream& operator<<(ostream& out,TimeTable& tb){
            return out<<"Name:"<<tb.name<<"\nTime:"<<tb._start<<"   ->"<<tb._end<<endl;
        }
};

#endif
#ifndef TIMETABLE
#define TIMETABLE
#include<string>
#include<iostream>
using namespace std;

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
        friend ostream& operator<<(ostream& out,Time& tb){
            return out<<tb.dd<<":"<<tb.hh<<":"<<tb.mm<<":"<<tb.ss<<endl;
        }
};

class TimeTable{
    private:
        Time _start,_end;
        string name;
    public:
        TimeTable(){};
        TimeTable(string n1,int a1,int b1,int c1,int d1,int a2,int b2,int c2,int d2):name(n1),_start(a1,b1,c1,d1),_end(a2,b2,c2,d2){};
        bool intersect(const TimeTable&  tb);
        bool operator<=(const TimeTable& tb);
        friend ostream& operator<<(ostream& out,TimeTable& tb){
            return out<<"Name:"<<tb.name<<"\nTime:"<<tb._start<<"->"<<tb._end<<endl;
        }
};

#endif
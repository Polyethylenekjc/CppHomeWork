#ifndef TIMETABLE
#define TIMETABLE

#include"inc.h"
#include"ColorPrint.hpp"
using namespace std;

class Time{
    private:
        char *yy,*MM,*dd,*hh,*mm,*ss;
    public:
        Time(){};
        Time(char* y,char* M,char* d,char* h,char* m,char* s){
            char* zero;
            *(zero)='0';
            if(strlen(y)<=1){
                strcpy(yy,strcat(zero,y));
            }
            else{
                strcpy(yy,y);
            }
            if(strlen(M)<=1){
                strcpy(MM,strcat(zero,M));
            }
            else{
                strcpy(MM,M);
            }
            if(strlen(d)<=1){
                strcpy(dd,strcat(zero,d));
            }
            else{
                strcpy(dd,d);
            }
            if(strlen(h)<=1){
                strcpy(hh,strcat(zero,h));
            }
            else{
                strcpy(hh,h);
            }
            if(strlen(m)<=1){
                strcpy(mm,strcat(zero,m));
            }
            else{
                strcpy(mm,m);
            }
            if(strlen(s)<=1){
                strcpy(ss,strcat(zero,s));
            }
            else{
                strcpy(ss,s);
            }
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
        char* _name;
        bool _isapproval;
    public:
        TimeTable(){};
        TimeTable(char* n1,char* y1,char* m1,char* a1,char* b1,char* c1,char* d1,char* y2,char* m2,char* a2,char* b2,char* c2,char* d2):_name(n1),_start(y1,m1,a1,b1,c1,d1),_end(y2,m2,a2,b2,c2,d2){
            _isapproval=false;
        };
        bool intersect(const TimeTable&  tb);
        bool operator<=(const TimeTable& tb);
        void changeapproval();
        friend ostream& operator<<(ostream& out,TimeTable& tb){
            if(tb._isapproval)
                printGreen("Approved");
            else
                printRed("Waiting for approval");
            return out<<"Name:"<<tb._name<<"\nTime:"<<tb._start<<"   ->"<<tb._end<<endl;
        }
        inline char* get_name() const { return _name; }
};

#endif
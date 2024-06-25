#ifndef TIMETABLE
#define TIMETABLE

#include"inc.h"
#include"ColorPrint.hpp"
using namespace std;

class Time{
    private:
        char yy[5],MM[3],dd[3],hh[3],mm[3],ss[3];
    public:
        Time():yy(""),MM(""),dd(""),hh(""),mm(""),ss(""){};
        void set(char* y,char* M,char* d,char* h,char* m,char* s){
            if(strlen(y)<=1){
                char zero[5]="0";
                strcat(zero,y);
                strcpy(yy,zero);
            }
            else{
                strcpy(yy,y);
            }
            if(strlen(M)<=1){
                char zero[3]="0";
                strcat(zero,M);
                strcpy(MM,zero);
            }
            else{
                strcpy(MM,M);
            }
            if(strlen(d)<=1){
                char zero[3]="0";
                strcat(zero,d);
                strcpy(dd,zero);
            }
            else{
                strcpy(dd,d);
            }
            if(strlen(h)<=1){
                char zero[3]="0";
                strcat(zero,h);
                strcpy(hh,zero);
            }
            else{
                strcpy(hh,h);
            }
            if(strlen(m)<=1){
                char zero[3]="0";
                strcat(zero,m);
                strcpy(mm,zero);
            }
            else{
                strcpy(mm,m);
            }
            if(strlen(s)<=1){
                char zero[3]="0";
                strcat(zero,s);
                strcpy(ss,zero);
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
            out<<tb.yy<<"/"<<tb.MM<<"/"<<tb.dd<<" "<<tb.hh<<":"<<tb.mm<<":"<<tb.ss<<endl;
            return out;
        }
};

class TimeTable{
    private:
        Time _start,_end;
        bool _isapproval;
    public:
        char _name[20];
        TimeTable():_name(""),_isapproval(false){};
        TimeTable(char* n1){
            strcmp(_name,n1);
            _isapproval=false;
        };
        void setstart(){
            char y1[5] ="",M1[3] ="",d1[3] ="",h1[3] ="",m1[3] ="",s1[3] ="";
            system("clear");  
            cout<<"输入起始时间(yyyy/mm/dd hh:mm:ss): ";
            cin>>y1;cin>>M1;cin>>d1;cin>>h1;cin>>m1;cin>>s1;
            _start.set(y1,M1,d1,h1,m1,s1);
        }
        void setend(){
            char y1[5] ="",M1[3] ="",d1[3] ="",h1[3] ="",m1[3] ="",s1[3] =""; 
            cout<<"输入结束时间(yyyy/mm/dd hh:mm:ss): ";
            cin>>y1;cin>>M1;cin>>d1;cin>>h1;cin>>m1;cin>>s1;
            _end.set(y1,M1,d1,h1,m1,s1);
        }
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
};

#endif
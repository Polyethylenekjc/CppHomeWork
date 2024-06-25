#include "../inc/TimeTable.h"

bool Time::operator==(const Time & t){
    return yy==t.yy&&MM==t.MM&&dd==t.dd&&hh==t.hh&&mm==t.mm&&ss==t.ss;
}

bool Time::operator!=(const Time & t){
    return !((*this)==t);
}

bool Time::operator<(const Time & t)
{
    if(strcmp(yy,t.yy)>0)
        return false;
    if(strcmp(MM,t.MM)>0)
        return false;
    if(strcmp(hh,t.hh)>0)
        return false;
    if(strcmp(hh,t.hh)>0)
        return false;
    if(strcmp(mm,t.mm)>0)
        return false;
    if(strcmp(ss,t.ss)>0)
        return false;
    return true;
}

bool Time::operator>(const Time & t){
    if(strcmp(yy,t.yy)<0)
        return false;
    if(strcmp(MM,t.MM)<0)
        return false;
    if(strcmp(hh,t.hh)<0)
        return false;
    if(strcmp(hh,t.hh)<0)
        return false;
    if(strcmp(mm,t.mm)<0)
        return false;
    if(strcmp(ss,t.ss)<0)
        return false;
    return true;
}

bool Time::operator<=(const Time & t){
    return *(this)<t||*(this)==t;
}

bool Time::operator>=(const Time & t){
    return *(this)>t||*(this)==t;
}


bool TimeTable::intersect(const TimeTable & tb){
    return !(this->_end<=tb._start||this->_start>=tb._end);
}

bool TimeTable::operator<=(const TimeTable & tb){
    return this->_end<=tb._start;
}
void TimeTable::changeapproval(){
    this->_isapproval=!this->_isapproval;
}
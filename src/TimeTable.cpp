#include "../inc/TimeTable.h"
#include "TimeTable.h"

bool Time::operator==(const Time & t){
    return dd==t.dd&&hh==t.hh&&mm==t.mm&&ss==t.ss;
}

bool Time::operator!=(const Time & t){
    return !((*this)==t);
}

bool Time::operator<(const Time & t)
{
    if(dd>t.dd)
        return true;
    if(hh>t.hh)
        return true;
    if(mm>t.mm)
        return true;
    if(ss>t.ss)
        return true;
    return false;
}

bool Time::operator>(const Time & t){
    if(dd>t.dd)
        return true;
    if(hh>t.hh)
        return true;
    if(mm>t.mm)
        return true;
    if(ss>t.ss)
        return true;
    return false;
    return false;
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
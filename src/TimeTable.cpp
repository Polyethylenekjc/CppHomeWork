#include "../inc/TimeTable.h"

bool Time::operator==(const Time & t){
    return yy==t.yy&&MM==t.MM&&dd==t.dd&&hh==t.hh&&mm==t.mm&&ss==t.ss;
}

bool Time::operator!=(const Time & t){
    return !((*this)==t);
}

bool Time::operator<(const Time & t)
{
    if(yy>t.yy)
        return false;
    if(MM>t.MM)
        return false;
    if(dd>t.dd)
        return false;
    if(hh>t.hh)
        return false;
    if(mm>t.mm)
        return false;
    if(ss>t.ss)
        return false;
    return true;
}

bool Time::operator>(const Time & t){
    if(yy<t.yy)
        return false;
    if(MM<t.MM)
        return false;
    if(dd<t.dd)
        return false;
    if(hh<t.hh)
        return false;
    if(mm<t.mm)
        return false;
    if(ss<t.ss)
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
#include "../inc/ClassRoom.h"
#include "ClassRoom.h"


void ClassRommBase::addAttribute(string k1, string k2){
     _attribute[k1]=k2;
}

void ClassRommBase::eraseAttribute(string k1){
    _attribute.erase(k1);
}

void ClassRommBase::addBooklist(std::string n1,int a1,int b1,int c1,int d1,int a2,int b2,int c2,int d2){
    TimeTable temp(n1,a1,b1,c1,d1,a2,b2,c2,d2);
    auto i=_booklist.begin();
    if(_booklist.getLen()==-1){
        _booklist.insert(temp);
        return;
    }
    for(;i!=nullptr;i++){
        if(temp<=(*i).data&&!temp.intersect((*i)._last->data)){
            break;
        }
    }
    if(!i.getptr()){
        cerr<<"Error!Appointment overlap\n";
        return;
    }
    _booklist.insert(temp,i);
}

void ClassRommBase::showBooklist(){
    _booklist.show();
}

#ifndef CLASSROOM
#define CLASSROOM

#include"DoubleLinkedList.hpp"
#include"TimeTable.h"
#include<map>
#include<string>

class ClassRommBase{
    protected:
        map<string,string> _attribute;
        DoubleLinkedList<TimeTable> _booklist;
    public:
        ClassRommBase(){};
        void addnewattribute(string k1,string k2){
            _attribute[k1]=k2;
        }
        void eraseattribute(string k1){
            _attribute.erase(k1);
        }
}; 


#endif
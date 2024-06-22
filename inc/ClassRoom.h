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
        void addAttribute(string k1,string k2);
        void eraseAttribute(string k1);
        void addBooklist(std::string n1,int a1,int b1,int c1,int d1,int a2,int b2,int c2,int d2);
        void showBooklist();
}; 


#endif
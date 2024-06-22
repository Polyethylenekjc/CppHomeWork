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
        void eraseBooklist(string k1);
        void addBooklist(std::string n1,string y1,string m1,string a1,string b1,string c1,string d1,string y2,string m2,string a2,string b2,string c2,string d2);
        void showBooklist();
        void shouwAttribute();
}; 


#endif
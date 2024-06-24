#ifndef CLASSROOM
#define CLASSROOM

#include"inc.h"
#include<map>
using namespace std;

class ClassRommBase{
    protected:
        map<string,string> _attribute;
        DoubleLinkedList<TimeTable> _booklist;
        static bool cmp(string n1,const TimeTable& t1){
            return n1==t1.get_name(); 
        }
    public:
        ClassRommBase(){};
        void addAttribute(string k1,string k2);
        void eraseAttribute(string k1);
        void eraseBooklist(string k1);
        void addBooklist(std::string n1,string y1,string m1,string a1,string b1,string c1,string d1,string y2,string m2,string a2,string b2,string c2,string d2);
        void showBooklist();
        void shouwAttribute();
        void adminapproval(User userlogin);
}; 


#endif
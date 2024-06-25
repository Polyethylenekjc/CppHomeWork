#ifndef CLASSROOM
#define CLASSROOM

#include"inc.h"
#include"ColorPrint.hpp"
using namespace std;

struct Attribute{
    char map[20]="",key[20]="";
    friend ostream& operator<<(ostream& out,Attribute& att){
        return out<<"属性名:"<<att.map<<"\n属性值:"<<att.key;
    }
};

class ClassRommBase{
    protected:
        Attribute _attributelist[20];
        TimeTable _booklist[20];
        int idxAttribute=0,idxBooklist=0;
    public:
        char _name[20];
        ClassRommBase():_name(""){};
        void addAttribute(char *k1,char *k2);
        void eraseAttribute(char *k1);
        void eraseBooklist(char* k1);
        void addBooklist(char* name);
        void showBooklist();
        void ShowAttribute();
        void adminApproval(User userlogin);
        friend ostream& operator<<(ostream& out,ClassRommBase& crb){
            out<<"ClassRoom:"<<crb._name<<endl;
            char key[2]="";
            cout<<"\nShow Attribute?(Yes:y):";
            cin>>key;

            if(strcmp(key,"y")==0)
                crb.ShowAttribute();
            cout<<"\nShow Booklist?(Yes:y):";
            cin>>key;
            if(strcmp(key,"y")==0)
                crb.showBooklist();
            return out;
        }
}; 


#endif
#include"DoubleLinkedList.hpp"
#include"ClassRoom.h"
using namespace std;

int main(){
    DoubleLinkedList<ClassRommBase> classlist;
    classlist.resize(1);
    classlist[0].addBooklist("kjc","2025","6","15","12","30","0","2025","6","15","13","00","00");
    classlist[0].showBooklist();
    User admin("kjc","123456",0);
    classlist[0].adminapproval(admin);
    classlist[0].showBooklist();
}
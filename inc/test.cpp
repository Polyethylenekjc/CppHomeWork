#include"ClassRoom.h"

int main(){
    DoubleLinkedList<ClassRommBase> classlist;
    classlist.resize(2);
    classlist[1].addBooklist("kjc","2025","6","15","12","30","0","2025","6","15","13","00","00");
    classlist[1].addBooklist("kjc","2025","6","15","12","30","0","2025","6","15","13","00","00");
    classlist[1].showBooklist();
}
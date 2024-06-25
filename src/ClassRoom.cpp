#include "../inc/ClassRoom.h"


void ClassRommBase::addAttribute(char* k1,char* k2){
    strcpy(_attributelist[idxAttribute].map,k1);
    strcpy(_attributelist[idxAttribute++].key,k2);
}

void ClassRommBase::eraseAttribute(char* k1){
    int i=0;
    for(;i<idxAttribute;i++){
        if(strcmp(_attributelist[i].map,k1)==0)
            break;
    }
    for(++i;i<20;i++){
        _attributelist[i-1]=_attributelist[i];
    }
}

void ClassRommBase::eraseBooklist(char* k1){
    int i=0;
    for(;i<idxBooklist;i++){
        if(strcmp(_booklist[i]._name,k1)==0)
            break;
    }
    for(++i;i<20;i++){
        _booklist[i-1]=_booklist[i];
    }
}

void ClassRommBase::addBooklist(char *name){
    TimeTable temp;
    strcpy(temp._name,name);
    temp.setstart();
    temp.setend();
    _booklist[idxBooklist++]=temp;
}

void ClassRommBase::showBooklist(){
    for(int i=0;i<idxBooklist;i++)
        cout<<_booklist[i];
}

void ClassRommBase::ShowAttribute(){
    for(int i=0;i<idxAttribute;i++)
        cout<<_attributelist[i];
}

void ClassRommBase::adminApproval(User userlogin){
    system("clear");
    cout<<"-------------------Approval--------------------\n";
    if(userlogin.get__level()!=0){
        return printMagenta("Permission denied");}
    this->showBooklist();
    cout<<"\n\n-----Choose the Approval Target-----\n";
    char temp[999]="";
    cin>>temp;
    for(int i=0;i<strlen(temp);i++){
        int idx=(temp[i]-'0')-1;
        if(idx==-1)
            return;
        _booklist[idx].changeapproval();
    }
}
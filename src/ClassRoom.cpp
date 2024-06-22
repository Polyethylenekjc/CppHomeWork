#include "../inc/ClassRoom.h"


void ClassRommBase::addAttribute(string k1, string k2){
     _attribute.insert(pair<string,string>(k1,k2));
}

void ClassRommBase::eraseAttribute(string k1){
    _attribute.erase(k1);
}

void ClassRommBase::eraseBooklist(string k1){
    _booklist.erase(_booklist.search(k1,cmp));
}

void ClassRommBase::addBooklist(string n1,string y1,string m1,string a1,string b1,string c1,string d1,
string y2,string m2,string a2,string b2,string c2,string d2){
    TimeTable temp(n1,y1,m1,a1,b1,c1,d1,y2,m2,a2,b2,c2,d2);
    auto i=_booklist.begin();
    if(_booklist.getLen()==-1){
        _booklist.insert(temp);
        return;
    }
    for(;i!=nullptr;i++){
        if(temp<=(*i).data&&(!(*i)._last?true:!temp.intersect((*i)._last->data))){
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

void ClassRommBase::shouwAttribute(){
    for(auto iter:_attribute){
        cout<<iter.first<<"\t"<<iter.second<<endl;
    }
}

void ClassRommBase::adminapproval(User userlogin){
    system("clear");
    if(userlogin.get__level()!=0)
        return printMagenta("Permission denied");
    this->showBooklist();
    cout<<"\n\n-----Choose the Approval Target-----\n";
    string temp;
    cin>>temp;
    for(auto i:temp){
        int idx=(i-'0')-1;
        _booklist[idx].changeapproval();
    }
}
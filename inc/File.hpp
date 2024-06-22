#ifndef FILEOPERATE
#define FILEOPERATE

#include<fstream>
#include<string>
#include<iostream>
using namespace std;

template<typename T,typename U>
class FileOperate{
    private:
        string _dir;
        bool isinit;
    public:
        FileOperate();
        FileOperate(string dir);
        bool write(T& elem);
        bool read(T& elem);
        void set_dir(string dir);
};

template<typename T,typename U>
FileOperate<T,U>::FileOperate():_dir(""),isinit(false){}

template<typename T,typename U>
FileOperate<T,U>::FileOperate(string dir):_dir(dir),isinit(true){
}

template<typename T,typename U>
bool FileOperate<T,U>::write(T& elem){
    if(!isinit){
        cerr<<"Error!Empty dir path\n";
        return false;
    }
    ofstream obin;
    obin.open(_dir);
    for(auto iter=elem.begin();;iter++){
        U temp=iter.getptr()->data;
        obin.write(reinterpret_cast<char*>(&temp),sizeof(U));
        if(iter==elem.end())
            break;
    }
    return true;
}

template<typename T,typename U>
bool FileOperate<T,U>::read(T & elem){
    ifstream ibin;
    ibin.open(_dir);
    if(!isinit||!ibin.is_open()){
        cerr<<"Error!Empty dir path\n";
        return false;
    }
    U temp;
    while(!ibin.eof()){ 
        ibin.read(reinterpret_cast<char*>(&temp),sizeof(U));
        elem.push_back(temp);
        if(ibin.eof()){
            elem.erase(elem.end());
            break;
        }
    }
    return true;
}

template<typename T,typename U>
void FileOperate<T,U>::set_dir(string dir){
    this->_dir=dir;
    this->isinit=true;
}

#endif
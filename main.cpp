#include"inc/DoubleLinkedList.hpp"
#include"inc/File.hpp"
#include<algorithm>
#include<string>
using namespace std;

class test{
    string  x,y;
    public:
    test(){};
    test(test& t){
        x=t.x;y=t.y;
    }
    test(string x,string y):x(x),y(y){};
    friend ostream& operator<<(ostream& out,test& t){
        return out<<"x="<<t.x<<"\ty="<<t.y;
    }
    friend istream& operator>>(istream& in,test& t){
        return in>>t.x>>t.y;
    }
    bool operator==(test &t){
        return this->x==t.x&&this->y==t.y;
    }
};


int main(){
    DoubleLinkedList<test> t;
    FileOperate<DoubleLinkedList<test>,test> f("test.dat");
    t.push_back({"一二三四","孔佳宸"});
    f.write(t);
    f.read(t);
    t.show();
    return 0;
}







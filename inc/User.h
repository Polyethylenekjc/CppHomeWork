#ifndef USER
#define USER

#include"inc.h"
using namespace std;

class User{
    private:
        int _hash,_level;
        string _username;
        int StringtoHash(const string& n){
            int res=0,M=1e9+7,B=133;
            for(auto i:n){
                res=((long long)res*B+i)&M;
            }
            return res;
        }
    public:
        User(){};
        User(string username,string key,int level=-1):_username(username),_hash(this->StringtoHash(key)),_level(level){};
        bool login(string key){
            return _hash==this->StringtoHash(key);
        };
        inline int get__level() const { return _level; }
};

#endif
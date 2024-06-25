#ifndef _MYUI_
#define _MYUI_
#include"ClassRoom.h"
#include<vector>
using namespace std;

class MyUi{
    private:
        DoubleLinkedList<User> _userlist;
        DoubleLinkedList<ClassRommBase> _classlist;
        FileOperate<DoubleLinkedList<ClassRommBase>,ClassRommBase> _f_classlist;
        FileOperate<DoubleLinkedList<User>,User> _f_userlist;
        int _opt;
        User _user;
        DoubleLinkedList<ClassRommBase>::iterator _classroom;
        bool _islogin,_isselect;
        static bool cmp(char* name,User u){
            return strcmp(name,u._username)==0;
        }
    public:
        MyUi():_isselect(false),_islogin(false),_opt(-1){
            char temp[]="/mnt/e/Code/Homework/data/user.dat";
            _f_userlist.set_dir(temp);
            _f_userlist.readfromfile(_userlist);

        };
        bool UIlogin(){
            sleep(1); 
            while(!_islogin){
                system("clear");
                cout<<"------------------Login Menu------------------\n";
                cout<<"                   1 注册                     \n";
                cout<<"                   2 登录                     \n";
                cout<<"                   0 退出                     \n";
                int opt;
                cin>>opt;
                switch(opt){
                    case 0:return false;break;
                    case 1:_register();break;
                    case 2:login();break;
                    default: printRed("Error!Please enter right idx");
                }
                sleep(1);
            }
            return true;
        }
        void login(){
            while(1){
                system("clear");
                cout<<"--------------------Login---------------------\n";
                cout<<"   UserName:";
                char name[20]="",password[20]="",isadmin[]="admin";
                cin>>name;
                cout<<"   Password:";
                cin>>password;
                if(strcmp(name,isadmin)==0&&strcmp(password,isadmin)==0){
                    User admin(isadmin,isadmin,0);
                    _user=admin;
                    _islogin=true;
                    return printGreen("   Successfully login");
                }
                auto iter=_userlist.search(name,cmp);
                bool ctrl=true;
                if(iter.getptr()==nullptr){
                ctrl=false;
                }
                if(ctrl&&(*iter).data.login(password)){
                    _islogin=true;
                    _user=(*iter).data;
                    return printGreen("   Successfully login");
                }
                else{
                    printRed("   Incorrect username or password");
                }
                sleep(1);
            }
        }
        void _register(){
            system("clear");
            cout<<"-------------------Register--------------------\n";
            cout<<"   UserName:";
            char name[20]="",password[20]="";
            cin>>name;
            cout<<"   Password:";
            cin>>password;
            if(_userlist.search(name,cmp).getptr()!=nullptr){
                printRed("Error!Account already exists");
                sleep(1);
                return;
            }
            User temp(name,password,1);
            _userlist.push_back(temp);
        }
        void adminempowerment(){
            system("clear");
            cout<<"------------------Empowerment------------------\n";
            if(_user.get__level()!=0)
                return printMagenta("Permission denied");
            _userlist.show();
            cout<<"\n\n---------选择提权序号---------\n";
            char temp[999]="";
            cin>>temp;
            cout<<"\n\n----------输入权值----------\n";
            cout<<"管理员:0 教师:1 审核员:2\n";
            int n;
            cin>>n;
            for(int i=0;i<strlen(temp);i++){
                int idx=(temp[i]-'0')-1;
                if(idx==-1)
                    return;
                _userlist[idx].empowerment(n);
            }
        }
        void newclassroom(){
            _classlist.addnewnode(1);
            ClassRommBase *iter=(*(_classlist.end())).pointer();
            char name[20],key1[20],key2[20];
            int i=0;
            system("clear");
            cout<<"输入教室名:";
            cin>>iter->_name;
            cout<<"教室属性数量:";
            cin>>i;
            while(i--){
                cout<<"输入属性名:";
                cin>>key1;
                cout<<"输入属性值:";
                cin>>key2;
                iter->addAttribute(key1,key2);
                cout<<endl;
            }
            printGreen("Successfully create");
        }
        static bool cmp2(char* key,ClassRommBase classroom){
            return strcmp(key,classroom._name)==0;
        }
        void selectclassroom(){
            auto iter=_classlist.begin();
            while(1){
                cout<<"输入教室名:";
                char key1[20];
                cin>>key1;
                iter=_classlist.search(key1,cmp2);
                if(iter==nullptr){
                    printRed("Error!No classroom");
                    return;
                }
                else break;
            }
            _classroom=iter;
            _isselect=true;
            cout<<"Successfully select:";
            printShine((*_classroom).data._name);
        }
        void UIeditclassroom(){
            while(1){
                system("clear");
                if(!_isselect)
                    return printRed("Error!No classroom selected");
                cout<<"----------------Edit Clossroom----------------\n";
                cout<<"------------------1 更改教室名----------------\n";
                cout<<"------------------2 增加属性------------------\n";
                cout<<"------------------3 删除属性------------------\n";
                cout<<"------------------0 退出----------------------\n";
                int opt;
                cin>>opt;
                switch(opt){
                    case 0:return;break;
                    case 1:cout<<"输入教室名";cin>>_classroom.getptr()->data._name;printGreen("Success");break;
                    case 2:{
                        int i;char key1[20],key2[20];
                        cout<<"教室属性数量:";
                        cin>>i;
                        while(i--){
                            cout<<"输入属性名:";
                            cin>>key1;
                            cout<<"输入属性值:";
                            cin>>key2;
                            _classroom.getptr()->data.addAttribute(key1,key2);
                            cout<<endl;
                            printGreen("Success");
                        }break;
                    }
                    case 3:cout<<"输入要删除的属性名:";char key[20];cin>>key;_classroom.getptr()->data.eraseAttribute(key);printGreen("Success");break;
                    default: printRed("Error!Please enter right idx");
                }
                sleep(1);
            }
        }
        void UIclasslist(){
            while(1){
                system("clear");
                cout<<"-----------------Classroom Menu----------------\n";
                cout<<"                 1  新建教室                  \n";
                cout<<"                 2  选定教室                  \n";
                cout<<"                 3  编辑教室                  \n";
                cout<<"                 4  删除教室                  \n";
                cout<<"                 5  输出所选教室              \n";
                cout<<"                 6  显示所有教室              \n";
                cout<<"\n-----------------Book Menu--------------------\n";
                cout<<"                 7  审核预约                  \n";
                cout<<"                 8  预约教室                  \n";
                cout<<"                 9  输出预约                  \n";
                cout<<"                 10 删除预约                  \n";
                cout<<"\n-----------------File Menu--------------------\n";
                cout<<"                 11 从文件读取                \n";
                cout<<"                 12 保存到文件                \n";
                cout<<"\n-----------------Other Menu-------------------\n";
                cout<<"                 13 管理员权限更改            \n";
                cout<<"                 14 删除账户                  \n";
                cout<<"                 0  退出                      \n";
                cout<<"\n\n输入功能序号:";
                int opt;
                cin>>opt;
                char stop;
                switch(opt){
                    case 0:return;
                    case 1:{
                        if(_user.get__level()==0)  
                            newclassroom();
                        else
                            printMagenta("Permission denied");
                    }break;
                    case 2:selectclassroom();break;
                    case 3:{
                        if(_user.get__level()==0)  
                            UIeditclassroom();
                        else
                            printMagenta("Permission denied");
                    }break;
                    case 4:{
                        if(_isselect){
                            if(_user.get__level()==0)  
                                  _classlist.erase(_classroom);
                            else
                                printMagenta("Permission denied");
                        }
                        else
                            printRed("Error!No classroom selected");
                    }break;
                    case 5:{
                        if(_isselect){
                            cout<<(_classroom._ptr->data);cout<<"Press C To Continue...\n";cin>>stop;
                        }
                        else    
                            printRed("Error!No classroom selected");
                    }break;
                    case 6:system("clear");_classlist.show();cout<<"Press C To Continue...\n";cin>>stop;break;
                    case 7:
                    {   
                        if(_user.get__level()==1){
                            printMagenta("Permission denied");
                            break;
                        }
                        else{
                            system("clear");
                            int acc=0;
                            for(auto iter=_classlist.begin();iter!=nullptr;iter++){
                                cout<<"Number:"<<++acc<<endl;
                                cout<<"Name:"<<iter._ptr->data._name<<endl;
                                iter._ptr->data.adminApproval(_user);
                            }
                        }
                    }break;
                    case 8:{
                        if(_isselect){
                            _classroom.getptr()->data.addBooklist(_user._username);
                        }
                        else
                            printRed("Error!No classroom selected");
                    }break;
                    case 9:system("clear");_classroom._ptr->data.showBooklist();cout<<"Press C To Continue...\n";cin>>stop;break;
                    case 10:{
                        if(_isselect){
                            _classroom.getptr()->data.eraseBooklist(_user._username);
                        }
                        else
                            printRed("Error!No classroom selected");
                    }break;
                    case 11:readclasslistfromfile();break;
                    case 12:saveclasslisttofile();break;
                    case 13:adminempowerment();break;
                    case 14:{   
                        if(_user.get__level()!=0){
                            printMagenta("Permission denied");
                            break;
                        }
                        else{
                            system("clear");
                            _userlist.show();
                            cout<<"\n\n---------选择删除序号---------\n";
                            char temp[999]="";
                            cin>>temp;
                            for(int i=0;i<strlen(temp);i++){
                                int idx=(temp[i]-'0')-1;
                                if(idx==-1)
                                    return;
                                _userlist.erase(idx);
                            }
                        }
                    }break;
                    default: printRed("Error!Please enter right idx");
                }
                sleep(1);
            }
        }
        void readclasslistfromfile(){
            char dd[]="/mnt/e/Code/Homework/data/";
            char input[50]="";char opt;
            cout<<"默认文件名为用户名,使用自定义文件名?(yes/y):";
            cin>>opt;
            char *dir;
            if(opt=='y'){
                cout<<"请输入文件名:";
                cin>>input;
                dir=strcat(dd,input);
            }
            else dir=strcat(dd,_user._username);
            _f_classlist.set_dir(dir);
            _f_classlist.readfromfile(_classlist);
        } 
        void saveclasslisttofile(){
            char dd[]="/mnt/e/Code/Homework/data/";
            char input[50]="";char opt;
            cout<<"默认文件名为用户名,使用自定义文件名?(yes/y):";
            cin>>opt;
            char *dir;
            if(opt=='y'){
                cout<<"请输入文件名:";
                cin>>input;
                dir=strcat(dd,input);
            }
            else dir=strcat(dd,_user._username);
            _f_classlist.set_dir(dir);
            _f_classlist.savetofile(_classlist);
        }
        ~MyUi(){
            char dd[]="/mnt/e/Code/Homework/data/";
            char *dir=strcat(dd,_user._username);
            _f_classlist.set_dir(dir);
            _f_classlist.savetofile(_classlist);
            _f_userlist.savetofile(_userlist);
        }
};
#endif

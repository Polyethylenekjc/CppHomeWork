#include"../inc/ColorPrint.h"

template <typename T>
inline void printRed(T data){
    cout<<RED<<data<<CLEAR<<endl;
}


template<typename T>
void printGreen(T data){
    cout<<GREEN<<data<<CLEAR<<endl;
}


template<typename T>
void printMagenta(T data){
    cout<<MAGENTA<<data<<CLEAR<<endl;
}
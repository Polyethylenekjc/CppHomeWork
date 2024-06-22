#ifndef CLASSROOM
#define CLASSROOM

#include"DoubleLinkedList.hpp"
#include"TimeTable.h"

class ClassRommBase{
    protected:
        int _type,_number,_size;
        DoubleLinkedList<TimeTable> booklist;
    public:
        
        void set__type(const int &_type) {
            this->_type = _type; 
        }
        void set__number(const int &_number) {
            this->_number = _number; 
        }
        void set__size(const int &_size) {
            this->_size = _size;       
        }
}; 


#endif
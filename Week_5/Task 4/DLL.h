
#include "Node.h"

#ifndef DLL_H
#define DLL_H

class DLL {
    public:
        DLL();
        ~DLL();

        int size;
        Node* head;
        Node* tail;

        bool isEmpty();
        void pushHead(Student data); 
        void pushTail(Student data);
        void popHead();
        void popTail();
        void print(std::string id);
        void push(int position, Student data);
        void pop(std::string id);
};

#endif
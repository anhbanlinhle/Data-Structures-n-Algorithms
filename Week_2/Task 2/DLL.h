
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
        void pushHead(int data); 
        void pushTail(int data);
        void popHead();
        void popTail();
        void print();
        void push(int position, int data);
        void pop(int position);
};

#endif
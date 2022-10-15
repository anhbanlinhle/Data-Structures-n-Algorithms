
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
        void print();
        void push(int position, int data);
        int countTriplet();
};

#endif
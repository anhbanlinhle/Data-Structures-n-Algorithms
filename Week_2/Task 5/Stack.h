#include "Node.h"

#ifndef STACK_H
#define STACK_H

class Stack {
    public:
        Stack();
        ~Stack();

        int size;
        Node* head;
        Node* tail;

        bool isEmpty();
        void push(int data); 
        void pop();
        void print();      
};

#endif

#include "Node.h"

#ifndef QUEUE_H
#define QUEUE_H

class Queue {
    public:
        Queue();
        ~Queue();

        int size;
        Node* head;
        Node* tail;

        bool isEmpty();
        void enqueue(int data);
        void dequeue();
        void print();
        
};

#endif
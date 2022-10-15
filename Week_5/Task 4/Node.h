
#ifndef NODE_H
#define NODE_H
#include "Student.h"

class Node{
    public:
        Node();
        ~Node();

        Node(Student x);
        Student data;
        Node* next;
        Node* prev;
};

#endif
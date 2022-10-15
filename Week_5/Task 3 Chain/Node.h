
#ifndef NODE_H
#define NODE_H

class Node{
    public:
        Node();
        ~Node();

        Node(int x);
        int data;
        Node* next;
        Node* prev;
};

#endif
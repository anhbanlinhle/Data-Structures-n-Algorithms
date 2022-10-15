#include "Node.h"
#include "Libs.h"

Node::Node() {
    Student temp;
    data = temp;
    next = NULL;
    prev = NULL;
}

Node::~Node() {
}

Node::Node(Student x) {
    data = x;
    next = NULL;
    prev = NULL;
}

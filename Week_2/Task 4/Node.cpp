#include "Node.h"
#include "Libs.h"

Node::Node() {
    data = 0;
    next = NULL;
    prev = NULL;
}

Node::~Node() {
}

Node::Node(int x) {
    data = x;
    next = NULL;
    prev = NULL;
}

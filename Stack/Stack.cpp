#include "Stack.h"
#include "Libs.h"

Stack::Stack() {
    size = 0;
    head = NULL;
    tail = NULL;
}

Stack::~Stack() {

}

bool Stack::isEmpty() {
    return (head == NULL || tail == NULL);
}

void Stack::push(int data) {
    Node* temp = new Node(data);

    if (isEmpty()) {
        head = temp;
        tail = temp;
        size++;
        return;
    }
    head->prev = temp;

    temp->next = head;
    head = temp;

    size++;
}

void Stack::pop() {
    if (isEmpty()) {
        std::cout << "STACK UNDERFLOW";
        return;
    }

    head = head->next;
    head->prev = NULL;

    size--;
}

void Stack::print() {
    if (isEmpty())
        return;
    
    Node* temp = tail;
    while (temp != NULL) {
        std::cout << " " << temp->data << " ";
        temp = temp->prev;
    }
}
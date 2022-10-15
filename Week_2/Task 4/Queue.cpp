#include "Queue.h"
#include "Libs.h"

Queue::Queue() {
    size = 0;
    head = NULL;
    tail = NULL;
}

Queue::~Queue() {

}

bool Queue::isEmpty() {
    return (head == NULL || tail == NULL);
}

void Queue::enqueue(int data) {
    Node* temp = new Node(data);

    if(isEmpty()) {
        head = temp;
        tail = temp;
        size++;
        return;
    }
    tail->next = temp;

    temp->prev = tail;
    tail = temp;

    size++;
}

void Queue::dequeue() {
    if (isEmpty())
        return;

    head = head->next;
    head->prev = NULL;

    size--;
}

void Queue::print() {
    if (isEmpty())
        return;
    
    Node* temp = head;
    while (temp != NULL) {
        std::cout << " " << temp->data << " ";
        temp = temp->next;
    }
}

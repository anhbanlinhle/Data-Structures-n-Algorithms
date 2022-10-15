#include "DLL.h"
#include "Libs.h"

DLL::DLL() {
    size = 0;
    head = NULL;
    tail = NULL;
}

DLL::~DLL() {

}

bool DLL::isEmpty() {
    return (head == NULL || tail == NULL);
}

void DLL::pushHead(int data) {
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

void DLL::pushTail(int data) {
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

void DLL::print() {
    if (isEmpty())
        return;
    
    Node* temp = head;
    while (temp != NULL) {
        std::cout << " " << temp->data << " ";
        temp = temp->next;
    }
}

void DLL::push(int position, int data) {
    if (position < 0 || position > size) {
        std::cout << "INVALID POSITION";
        return;
    }

    if (position == 0) {
        pushHead(data);
        return;
    }

    if (position == size) {
        pushTail(data);
        return;
    }

    Node* temp = new Node(data);
    Node* scan = head;

    for (int i = 1; i < position; i++)
        scan = scan->next;

    temp->next = scan->next;  
    scan->next = temp;  
    temp->prev = scan;  
    
    temp->next->prev = temp; 
    size++;
}

int DLL::countTriplet() {
    int count = 0;
    Node* node1, node2, node3;

    for (Node* node1 = head; node1 !=0; node1 = node1->next)
        for (Node* node2 = node1->next; node2 != 0; node2 = node2->next)
            for (Node* node3 = node2->next; node3 != 0; node3 = node3->next)
                if (node1->data + node2->data + node3->data == 0)
                    count++;
    return count;
}
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

void DLL::pushHead(Student data) {
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

void DLL::pushTail(Student data) {
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

void DLL::popHead() {
    if (isEmpty())
        return;

    head = head->next;
    head->prev = NULL;

    size--;
}

void DLL::popTail() {
    if (isEmpty())
        return;

    tail = tail->prev;
    tail->next = NULL;

    size--;
}

void DLL::print(std::string id_) {
    if (isEmpty())
        return;
    
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data.id == id_) {
            std::cout << temp->data.info() << "\n";
            return;
        }
        temp = temp->next;
    }
    Student fake = Student();
    std::cout << fake.info() << "\n";
}

void DLL::push(int position, Student data) {
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

void DLL::pop(std::string id_) {
    int position = 0;
    Node* temp = head;
    for (int i = 0; i < size; i++) {
        if (temp->data.id == id_)
            break;
        position++;
        temp = temp->next;
    }
    if (position < 0 || position > size - 1) {
        return;
    }

    if (position == 0) {
        popHead();
        return;
    }

    if (position == size - 1) {
        popTail();
        return;
    }

    Node* del = head;

    for (int i = 0; i < position; i++)
        del = del->next;
 
    del->next->prev = del->prev; 
    del->prev->next = del->next; 
    size--;
    free(del);
}
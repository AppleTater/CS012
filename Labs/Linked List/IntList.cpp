#include "IntList.h"
#include <iostream>
#include <cstdlib>

using namespace std;

//  int data;
//     IntNode *next;
//     IntNode(int data) : data(data), next(nullptr) { }
// };

IntList::IntList(){
    head = nullptr;
    tail = nullptr;
}

IntList::~IntList(){
    for(IntNode *current = head; current != nullptr; current = current->next) {
        delete current;
    }
}

void IntList::push_front(int value) {
    IntNode *temp = head;
    head = new IntNode(value);
    head->next = temp;
    
    if(tail == nullptr) {
        tail = head;
    }
}

void IntList::pop_front() {
    if (head == nullptr) {
          return;
    }
    IntNode * temp = head;
    head = head->next;
    delete temp;
}

bool IntList::empty() const{
    if (head == nullptr) {
        return true;
    }
    else {
        return false;
    }
}

const int & IntList::front() const{
    return head->data;
}

const int & IntList::back() const{
    return tail->data;
}

ostream & operator<<(ostream &out, const IntList &rhs){
    for(IntNode *current = rhs.head; current != nullptr; current = current->next) {
        if (current == rhs.tail) {
            out << current->data;
        }
        else {
            out << current->data << " ";
        }
    }
//     out << tail->data;
    
    return out;
}

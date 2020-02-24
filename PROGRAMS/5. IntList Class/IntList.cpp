/*
You are required to come up with a single header file (IntList.h) that declares and implements the IntNode class 
(just copy it exactly as it is below) as well as declares the IntList Class interface only. 
You are also required to come up with a separate implementation file (IntList.cpp) that implements the 
member functions of the IntList class. While developing your IntList class you must write your own test harness 
(within a file named main.cpp). Never implement more than 1 or 2 member 
functions without fully testing them with your own test harness.
*/



------
#include "IntList.h"
#include <iostream>
#include <cstdlib>

using namespace std;

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
    for(IntNode *currentNode = rhs.head; currentNode != nullptr; currentNode = currentNode->next) {
        if (currentNode == rhs.tail) {
            out << currentNode->data;
        }
        else {
            out << currentNode->data << " ";
        }
    }
    return out;
}

 IntList::IntList(const IntList &cpy) {
//the copy constructor. Make sure this performs deep copy   
     head = nullptr;
     tail = nullptr;
     if (cpy.head == nullptr) {
         head = nullptr;
         tail = nullptr;
     }
     
     else {
         for (IntNode *current = cpy.head; current != nullptr; current = current->next) {
             push_back(current->data);
         }
     }
 }

IntList & IntList::operator=(const IntList &rhs) {
//the overloaded assignment operator. Make sure this performs deep copy
    if (rhs.head == nullptr) {
        head = nullptr;
    }
    
    if (this != &rhs) {
        head = nullptr;
        tail = nullptr;
        
        for (IntNode *copy = rhs.head; copy != nullptr; copy = copy->next) {
            this ->push_back(copy->data);
        }
    }
    return *this;
}

void IntList::push_back(int value) {
//Inserts a data value (within a new node) at the back end of the list
    if (head != nullptr) {
        IntNode *temp = new IntNode(value);
        tail->next = temp;
        tail = temp;
    }
    else {
        head = new IntNode(value);
        tail = head;
    }
}

void IntList::clear() {
//Removes (deallocates) all IntNodes in the IntList. Don't forget to set both head and tail to appropriate values for an empty list
    for (IntNode *currentNode = head; currentNode != nullptr; currentNode = currentNode ->next) {
        pop_front();
    }
    
}

void IntList::selection_sort(){
//Sorts the integers in the list into ascending order. Do NOT move the nodes, just the integers
    for (IntNode *i = head; i != 0; i = i->next) {
        int min = i->data;
        for (IntNode *j = i->next; j != 0; j = j->next) {
            if(j->data < min) {
                min = j->data;
                j->data = i->data;
                i->data = min;
            }
        }
    }
}

void IntList::insert_ordered(int value) {
//Inserts a data value (within a new node) in an ordered list. Assumes the list is already sorted in ascending order (i.e., Do not sort the list first, assume the list is already is sorted.) This function loops through the list until if finds the correct position for the new data value and then inserts the new IntNode in that location. This function may NOT ever sort the list
    IntNode *insertValue = new IntNode(value);
    if (head == nullptr) {
        push_front(value);
    }
    
    else if (value < (head->data)) {
        push_front(value);
    }
    
    else if (value >= (tail->data)) {
        push_back(value);
    }
    
    else {
        for (IntNode *previous = head; previous != tail; previous = previous->next) {
            IntNode *current = previous->next;
            if(value <= (current->data)) {
                previous->next = insertValue;
                insertValue->next = current;
                return;
            }
        }
    }
}


void IntList::remove_duplicates() {
//Removes all duplicate data values (actually removes the nodes that contain the values) within the list. Always remove just the later value within the list when a duplicate is found. This function may NOT ever sort the list
    for (IntNode *i = head; i != 0; i = i->next) {
        int match = i->data;
        IntNode *previous = i;
        for(IntNode* j = i->next; j != 0;) {
            if (match == j->data && j->next != 0) {
                previous->next = j->next;
                delete j;
                j = previous;
            }
            
            else if(match == j->data && j == tail) {
                tail = previous;
                delete j;
                tail->next = 0;
            }
            
            if (j == previous) {
                j = j->next;
            }
            
            else {
                j = j->next;
                previous = previous->next;
            }
        }
    }
}

#include "IntList.h"

#include <ostream>

using namespace std;

IntList::IntList() : head(0) {}


void IntList::push_front(int val) {
   if (!head) {
      head = new IntNode(val);
   } else {
      IntNode *temp = new IntNode(val);
      temp->next = head;
      head = temp;
   }
}



bool IntList::exists(int value) const {
    if (this->head != nullptr) {
        return this->exists(this->head, value);
    }
    return false;
}

bool IntList::exists(IntNode *node, int num) const {
    if (node->data != num) {
        if (node->next == nullptr) {
            return false;
        }    
        else {
            return exists(node->next, num);
        }
    }
    
    else {
        return true;
    }
}

ostream & operator<<(ostream &out, const IntList &list){
   if (list.head == nullptr) {
       return out;
   } 

    out << list.head->data;
    return operator<<(out, list.head->next);
}

ostream & operator<<(ostream &out, IntNode *node) {
    if (node == nullptr) {
        return out;
    }
    
    else {
        out << " ";
    }
    
    out << node->data;
    return operator<<(out, node->next);
}

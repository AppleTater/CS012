#include "IntVector.h"
#include <iostream>
#include <cstdlib>
#include <stdexcept>

using namespace std;

//Constructors and Accessors
IntVector::IntVector() {
    sz = 0;
    cap = 0;
    data = nullptr;
}

IntVector::IntVector(unsigned size, int value) {
    sz = size;
    cap = size;
    data = new int[size];
    
    for (unsigned int i = 0; i < size; i++) {
        data[i] = value;
    }
}

unsigned IntVector::size() const {
    return sz;
}

unsigned IntVector::capacity() const {
    return cap;
}

bool IntVector::empty() const {
    if (sz != 0){
        return false;
    }
    else {
        return true;
    }
}

const int & IntVector::at(unsigned index) const {
    if (index >= sz) {
        throw out_of_range("IntVector::at_range_check");
    }
    
    else {
        return data[index];
    }
}

const int & IntVector::front() const {
    return data[0];
}

const int & IntVector::back() const {
    if (size() != 0) {
        return data[sz - 1];
    }
    else {
        return data[sz];
    }
}

// Destructor, Mutators, and Private Helper Functions

IntVector::~IntVector() {
    delete[] data;
}

void IntVector::expand(){
//     int *temp = data;
//     cap *= 2;
    
//     if (cap == 0) {
//         cap = 1;
//         data = new int[cap];
//     }
    
//     else {
//         data = new int [cap];
//         for (unsigned int i = 0; i < sz; i++) {
//             data[i] = temp[i];
//         }
//     }
    int tempData[sz];
    
    for (unsigned int i = 0; i < sz; ++i) {
        tempData[i] = data[i];
    }
    
    delete[] data;
    
    if (cap == 0) {
        data = new int[1];
        for (unsigned int i = 0; i < sz; ++i) {
            data[i] = tempData[i];
        }
        cap = 1;
    }
    else {
        data = new int[2 * cap];
        for (unsigned int i = 0; i < sz; ++i) {
            data[i] = tempData[i];
        }
        cap = 2 * cap;
    }
}

void IntVector::expand(unsigned x) {
//     int *temp = data;
//     if (cap == 0) {
//         cap = x;
        
//         data = new int [cap];
//     }
    
//     else {
//         cap = x;
        
//          data = new int [cap];
//         for (unsigned int i = 0; i < sz; i++) {
//             data[i] = temp[i];
//         }
//     }
    int tempData[sz];
    
    for (unsigned int i = 0; i < sz; ++i) {
        tempData[i] = data[i];
    }
    
    delete[] data;
    
    data = new int[cap + x];
    for (unsigned int i = 0; i < sz; ++i) {
        data[i] = tempData[i];
    }
    cap = cap + x;
}  

void IntVector::insert(unsigned index, int value) {
    if (index > sz) {
                throw out_of_range("IntVector::insert_range_check");
            }
              
                sz = sz + 1;
                
                if (cap < sz) {
                    expand();
                }
               
                for (unsigned int i = sz - 1; i > index; i--) {

                        data[i] = data[i - 1];
                }
                data[index] = value; 
}

void IntVector::erase(unsigned index) {
    if (index >= sz) {
                throw out_of_range("IntVector::erase_range_check");
            }
            for (unsigned int i = index; i+1 < sz; i++) {
                
                data[i] = data[i+1];
            }
           sz -= 1;
}

void IntVector::push_back(int value) {
    if (sz >= cap) {
        expand();
    }
    sz += 1;
    
    data[sz - 1] = value;
}

void IntVector::pop_back(){
    sz = sz - 1;
}

void IntVector::clear(){
    sz = 0;
}

void IntVector::resize(unsigned size, int value) {
    if (size < sz) {
        sz = size;
    }
                
    if (size > sz) {
        unsigned temp = sz;
        sz = size;
        
        if (sz > (2*cap)) {
            expand(sz);
        }
        
        else if (size > cap){
                expand();
        }
                    
        for (unsigned int i = temp; i < sz; i++) {
            data[i] = value;
            cout << data[i] << endl;
        }
    }        
} 

void IntVector::reserve(unsigned n) {
    if (n > cap) {
        cap = n;
    }
}
   
void IntVector::assign(unsigned n, int value) {
    if (n <= cap) {
        sz = n;
        for (unsigned int i = 0; i < sz; i++) {
            data[i] = value;
        }
    }
    
    if (n > (2 * cap)) {
        expand(n);
        sz = n;
        for (unsigned int i = 0; i < sz; i++) {
            data[i] = value;
        }
    }
    
    else if (n > cap) {
        expand();
        sz = n;
        for (unsigned int i = 0; i < sz; i++) {
            data[i] = value;
        }
    }
}

int & IntVector::at(unsigned index) {
    if (index >= sz) {
        throw out_of_range("IntVector::at_range_check");
    }
    
    else {
        return data[index];
    }
}

int & IntVector::front() {
    return data[0];
}


int & IntVector::back() {
    if (size() != 0) {
        return data[sz - 1];
    }
    else {
        return data[sz];
    }
}

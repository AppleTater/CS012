#include "IntVector.h"
#include <iostream>
#include <cstdlib>

using namespace std;

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

IntVector::~IntVector() {
    delete[] data;
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
    
    return data[index];
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

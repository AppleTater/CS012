/*
You are going to build a smaller, simpler version of the STL vector class that is capable of only storing integers. 
Appropriately, it will be called IntVector. This class will encapsulate a dynamically allocated array of integers.

You are required to come up with a header file (IntVector.h) that declares the class interface and a separate implementation 
file (IntVector.cpp) that implements the member functions. You will also create a test harness (main.cpp) 
that you use to test each function you are currently developing.

Never implement more than 1 or 2 functions without compiling and unit testing them before moving on.

The final test harness (main.cpp) file should include all of the tests you performed on each member function. 
Feel free to comment out previous tests while you are working on later member functions. However, 
the final test harness should test ALL of your member functions thoroughly. zyBooks will not grade your main function. 
However, we will spot check the assignments and take off points for any PROGRAM that does 
not have this test harness in the main.cpp file.
*/



------
#include <iostream>
#include "IntVector.h"

using namespace std;

void testingValues(IntVector test) {
    cout << "Size: " << test.size() << endl;
    cout << "Capacity: " << test.capacity() << endl;
    
    if (!test.empty()) {
        for (unsigned int i = 0; i < test.size(); i++) {
            cout << i + 1 << ".)" << test.at(i) << endl;
        }
    }
    else {
        cout << "The vector is empty" << endl;
    }
    cout << endl;
}

void testingPushBack(IntVector test) {
    cout << "Default" << endl;
    testingValues(test);
    
    for (unsigned int i = 0; i < 5; i++) {
        cout << "Push Back " << i << endl;
        test.push_back(i);
        testingValues(test);
    }
}

void testingPopBack(IntVector test) {
    for (int i = 0; i < 3; i++) {
        test.pop_back();
        cout << "Pop Back" << endl;
        testingValues(test);
    }
}

void testingAt(IntVector test) {
    cout << "First" << endl;
    cout << test.at(0) << endl;
    
    cout << "Last" << endl;
    cout << test.at(test.size() - 1) << endl;
    
    cout << "Front" << endl;
    cout << test.front() << endl;
    
    cout << "Back" << endl;
    cout << test.back() << endl;
}

void testingAssign(IntVector test) {
    cout << "Size = 4, Values = 0" << endl;
    test.assign(4, 0);
    testingValues(test);
    
    cout <<"Size = 6, Values = 6" << endl;
    test.assign(6, 6);
    testingValues(test);
}

void testingInsert(IntVector test) {
    cout << "At position 2, insert the value 3" << endl;
    test.insert(2, 3);
    testingValues(test);
    
    cout << "At position 0, insert the value 6" << endl;
    test.insert(0, 6);
    testingValues(test);
}

void testingErase(IntVector test) {
    cout << "Erase position 2" << endl;
    test.erase(1);
    testingValues(test);
    
    cout << "Erase position 0" << endl;
    test.erase(0);
    testingValues(test);
}

void testingResize(IntVector test) {
    cout << "Resize to 6" << endl;
    test.resize(6);
    testingValues(test);
    
    cout << "Resize to 10" << endl;
    test.resize(10);
    testingValues(test);
    
    cout << "Resize to 6, fill all with value of 5" << endl;
    test.resize(6, 5);
    testingValues(test);
    
    cout << "Resize to 10, fill all with value of 7" << endl;
    test.resize(10, 7);
    testingValues(test);
}

void testingReserve(IntVector test) {
    cout << "Expand to 6" << endl;
    test.reserve(6);
    testingValues(test);
    
    cout << "Expand to 30" << endl;
    test.reserve(30);
    testingValues(test);
}

// void testingVector() {
//     vector <int> vec;
//     vec.push_back(45);
//     cout << vec.size() << " : " << vec.capacity() << endl;
// }

int main() {
    IntVector test;
//     testVector();
    testingPushBack(test);
    testingReserve(test);
    testingResize(test);
    testingInsert(test);
    testingErase(test);
    testingAssign(test);
    testingAt(test);
    testingPopBack(test);
}

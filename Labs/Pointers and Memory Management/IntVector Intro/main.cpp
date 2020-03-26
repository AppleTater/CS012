#include <iostream>
#include "IntVector.h"

using namespace std;

int main() {
    int i = 0;
    IntVector test01;
    IntVector test02 (1, i);
    IntVector *test03 = new IntVector;
    IntVector test04 (0, i);
    
    cout << "Testing IntVector() Expected: 0 0, Actual: " << test01.size() << " " << test01.capacity() << endl;
    
    cout << "Testing IntVector (unsigned size, int value = 0): Expected: 1 1, Actual: " << test02.size() << " " << test02.capacity() << endl;
    
    cout << "Testing ~IntVector(): ";
    delete test03;
    
    if (&test03->front() == nullptr) {
        cout << "Test Successful" << endl;;
    }
    
    cout << "Testing size(): Expected: 0, Actual: " << test04.size() << endl;
    
    cout << "Testing capacity(): Expected: 0, Actual: " << test04.capacity() << endl;
    
    cout << "Testing empty(): Empty: ";
    if (test01.empty() == true) {
        cout << "Passed ";
    }
    else {
        cout << "Failed";
    }
    cout << "Not Empty";
    
//     IntVector testAt(10, i);
//     cout << test.at(10) << endl;
    
    if (test04.at(3) == 0) {
        cout << "Testing at(): Expected: 0, Actual:  " << test04.at(3) << endl;
    }
    
    if (test04.front() != 0) {
        cout << "Testing front(): Expected: 0, Actual: " << test04.front() << endl;
    }
    
    if (test04.back() != 0) {
        cout << "Testing back(): Expected: 0, Actual: " << test04.back() << endl;
    }
    
    
}

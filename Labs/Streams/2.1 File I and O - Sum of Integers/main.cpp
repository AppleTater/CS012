/*
Implement the function fileSum. fileSum is passed in a name of a file. 
This function should open the file, sum all of the integers within this file, close the file, and then return the sum.

If the file does not exist, this function should output an error message and then call the exit 
function to exit the program with an error value of 1.
*/



------
#include <fstream>
#include <iostream>
#include <cstdlib> //needed for exit function

using namespace std;

// Place fileSum prototype (declaration) here
int fileSum (const string& fileName);

int main() {
    string filename;
    int y;
    cout << "Enter the name of the input file: ";
    cin >> filename;
    cout << endl;
    y = fileSum(filename);
    if (y == 1) {
        cout << "Error opening " << filename << endl;
    }
    else {
        cout << "Sum: " << y << endl;
    }
    return 0;
}

// Place fileSum implementation here
int fileSum(const string& fileName) {
    int sum = 0;
    int x = 0;
    ifstream inFile;
    inFile.open(fileName);
    
    if (!inFile.is_open()) {
      return 1;
    }
   
    while (inFile >> x) {
      sum = sum + x;
    }
    inFile.close();
    return sum;
}

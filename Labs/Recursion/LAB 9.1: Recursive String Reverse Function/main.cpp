#include <iostream>
#include <string>

using namespace std;


void flipString(string &s);

int main() {
   string line;
   cout << "Enter a sentence:" << endl;
   getline(cin, line);
   cout << endl;
   cout << line << endl;
   flipString(line);
   cout << line << endl;

   return 0;
}

//Implement the flipString function here

void flipString(string &s) {
    string newS;
    
    if(s.size() <= 1) {
        return;
    }
    
    char tempFront = s.front();
    char tempBack = s.back();
    
    swap(s.front(), s.back());
    newS = s.substr(1, s.size() - 2);
    
    flipString(newS);
    
    s = tempBack + newS;
    s.push_back(tempFront);
}


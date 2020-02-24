/*Implement the function charCnt. charCnt is passed in a name of a file and a single character (type char). 
This function should open the file, count the number of times the character is found within the file, close the file, 
and then return the count.
*/


------
#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

// Place charCnt prototype (declaration) here
int charCnt (const string& filename, const char x); 

int main() {
   string filename;
   ifstream inFS;
   char ch;
   int chCnt = 0;
   
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << endl;
   cout << "Enter a character: ";
   cin.ignore(); // ignores newline left in stream after previous input statement
   cin.get(ch);
   cout << endl;

   chCnt = charCnt(filename, ch);
   inFS.open(filename);

   if (inFS.is_open()) {
       cout << "# of " << ch << "'s: " << chCnt << endl;
    }

   return 0;
}

// Place charCnt implementation here
int charCnt (const string& filename, const char x) {
   int count = 0;
   ifstream inFS;
   char fileChar;
    
   inFS.open(filename);
    
   if (!inFS.is_open()) {
       cout << "Error opening " << filename << endl;
       return 1;
   }
   while (inFS.get(fileChar)) {
       if (fileChar == x) {
           count ++;
       }
   }
   inFS.close();
   return count;
}

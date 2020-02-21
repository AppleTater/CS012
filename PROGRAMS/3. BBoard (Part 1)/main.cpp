/*
In this assignment you will create an extremely rudimentary bulletin board with a simple command-line interface (like in the old days!).

This will require three collaborating classes - BBoard, User, and Message. 
For the moment, the bulletin board will exist only inside the test harness (i.e. we won't store it to the file system yet), 
so you will construct a single BBoard object (giving it an appropriate title - e.g. "Jack's Amazing Bulletin Board"), 
and then invoke its methods.

First, you will "load it up" with a set of authorized Users (read in from a file);

then you will ask the user to log in with a username and password, which you will check against the list you just read in;

and then you will "run" the board: the program will enter a sentinel-controlled loop asking the user 
to choose from a menu of actions (corresponding, obviously, to BBoard's other public methods)

- list all current posts
- create a new post
- quit the system
*/


------
#include <iostream>
#include <string>

using namespace std;

#include "BBoard.h"

int main(int argc, char *argv[]) {
   
   string userfile = argv[1];
   
   BBoard bb("CS12 Bulletin Board");
   
   // load users from file
   if (!bb.loadUsers(userfile)) {
      cout << "Error loading users from file " << userfile << endl;
      return 1;
   }
   if (!bb.login()) {
      cout << "Login not successful" << endl;
      return 1;
   }
   bb.run();

   return 0;
}

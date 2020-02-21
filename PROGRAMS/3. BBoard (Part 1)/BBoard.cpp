#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Message.h"
#include "User.h"
#include "BBoard.h"

using namespace std;

//Public

// Constructs a board with a default title, 
// empty user & message lists, 
// and the "default" User
BBoard::BBoard(){
    title = "";
    userList = userList;
    currentUser = User();
    messageList = messageList;
}

// Same as the default constructor except 
// it sets the title of the board
BBoard::BBoard(const string &ttl) {
    title = ttl;
    userList = userList;
    currentUser = User();
    messageList = messageList;
}

// Imports all the authorized users from an input file, 
// storing them as User objects in the vector userList
// The name of the input file is passed in as a parameter to this function. 
// See below for file format.
bool BBoard::loadUsers(const string &filename) {
    User usertopush;
    ifstream fileIn;
    string username;
    string password;
    
    fileIn.open(filename.c_str());
    
    if(!fileIn.is_open()) {
        return false;
    }
    
    while(fileIn >> username >> password) {
        if(username != "end")
        {
            usertopush = User(username, password);
            userList.push_back(usertopush);
        }
    }
    fileIn.close();
    
    return true;
}

// Asks for and validates a user/password.
// Always asks for both user and password combo unless 'q' or 'Q' entered.
// Checks userList to validate user and password.
// If valid, sets currentUser to this User, outputs welcome message, 
// then returns true.
// Otherwise outputs error message and then repeats request
// for username/password.
// Continues until valid user/password 
// or until 'q' or 'Q' is entered for username.
// If 'q' or 'Q' is entered, does not ask for password, outputs "Bye!"
// and then returns false.
bool BBoard::login(){
    cout << "Welcome to " << title << endl;
    string user;
    string pass;
    cout << "Enter your username ('Q' or 'q' to quit): ";
    cin >> user;
    if ((user == "q") || (user== "Q")){
        cout << endl;
        cout << "Bye!" << endl;
        return false;
    }
    while ((user != "q") || (user!= "Q")){
         cout << endl << "Enter your password: ";
         cin >> pass;
         cout << endl;
         bool check = false;
         for (unsigned int i = 0; i < userList.size(); ++i){
            
            if  (userList.at(i).check(user, pass) == true){
                currentUser = userList.at(i);
                cout << "Welcome back " << user << "!" << endl;
                cout << endl;
                check = true;
                return true;
            }
    }
        if (check == false){
            cout << "Invalid Username or Password!" << endl;
            cout << endl;
            cout << "Enter your username ('Q' or 'q' to quit): ";
            cin >> user;
            if ((user == "q") || (user== "Q")){
                cout << endl;
                cout << "Bye!" << endl;
                return false;
        }
    }
} 
        return false;

}
// Contains main loop of Bulletin Board.
// First verifies a User has been logged in.
// Exits **function** immediately if no User logged in (Default User).
// Continues to display menu options to user and performs requested action
// until user chooses to quit.
// See output samples for exact format of menu.
void BBoard::run() {
    char action;
    bool stop = false;
    
    while(!stop) {
        cout << "Menu" << endl;
        cout << "- Display Messages ('D' or 'd')" << endl;
        cout << "- Add New Message ('N' or 'n')" << endl;
        cout << "- Quit ('Q' or 'q')" << endl;
        cout << "Choose an action: ";
        cin >> action;
        cout << endl;
        
        if(action == 'D' || action == 'd') {
            //Display message with display()
            display();
        }
        else {
            if(action == 'N' || action == 'n') {
                //Add message with addMessage()
                addMessage();
            }
            else {
                if(action == 'Q' || action == 'q') {
                    cout << "Bye!";
                    cout << endl;
                    return;
                }
            }
        }
    }
}

//Private

void BBoard::display() const {
    Message currentMsg;
    
    if(messageList.empty()) {
        cout << "Nothing to Display." << endl;
        cout << endl;
    }
    else {
        for(unsigned x = 0; x < messageList.size(); x++) {
            currentMsg = messageList.at(x);
            cout << "---------------------------------------------------------" << endl;
            cout << "Message #" << x + 1 << ": ";
            currentMsg.display();
            cout << endl;
        } 
        
        cout << "---------------------------------------------------------" << endl;
        cout << endl;
    }
}

void BBoard::addMessage() {
    string tempMessage;
    string tempSubject;
    string tempBody;
    string name;
    
    cout << "Enter Subject: ";
    cin.ignore();
    getline(cin, tempSubject);
    cout << endl;
    
    cout << "Enter Body: ";
    getline(cin, tempBody);
    cout << endl;
    
    name = currentUser.getUsername();
    messageList.push_back(Message(name, tempSubject, tempBody));
    
    cout << "Message Recorded!" << endl;
    cout << endl;
}

bool BBoard::userExists(const string &user, const string &pass) const {
    if(user != "" || pass != "")
        return true;
    
    return false;
}

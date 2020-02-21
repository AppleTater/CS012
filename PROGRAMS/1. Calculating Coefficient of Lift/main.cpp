/*PROGRAM Steps
1. Get from the command line the name of the file that contains the wind tunnel data.

2. Read wind-tunnel data into two parallel vectors, one vector stores the flight-path angle and the other stores 
the corresponding coefficient of lift for that angle. Both vectors should store doubles.

3. Ask the user for a flight-path angle. If the angle is within the bounds of the data set, 
the program should then use linear interpolation (see explanation of linear interpolation below) 
to compute the corresponding coefficient of lift and output it.

4. Finally, ask the user if they want to enter another flight-path angle. Repeat steps 3 and 4 
if they answer Yes, otherwise end the program if they answer No.

For linear interpolation to work, the flight-path angles in the data file must be in ascending order. 
If the flight-path angles are not in ascending order, your program will need to sort them before implementing Step 3.*/



------
#include <iostream>
#include <vector>
#include <fstream>
#include <bits/stdc++.h>
#include <sstream>
#include <string>

using namespace std;

void readData(const string &dataFile, vector<double> &angle, vector<double> &lift);
bool isOrdered(const vector<double> &angle);
void reorder(vector<double> &angle, vector<double> &lift);
double interpolation(double angleB, const vector<double> &angle, const vector<double> &lift);


int main (int argc, char *argv[]){
    string dataFile;
    vector <double> angle;
    vector <double> lift;
    double angleB;
    string answer;
    
    dataFile = argv[1];
    
    ifstream inFS;
    
    readData(dataFile, angle, lift);
    
    if (!isOrdered(angle)) {
       reorder(angle, lift);
    }
    
    double min = angle.at(0);
    double max = angle.at(angle.size() - 1);
    
    cin >> angleB;
    
    if (angleB <= max && angleB >= min) {
        cout << interpolation(angleB, angle, lift);
    }
    
    cin >> answer;
    
    while (answer == "Yes") {
        cin >> angleB;
        if (angleB <= max && angleB >= min) {
            cout << interpolation(angleB, angle, lift);
    }
     cin >> answer;
    }
    
    inFS.close();
    
    return 0;
}

void readData(const string &dataFile, vector<double> &angle, vector<double> &lift) {
    ifstream inFS;

    double numAngle;
    double numLift;
    
    inFS.open(dataFile);
    
    if (!inFS.is_open()) {
        cout << "Error opening " << dataFile << endl;
        exit (1);
    }

    while (inFS >> numAngle) {
        inFS >> numLift;
        angle.push_back(numAngle);
        lift.push_back(numLift);
    }
    inFS.close();
}

void reorder (vector<double> &angle, vector <double> &lift) {
    int minimum;
    for (unsigned int i = 0; i < angle.size(); i++) {
        for (unsigned int j = i + 1; j < angle.size(); j++) {
            if (angle.at(i) > angle.at(j)){
                minimum = j;
                swap (angle.at(i), angle.at(minimum));
                swap (lift.at(i), lift.at(minimum));
            }
        }
    }
}

bool isOrdered(const vector<double>& angle) {
   if(!angle.empty()) {
       for(unsigned i = 0; i + 1 < angle.size(); i++) {
           if(angle.at(i) > angle.at(i + 1)) {
               return false;
           }
       }
   }
   return true;
}

double interpolation(double angleB, const vector<double>& angle, const vector<double>& lift) {
    double liftB = 0;
    double liftReturn;
    
    for (unsigned int i = 0; i < angle.size(); i++) {
        if (angleB == angle.at(i)) {
            liftReturn = lift.at(i);
        }
    }
    for (unsigned int j = 0; j < angle.size(); j++) {
        if (angleB > angle.at(j)) {
            liftB = lift.at(j) + ((angleB - angle.at(j)) / (angle.at(j + 1) - angle.at(j))) * (lift.at(j + 1) - lift.at(j));
            liftReturn = liftB;
        }
    }
    return liftReturn;
}

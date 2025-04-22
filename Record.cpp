#include "Record.hpp"

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

Record::Record() {
    nUsers = 0;
    userData = vector<User>{};
}

Record::Record(vector<User> data) {
    for (int i = 0; i < data.size(); i++) {
        this->nUsers++;
    }
    this->userData = data;
}

void Record::addUser(string name) {
    User newUser = User(name);
    userData.push_back(newUser);
    this->nUsers = userData.size();
}

void Record::print(){
    cout << "Users:" << endl;
    for (int i = 0; i < nUsers; i++) {
        cout << userData[i].getName() << " | ";
        cout << "W:" << userData[i].getWins() << "/";
        cout << "L:" << userData[i].getLosses() << " | ";
        cout << "admin: ";
        if (userData[i].isAdmin()) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}

void Record::saveFile(string filename, string name) {
    ofstream outfile( filename, ios::binary );

    //check if file opened
    if (!outfile) {
        cout << "Error: could not open user record." << endl;
        return;
    }

    // save record of user
}
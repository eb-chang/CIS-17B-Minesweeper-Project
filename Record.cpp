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

int Record::getnUsers() {
    return this->nUsers;
}

void Record::addUser(User newUser) {
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

void Record::saveFile(string filename) {
    ofstream outfile( filename, ios::binary | ios::out );

    //check if file opened
    if (!outfile) {
        cout << "Error: could not open user record for saving." << endl;
        return;
    }

    // save number of users in record;
    outfile.write(reinterpret_cast<char*>(&nUsers), sizeof(nUsers));

    // save record of user
    for (int i = 0; i<userData.size(); i++) {
        userData[i].save(outfile);
    }

    outfile.close();
}

void Record::loadFile(string filename) {
    ifstream infile( filename, ios::binary | ios::in );

    //check if file opened
    if (!infile) {
        cout << "Error: could not open user record for loading." << endl;
        return;
    }

    //load number of users
    infile.read(reinterpret_cast<char *>(&this->nUsers), sizeof(this->nUsers));

    //initialize user record
    this->userData = vector<User>(this->nUsers);

    //load all users into record
    for (int i = 0; i < nUsers; i++) {
        userData[i].load(infile);
    }
    infile.close();
}
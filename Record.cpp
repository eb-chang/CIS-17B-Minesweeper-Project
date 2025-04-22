#include "Record.hpp"

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

Record::Record(int n) {
    this->nUsers = n;
    users = new User[nUsers];
}

void Record::addUser(string name) {
    nUsers++;
    User *u = &this->users[nUsers]; // temp holder

    u->setName(name); // set username
    u->setWins(0);
    u->setLosses(0);
    u->setAdmin(false);
}

void Record::print(){
    cout << "Users:" << endl;
    for (int i = 0; i < nUsers; i++) {
        cout << users[i].getName() << " | ";
        cout << "W:" << users[i].getWins() << "/";
        cout << "L:" << users[i].getLosses() << " | ";
        cout << "admin: ";
        if (users[i].isAdmin()) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}

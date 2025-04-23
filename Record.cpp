#include "Record.hpp"

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

// constructors
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

//getters
int Record::getnUsers() {
    return this->nUsers;
}

vector<User> Record::getUserData() {
    return this->userData;
}

//functions
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

int Record::searchFor(string name) {
    // search through userData vector to find a User based on input name.
    //    return index of User if found,
    //    return -1 if User is not found. 
    for (int i = 0; i < nUsers; i++) {
        if (userData.at(i).getName() == name) {
            return i;
        } else {
            return -1;
        }
    }
    return -1;
}

User Record::at(int n) {
    return userData.at(n);
}

User Record::login() {
    string name;
    int position;

    cout << "Welcome! Please enter a username: ";

    // do not let the user enter an empty string as a username
    do {
        getline(std::cin, name);
        if (name == "") {
            cout << "Error - Please enter a valid username: ";
        }
    } while (name == "");
    
    // search if user exists
    position = searchFor(name);
    User loginUser;

    // if user is not in record, create a record for user.
    if (position == -1) {
        cout << "User not found. Creating a new user for " << name << "." << endl;
        loginUser = User(name);
        addUser(loginUser);
        return loginUser;

    // if user is found in record 
    } else { 
        cout << "User found. Welcome back, " << name << "!" << endl;
        loginUser = userData.at(position);
        return loginUser;
    }
}

void Record::deleteUser(string name) {
    // search for user in record
    int position = searchFor(name);

    // if user exists, erase the user and decrement nUsers.
    if (position != -1) {
        userData.erase(userData.begin()+position);
        nUsers = userData.size();
        return; 

    // if user does not exist, return.
    } else {
        cout << "User \"" << name << "\" not found." << endl;
        return; 
    }

    return;
}

// I/O functions
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
#include "User.hpp"

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

//constructors;
User::User() {
    this->username = "";
    this->wins = 0;
    this->losses = 0;
    this->admin = false;
}

User::User(string name) {
    this->username = name;
    this->wins = 0;
    this->losses = 0;
    this->admin = false;
}

User::User(string name, int nWins, int nLosses, bool adminStatus) {
    this->username = name;
    this->wins = nWins;
    this->losses = nLosses;
    this->admin = adminStatus;
}


//setters
void User::setName(string name) {
    this->username = name;
}

void User::setWins(int nWins) {
    this->wins = nWins;
}

void User::setLosses(int nLosses) {
    this->losses = nLosses;
}

void User::setAdmin(bool adminStatus) {
    this->admin = adminStatus;
}

//getters
string User::getName() {
    return this->username;
}

int User::getWins() {
    return this->wins;
}

int User::getLosses() {
    return this->losses;
}

bool User::isAdmin() {
    return this->admin;
}

// to be used in Record Class
void User::save(ofstream &outfile) {
    // no need to check if file is open, file should already be
    // successfully open when this function is run.

    // save user data
    // 1. save username
    int nameLen = this->username.size(); // get length of username
    outfile.write(reinterpret_cast<const char*>(&nameLen), sizeof(nameLen)); //write out name length (int, so 4 bytes)
    outfile.write(username.c_str(), nameLen); //write out array of char representing username

    // 2. save # wins
    outfile.write(reinterpret_cast<char *> (&wins), sizeof(wins));

    // 3. save # losses
    outfile.write(reinterpret_cast<char *>(&losses), sizeof(losses));

    // 4. save admin status
    outfile.write(reinterpret_cast<char*>(&admin), sizeof(admin));

    // done!
    // no need to close file, the function that User::save is used in will close the file.
}

void User::load(ifstream &infile) {
    // no need to check if file is open, file should already be
    // successfully open when this function is run.

    // load user data
    // 1. load username
    int nameLen;
    infile.read(reinterpret_cast<char*>(&nameLen), sizeof(nameLen)); //read in # of chars for name
    char *tempName = new char[ nameLen + 1]; //new char* with +1 space for null terminator
    infile.read(tempName, nameLen); //read at tempName start address, for nameLen characters
    tempName[nameLen] = '\0'; //put null terminator at end of tempName array
    this->username = tempName; //put temp name into username member
    delete [] tempName; //done and dusted.

    // 2. load number of wins
    infile.read(reinterpret_cast<char*>(&this->wins), sizeof(this->wins));

    // 3. load number of losses
    infile.read(reinterpret_cast<char*>(&this->losses), sizeof(this->losses));

    // 4. load admin status
    infile.read(reinterpret_cast<char*>(&this->admin), sizeof(this->admin));

    // done!
    // no need to close file, the function that User::load is used in will close the file.
}
// to be used in Record class
void User::saveUser(string filename) {
    ofstream outfile(filename, ios::binary | ios::out | ios::app); //set binary flag
    
    //check if file opened
    if (!outfile) {
        cout << "File open error for save." << endl;
        return;
    }

    // save user data

    // 1. save username
    int nameLen = this->username.size(); // get length of username
    outfile.write(reinterpret_cast<char *>( &nameLen), sizeof(nameLen)); // what is this doing? check lecture.
    outfile.write(this->username.c_str(), nameLen); // write out username

    // 2. save number of wins
    outfile.write(reinterpret_cast<char *> (&wins), sizeof(wins));

    // 3. save number of losses
    outfile.write(reinterpret_cast<char *> (&losses), sizeof(losses));

    // 4. save admin status
    outfile.write(reinterpret_cast<char*>(&admin), sizeof(admin));

    // done with save.
    outfile.close();
}

void User::loadUser(string filename) {
    ifstream infile(filename, ios::binary);

    // make sure file opens
    if (!infile) {
        cout << "File open error for load." << endl;
        return;
    }

    //read file info

    // 1. read username
    int nameLen;
    infile.read(reinterpret_cast<char*>(&nameLen), sizeof(nameLen)); // read in # of chars for name
    char *tempName = new char[nameLen + 1]; // new char* with space for null terminator
    infile.read(tempName, nameLen); //read at tempName start address, for nameLen characters 
    tempName[nameLen] = '\0'; // place null terminator at end of temp name array
    this->username  = string(tempName);
    delete [] tempName;

    // 2. load number of wins
    infile.read(reinterpret_cast<char*>(&this->wins), sizeof(this->wins));

    // 3. load number of losses
    infile.read(reinterpret_cast<char*>(&this->losses), sizeof(this->losses));

    // 4. load admin status
    infile.read(reinterpret_cast<char*>(&this->admin), sizeof(this->admin));

    // done loading!
    infile.close();
}
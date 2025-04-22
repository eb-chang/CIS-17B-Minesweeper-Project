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

void User::saveFile(string filename) {
    ofstream outfile(filename, ios::binary); //set binary flag
    
    //check if file opened
    if (!outfile) {
        cout << "File open error" << endl;
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
}
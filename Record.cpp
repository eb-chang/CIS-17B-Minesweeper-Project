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
    nUsers = data.size();
    userData = data;
}

//getters
int Record::getnUsers() {
    return nUsers;
}

vector<User> Record::getUserData() {
    return userData;
}

//functions
void Record::addUser(User newUser) {
    userData.push_back(newUser);
    nUsers = userData.size();
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

void Record::editUser(User user) {
    int choice;

    // do while choice != 5.
    cout << "What would you like to modify for " << user.getName() << "?" << endl;
    cout << "1. Edit username" << endl;
    cout << "2. Edit number of wins" << endl;
    cout << "3. Edit number of losses" << endl;
    cout << "4. Edit admin status" << endl;
    cout << "5. Quit" << endl;

    //INPUT VALIDATION HERE
    cin >> choice;
    switch (choice) {
        case 1: {
            string newname;
            cout << "Enter a new username: ";
            getline(std::cin, newname);
            user.setName(newname);
            cout << "Username set to " << newname << "." << endl;
        }
        case 2:
            int n;
            cout << "Enter the number of wins that " << user.getName() << " has: ";
            cin >> n;
            user.setWins(n);
            cout << user.getName() << " now has " << n << " wins." << endl;
        
        case 3:
            int n;
            cout << "Enter the number of losses that " << user.getName() << " has:";
            cin >> n;
            user.setLosses(n);
            cout << user.getName() << " now has " << n << " losses." << endl;
       
        case 4:
            int adminChoice;
            if (!user.isAdmin()) {
                cout << "Would you like to give " << user.getName() << " admin status?";
                cout << "1. Yes" << endl;
                cout << "2. No" << endl;
                // VALIDATION HERE!
                cin >> adminChoice;
                if (adminChoice == 1) {
                    user.setAdmin(true);
                } else if (adminChoice == 2) {
                    // don't change ad status
                }
                
            } if (user.isAdmin()) {
                cout << "Would you like to revoke admin status from " << user.getName() << "?";
                cout << "1. Yes" << endl;
                cout << "2. No" << endl;
                //VALIDATION HERE!
                cin >> adminChoice;
                if (adminChoice == 1) {
                    user.setAdmin(false);
                } else if (adminChoice ==2) {
                    // don't change ad status
                }
            }

        case 5:
            return;
    }

    return;
}

void Record::openAdminMenu(User user) {
    // if the user is not an admin, skip function.
    if (!user.isAdmin()) {
        return;
    }

    // otherwise, continue!
    // TO-DO: INPUT VALIDATION

    // do while choice != 4
    cout << "Welcome to the admin menu, " << user.getName() << ". Choose an option below" << endl;
    cout << "1. See all users" << endl;
    cout << "2. Delete a user" << endl;
    cout << "3. Modify a user's data" << endl;
    cout << "4. Exit admin menu" << endl;

    int choice;
    string name;
    switch (choice) {
        case 1:
            this->print();
        case 2:
            cout << "Please enter a user to delete their record: ";
            getline(std::cin, name);
            this->deleteUser(name);
        case 3:
            int position;
            cout << "Please enter a user to modify their data: ";
            getline(std::cin, name);
            position = this->searchFor(name);
            this->editUser(this->at(position));
        case 4:
            return;
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

void Record::clear(string filename) {
    ofstream outfile;
    outfile.open("test.txt", ios::out | ios::binary | ios::trunc);
    outfile.close();
}

void Record::loadFile(string filename) {
    ifstream infile( filename, ios::binary | ios::in );

    //check if file opened
    if (!infile) {
        cout << "Error: could not open user record for loading." << endl;
        //return;
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
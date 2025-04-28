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
// add a user to the userData vector
void Record::addUser(User &newUser) {
    // if there are no users in the record, the first user should be an admin
    if (userData.size() == 0) {
        newUser.setAdmin(true);
    }
    userData.push_back(newUser);
    nUsers = userData.size();
}

// display a printed record of all users
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

    cout << "Please enter a username: ";

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
        cout << "User not found. Creating a new ";

        //prompt the user that they are an admin if they are the first user in the record.
        if (userData.size() == 0) {
            cout << "admin";
        }
        cout << " user for " << name << "." << endl;
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

void Record::openAdminMenu(User user) {
    // if the user is not an admin, skip function.
    if (!user.isAdmin()) {
        return;
    }

    // otherwise, continue!
    char choice; // user choice
    cout << "Welcome to the admin menu! ";
    do {
        cout << endl;
        cout << "Choose an option below:" << endl;
        cout << "   1. See all users" << endl;
        cout << "   2. Delete a user" << endl;
        cout << "   3. Modify a user's data" << endl;
        cout << "   4. Exit admin menu and continue to Minesweeper" << endl;
        
        // prompt user for menu choice
        cin >> choice;
        cin.ignore(256, '\n');

        // execute menu choice options
        switch (choice) {
            // works
            case '1':
                this->print();
                break;

            // works
            case '2':
                this->deleteUser();
                break;

            // 
            case '3':
                this->editUser();
                break;

            case '4':
                return;
                break;
            
            default:
                cout << "Please enter a valid choice." << endl;
                break;
        }
    } while (choice != '4');

    // return if you somehow get here
    return;
}

void Record::editUser() {
    // initialize name variable
    string name;

    // user input for username
    cout << "Please enter a user to modify their data: ";
    getline(std::cin, name);

    // search for user in record
    int position = searchFor(name);

    // if user does not exist, return.
    if (position == -1) {
        cout << "User \"" << name << "\" not found." << endl;
        return;
    }

    // Console menu for an admin to edit a user's data
    char choice;
    do {
        cout << "What would you like to modify for " << userData.at(position).getName() << endl;
        cout << "   1. Change username" << endl;
        cout << "   2. Edit number of wins" << endl;
        cout << "   3. Edit number of losses" << endl;
        cout << "   4. Change admin status" << endl;
        cout << "   5. Quit" << endl;

        // prompt user for menu choice
        cin >> choice;
        cin.ignore(256, '\n');
 
        switch (choice) {
            case '1': {
                string newname;
                cout << "Enter a new username: ";
                getline(std::cin, newname);
                cin.ignore();
                userData.at(position).setName(newname);
                cout << "Username set to " << newname << "." << endl;
                break;
            }
            case '2': {
                int newWins;
                cout << "Enter the new number of wins for " << userData.at(position).getName() << ": ";
                cin >> newWins;
                userData.at(position).setWins(newWins);
                cout << userData.at(position).getName() << " now has " << newWins << " wins." << endl;
                break;
            }
            case '3': {
                int newLosses;
                cout << "Enter the new number of losses for " << userData.at(position).getName() << ": ";
                cin >> newLosses;
                userData.at(position).setLosses(newLosses);
                cout << userData.at(position).getName() << " now has " << newLosses << " losses." << endl;
                break;
            }
            case '4': {
                char adminChoice;
                if (!userData.at(position).isAdmin()) {
                    cout << "Would you like to give " << userData.at(position).getName() << " admin status?" << endl;
                    cout << "   1. Yes" << endl;
                    cout << "   2. No" << endl;
                    // VALIDATION HERE!
                    cin >> adminChoice;
                    cin.ignore(256, '\n');

                    if (adminChoice == '1') {
                        userData.at(position).setAdmin(true);
                        cout << "This user now has admin status." << endl;
                    } else if (adminChoice == '2') {
                        // don't change ad status
                    }
                    
                } if (userData.at(position).isAdmin()) {
                    cout << "Would you like to revoke admin status from " << userData.at(position).getName() << endl;
                    cout << "   1. Yes" << endl;
                    cout << "   2. No" << endl;
                    //VALIDATION HERE!
                    cin >> adminChoice;
                    if (adminChoice == 1) {
                        userData.at(position).setAdmin(false);
                        cout << "This user's admin status has been revoked." << endl;
                    } else if (adminChoice == 2) {
                        // don't change ad status 
                    }
                }
                break;
            }
            case '5':
                return;
                break;
        }
        cout << endl;
    } while (choice != '5');
    
    // something went wrong if you had to return here
    return;
}

void Record::deleteUser() {
    // initialize name variable
    string name;

    // DO NOT DELETE A USER IF...
    // they are the only one left
    if (userData.size() == 1) {
        cout << "Unable to delete users: not enough users." << endl;
        return;
    }

    // they are the only admin left
    int adCt = 0;
    // find # admins in record
    for (int i = 0; i < userData.size(); i++) {
        if (userData.at(i).isAdmin() == true) {
            adCt++;
        }
    }

    // prompt user for name to be deleted
    cout << "Please enter a user to delete their record: ";
    getline(std::cin, name);

    // search for user in record
    int position = searchFor(name);

    // if user does not exist, return.
    if (position == -1) {
        cout << "User \"" << name << "\" not found." << endl;
        return;
    }

    // if user exists, continue!

    // if the user is admin, only erase user if there is at least 2 admins.
    if (userData.at(position).isAdmin()) {
        if (adCt < 2) {
            cout << "Unable to delete users: Not enough admin users." << endl;
            return;
        }
    }
    userData.erase(userData.begin()+position);
    nUsers = userData.size();
    return;
}

// I/O functions
void Record::saveFile(string filename) {
    ofstream outfile( filename, ios::binary | ios::out );

    //if file doesn't exist, create a new binary file to save data.
    if (!outfile) {
        cout << "Error: could not open user record for saving. ";
        cout << "Creating a new binary file named \"" << filename << "\"" << endl;
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
        cout << "Notice: No file named \"" << filename << "\" exists. Creating a new record." << endl;
        // if file does not exist, return, and the record will be blank
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
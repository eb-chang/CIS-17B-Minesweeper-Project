#ifndef RECORD_H
#define RECORD_H

#include "User.hpp"
#include <vector>

using namespace std;

// The record class contains a vector of users, and utilizes user save functions
// to write out/read in user data for the minesweeper game. Save/load functions courtesy of Jesus
class Record {
    private:
        int nUsers;
        vector<User> userData;
    public:
        //constructors
        Record();
        Record(vector<User> data);

        //getters
        int getnUsers();
        vector<User> getUserData();
        
        //functions
        void addUser(User newUser); // add user to userData vector
        void print(); // print out all users, # wins, # losses, admin status
        int searchFor(string name); // return index of User position; if not found, return -1
        User at(int n); // return the User at index n
        User login();
        void openAdminMenu(User user);
        void editUser();
        void deleteUser(); // delete a user from record
        void clear(string filename); // CLEARS WHOLE RECORD. 

        //I/O functions
        void saveFile(string filename);
        void loadFile(string filename);
};

#endif //RECORD_H
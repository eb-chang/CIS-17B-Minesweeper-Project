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
        Record();
        Record(vector<User> data);

        int getnUsers();
        void saveFile(string filename);
        void loadFile(string filename);
        void addUser(User newUser);
        void print();
};

#endif //RECORD_H
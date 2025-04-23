#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>

using namespace std;

class User {
    private:
        string username; // 4-char long
        int wins;
        int losses;
        bool admin;
    public:
        //constructors
        User();
        User(string name);
        User(string name, int nWins, int nLosses, bool adminStatus);

        //setters
        void setName(string name); //must validate a 4-letter name
        void setWins(int nWins);
        void setLosses(int nLosses);
        void setAdmin(bool adminStatus);

        //getters
        string getName();
        int getWins();
        int getLosses();
        bool isAdmin();

        //member functions
        void saveUser(string filename);
        void loadUser(string filename);
};

#endif //USER_H
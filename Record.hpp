#ifndef RECORD_H
#define RECORD_H

#include "User.hpp"

using namespace std;

class Record {
    private:
        int nUsers;
        User *users;
        
    public:
        Record();
        Record(int n);
        void saveFile(string filename);
        void loadFile(string filename);
        void addUser(string name);
        void print();
        virtual ~Record();
};

#endif //RECORD_H
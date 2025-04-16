#ifndef USER_H
#define USER_H

#include <string>



class User{
    private:
        std::string name;
    public:
        //constructors
        User(); //default constructor
        //User(param); TODO: params for copy constructor

        //getters
        std::string getName();

        //setters
        void setName(std::string);

        //other class methods
};

#endif
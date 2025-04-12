#ifndef ADMIN_HPP
#define ADMIN_HPP

#include "user.hpp"

class Admin :public User {


private:
	string adminID; //unique id 

public:
	Admin(string, string, string);

	void displayInfo()const override; //polymorphism ???
	
	void viewScoreBoard() const;
	void resetScoreBoard() const;

};




#endif
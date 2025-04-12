#include "user.hpp"
#include <iostream>


using namespace std;


User::User() {
	username = "username";
	email = "guest@example.com";


}

User::User(string x, string y) {
	username = x;
	email = y;

}


void User::displayInfo()const {
	cout << "User Name: " << username << "\nEmail: " << email << endl;

}

string User::getUserName() const {
	return username;
}

string User::getEmail()const {

	return email;
}

User::~User() {

}

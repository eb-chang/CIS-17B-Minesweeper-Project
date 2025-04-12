#ifndef USER_HPP
#define USER_HPP

#include <string>


using namespace std;

class User {
private:
/// <summary>
/// some other private code 
/// </summary>
protected:

	string username; 
	string email;

public:
	User();
	User(string, string);
	virtual void displayInfo()const;
	string getUserName() const;
	string getEmail()const;

	virtual ~User();



};


#endif
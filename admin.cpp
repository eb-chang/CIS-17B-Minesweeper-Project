#include "admin.hpp"

#include <iostream>
#include <fstream>

using namespace std;

Admin::Admin(string uName, string uEmail, string adID) :User(uName, uEmail), adminID(adID) {}

void Admin::displayInfo()const { //polymorphism
	
	User::displayInfo();
	cout << "\n\n\nAdmin Identification: " << adminID << endl;

}



void Admin::viewScoreBoard()const {
	cout << "\n--- Scoreboard ---\n";
	ifstream in("scoreboard.txt");
	string line;
	while (getline(in, line)) {
		cout << line << endl;
	}

	cout << "-----------------------\n";
}

void Admin::resetScoreBoard()const {
	ofstream out("scoreboard.txt", ios::trunc); //truncate
	cout << "Scoreboard reset by " << username << ".\n";

}
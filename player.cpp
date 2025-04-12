#include "player.hpp"
#include <iostream>
#include <fstream>

using namespace std;

Player::Player(string uName, string uEmail) :User(uName, uEmail), gamesPlayed(0), highScore(0) {}


void Player::displayInfo()const {
	User::displayInfo();
	cout << "Games Played " << gamesPlayed << "\nHigh Score: " << highScore << endl;

}

void Player::numGamePlay() {
	gamesPlayed++;
	cout << username << " is playing a game...\n";
}

void Player::recordWin() {
	
	highScore++;
	
}

void Player::saveStats()const{
	ofstream out("scoreboard.txt", ios::app);
	if (out.is_open()) {
		out << username << "," << email << "," << highScore << "\n";
		out.close();
	}
}

void Player::loadStats() {
	cout << "Loading previous scores for " << username << "...\n";
	ifstream in("scoreboard.txt");
	string line;
	while (getline(in, line)) {
		if (line.find(username) != string::npos) {
			cout << line << endl;
		}
	
	}
}
#ifndef PLAYER_HPP
#define PLAYER_HPP


#include "user.hpp"

class Player :public User {
private:
	int gamesPlayed;
	int highScore;
public:
	Player(string, string);

	void displayInfo()const override; //poly
	void numGamePlay();//counting num of game plays 
	void recordWin();
	void saveStats()const;
	void loadStats();


};

#endif
#ifndef BIN_H
#define	BIN_H

struct Score {
	int win;
	int loss;

};




class Binary {

private:
	Score score;
	char name[20];
	//type user class ???
public:
	Binary();
	Binary(int, int, const char*);//passing in wins/loss/name
	
	void iLoss();
	void iWin();
	void fileOutWin();
	void fileInWin();
	void fileOutLoss();
	void fileInLoss();
	char* getName();

};


#endif
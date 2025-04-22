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
public:
	Binary();
	
	void iLoss();
	void iWin();
	void fileOutWin();
	void fileInWin();
	void fileOutLoss();
	void fileInLoss();


};


#endif
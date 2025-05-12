#include "binary.hpp"
#include <iostream>
#include <fstream>
#include <cstring>


using namespace std;

Binary::Binary() {
	strcpy(name, "");
	score.win = 0;
	score.loss = 0;
	
}
Binary::Binary(int w, int l, const char*n) {
	strcpy(name,n);
	score.win = w;
	score.loss = l;


}

void Binary::iLoss() {
	
	score.loss = score.loss + 1;

}

void Binary::iWin() {
	score.win = score.win + 1;
}



void Binary::fileOutWin() {
	ofstream outW("WinScore.bin", ios::binary);
	if (outW.is_open()) {
		
		outW.write(reinterpret_cast<const char*>(&score.win), sizeof(score.win));
		outW.write(reinterpret_cast<const char*>(name), sizeof(name));
		cout << "write winners" << endl;
		outW.close();
	}
}
void Binary::fileInWin(){
	ifstream inW("WinScore.bin", ios::binary);
	if (inW.is_open()){
		int read_win;
		char read_name[4];
		inW.read(reinterpret_cast<char*>(&read_win), sizeof(read_win));
		cout << "read winners " << endl;
		cout << "name: " << read_name << endl;
		cout<<"number of Wins:"<<read_win << endl;
		inW.close();
	}
	
	}
void Binary::fileOutLoss() {
	ofstream outL("LossScore.bin", ios::binary);
	if (outL.is_open()) {
		outL.write(reinterpret_cast<const char*>(&score.loss), sizeof(score.loss));
		outL.write(reinterpret_cast<const char*>(&name), sizeof(name));
		cout << "write Loss" << endl;
		outL.close();
	
	
	}



}
	void fileInLoss(){
		ofstream outL("LossScore.bin", ios::binary);

		if (outL.is_open()) {
			int read_loss;
			char read_name[4];
			outL.write(reinterpret_cast<const char*>(&read_loss), sizeof(read_loss));
			outL.write(reinterpret_cast<const char*>(read_name), sizeof(read_name));
			cout << "read losers " << endl;
			cout << "name: " << read_name << endl;
			cout << "number of loss" << read_loss<<endl;
			outL.close();
		
		}

}

	char* Binary::getName() {
	
	
		return name;
	}
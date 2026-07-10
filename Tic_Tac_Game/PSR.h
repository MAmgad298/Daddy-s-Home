#include<iostream>
#include <random>
using namespace std;

#ifndef PSR_H
#define PSR_H

class PSR {

public:
	//Constructor
	PSR();

	//Check the Game
	bool gameOver(int, int);
	//setters
	void setPlayer(int);
	void setComp(int);

	//getters
	int returnPlayer();
	int returnComp();

	//get Random value
	int getRandomValue();

	//return turn
	string turn(int);

	//print list
	void printList();
private:
	string list[3] = { "Paper","Scissors", "Rock" };
	int player_turn;
	int comp_turn;
};
#endif // !PSR_H

#include<iostream>
#include<random>
using namespace std;

#ifndef DART_H

class Dart {
public:
	//contructor
	Dart();

	//setters
	void setPlayerTurn(char[3]);
	void setComputerTurn(char[3]);

	//getters
	int getPlayerTurn();
	int getComputerTurn();

	//place move
	void placeMove(char[3],int,char);

	//target strike
	bool isTheTargetStruck(char[3]);

	//reempty board
	void emptyBrd(char[3]);

	//print board
	void printBoard(char[3]);

private:
	char board[3]= { ' ',' ',' ' };
	int player_turn;
	int computer_turn;
};

#endif // !DART_H

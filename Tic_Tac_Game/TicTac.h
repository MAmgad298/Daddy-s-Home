#include<iostream>
#include<random>
using namespace std;

#ifndef TICTAC_H
class TicTac {
public:
	//Constructor
	TicTac();
	//setters
	void setPlayerTurn(char[3][3]);
	void setComputerTurn(char[3][3]);
	
	// getters
	int getPlayerTurn();
	int getComputerTurn();

	//Validations
	bool isValidMove(char[3][3],int);
	bool isGameFinished(char[3][3]);
	bool isGameWon(char[3][3], char);

	//place move
	void placeMove(char[3][3],int, char);

	//Print board
	void printBoard(char[3][3]);
private:
	//const int BRD_DIMS;
	char board[3][3] = {
		{' ',' ',' '},
		{' ',' ',' '},
		{' ',' ',' '} };

	int player_turn;
	int computer_turn;
};
#endif TICTAC_H

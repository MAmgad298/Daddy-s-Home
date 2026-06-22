#include<iostream>
#include<random>
using namespace std;

#ifndef ROL_NUMS

class RouletteNumbers {
public:
	
	//Constructors
	RouletteNumbers();


	//setters
	void setCompGuess(char[]);
	void setPlayerGuess(char[]);

	//Getters
	int getCompGuess(); //1-999
	int getPlayerGuess(); //1-999
	char getMove(char[]);	

	//Functions
	void placeMove(char[], int,int);
	void emptyArr(char[]);
	bool isGameFinished(char[],string,string);

	//printers
	void printBoard(char[]);

private:

	char board[3] = {' ',' ',' '};

	char charsArr[10] = {
		'@','#','$',
		'%','&','*',
		'-','/','+',
		'X'};

	int compGuess, playerGuess=0;
	string compMove,playerMove;


};


#endif // !ROL_NUMS


#include "RouletteNumbers.h";

RouletteNumbers::RouletteNumbers() {

	int noOfTrials = 0;
	
	playerGuess = 0;
	setCompGuess(board);
	compMove = getMove(board);
	emptyArr(board);

	do {
		setPlayerGuess(board);
		playerMove = getMove(board);
		noOfTrials+=1;
		if (isGameFinished(board, compMove, playerMove))
			cout << "\n!!!! CONGRAAAAATULAAATIONSSS ! you've got the right symbol :D\n";
		else
			cout << "\ntry again!";

		if(noOfTrials==5 && !isGameFinished(board, compMove, playerMove))
			cout << "\ntry again next run :(\n";

	} while (!isGameFinished(board, compMove, playerMove) && noOfTrials < 5);

	
}

//setters
void RouletteNumbers::setPlayerGuess(char board[]) {

	cout << endl;

	/*for (int i = 0; i < 1; ++i) {
		cout << "from 1-10 guess number: ";
		cin >> playerGuess;
		placeMove(board, playerGuess, i);
	}*/

	cout << "from 1-10 guess number: ";
	cin >> playerGuess;
	placeMove(board, playerGuess, 1);

	//printBoard(board);
}

void RouletteNumbers::setCompGuess(char board[]) {


	/*for (int i = 0; i < 3; ) {
		placeMove(board, getCompGuess(), ++i);
	}*/

	placeMove(board, getCompGuess(), 1);
	printBoard(board);
}

//Getters
int RouletteNumbers::getPlayerGuess() {
	return playerGuess;
}

int RouletteNumbers::getCompGuess() {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dist(1, 10);

	return dist(gen);
}

char RouletteNumbers::getMove(char board[]) {
	
	/*for (int i = 0; i < 3; ++i)
		returnMv += board[i];*/
	
	return board[0];
}

//Functions
void RouletteNumbers::placeMove(char board[], int compPlayerGuess,int digit) {

		board[0] = charsArr[compPlayerGuess - 1];
}

void RouletteNumbers::emptyArr(char board[]) {
	for (int i = 0; i < 3; ++i)
		board[i] = ' ';
}

bool RouletteNumbers::isGameFinished(char board[], string mv1, string mv2) {
	return (mv1 == mv2);
}

//Print Board
void RouletteNumbers::printBoard(char board[]) {
	for (int i = 0; i < 3; ++i)
		cout << board[i];
}
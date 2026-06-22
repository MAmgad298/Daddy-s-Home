#include "TicTac.h"

TicTac::TicTac() {

	printBoard(board);

	while (true) {
		
		setPlayerTurn(board);

		if (isGameFinished(board))
			break;

		printBoard(board);

		cout << endl;

		setComputerTurn(board);

		cout << endl;

		if (isGameFinished(board))
			break;

		printBoard(board);
	}
}

//setters
void TicTac::setPlayerTurn(char board[3][3]) {

	while (true) {

		cout << "from (1-9) where are you gonna play? ";
		cin >> player_turn;

		if (isValidMove(board, player_turn))
			break;
		else
			cout << "not valid\n";
	}

	placeMove(board, getPlayerTurn(), 'X');

}

void TicTac::setComputerTurn(char board[3][3]) {
	int validCompMv;
	while (true) {
		validCompMv = getComputerTurn();
		if (isValidMove(board, validCompMv)) 
			break;
	}
	placeMove(board, validCompMv, 'O');
}

//getters
int TicTac::getPlayerTurn(){
	return player_turn;
}

int TicTac::getComputerTurn() {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> distirb(1, 9);

	return distirb(gen);
}

//Place Moves
void TicTac::placeMove(char board[3][3], int pos, char x) {
	switch (pos) {
	case 1:board[0][0] = x; break;
	case 2:board[0][1] = x; break;
	case 3:board[0][2] = x; break;
	case 4:board[1][0] = x; break;
	case 5:board[1][1] = x; break;
	case 6:board[1][2] = x; break;
	case 7:board[2][0] = x; break;
	case 8:board[2][1] = x; break;
	case 9:board[2][2] = x; break;
	default:cout << ":(";
	}
}

//validations
bool TicTac::isValidMove(char board[3][3], int move) {

	//from 1 to 3 & 4 to 6 & 7 to 9
	switch (move) {
	case 1: return (board[0][0] == ' '); break;
	case 2: return (board[0][1] == ' '); break;
	case 3: return (board[0][2] == ' '); break;
	case 4: return (board[1][0] == ' '); break;
	case 5: return (board[1][1] == ' '); break;
	case 6: return (board[1][2] == ' '); break;
	case 7: return (board[2][0] == ' '); break;
	case 8: return (board[2][1] == ' '); break;
	case 9: return (board[2][2] == ' '); break;
	default:return false;
	}

}

bool TicTac::isGameFinished(char board[3][3]) {

	if (isGameWon(board, 'X')) {
		printBoard(board);
		cout << "player wins!\n";
		return true;
	}

	if (isGameWon(board, 'O')) {
		printBoard(board);
		cout << "Computer wins!\n";
		return true;
	}

	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			if (board[i][j] == ' ')
				return false;
	cout << "Tie";
	return true;
}

bool TicTac::isGameWon(char board[3][3], char player) {

	if (board[0][0] == player && board[0][1] == player && board[0][2] == player ||
		board[1][0] == player && board[1][1] == player && board[1][2] == player ||
		board[2][0] == player && board[2][1] == player && board[2][2] == player ||

		board[0][0] == player && board[1][0] == player && board[2][0] == player ||
		board[0][1] == player && board[1][1] == player && board[2][1] == player ||
		board[0][2] == player && board[1][2] == player && board[2][2] == player ||

		board[0][0] == player && board[1][1] == player && board[2][2] == player ||
		board[0][2] == player && board[1][1] == player && board[2][0] == player)
		return true;

	return false;
}

//print board
void TicTac::printBoard(char board[3][3]) {
	for (int i = 0; i < 3; ++i) {
		
		for (int j = 0; j < 3; ++j) {
			cout << board[i][j]<<'|';
		}
		cout << "\n-+-+-\n";
	}
}
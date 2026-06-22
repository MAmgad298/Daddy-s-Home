#include"Dart.h"

Dart::Dart(){
	while(true)
	{
		cout << endl;
		printBoard(board);
		cout << endl;
		setPlayerTurn(board);
		setComputerTurn(board);
		printBoard(board);

		if (isTheTargetStruck(board))
		{
			cout << "\nOuch ! u've got me X_X";
			break;
		}
		else
		{
			cout << "\nLOL! u've missed me ! try again haha XD XD XD\n";
			emptyBrd(board);
		}
	}
	
	
}

//setters
void Dart::setPlayerTurn(char board[3]) {

	cout << "from (1-3) where are u gonna hit? (+)\n";
	cin >> player_turn;

	placeMove(board,player_turn, '+');
}

void Dart::setComputerTurn(char board[3]) {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dist(1,3);
	computer_turn = dist(gen);

	placeMove(board, computer_turn, '*');
}

//getters
int Dart::getPlayerTurn() {
	return player_turn;
}

int Dart::getComputerTurn() {
	return computer_turn;
}


//place move
void Dart::placeMove(char board[3], int pos, char fireZn) {
	
	switch (pos) {
	case 1:board[0] = fireZn; break;
	case 2:board[1] = fireZn; break;
	case 3:board[2] = fireZn; break;
	default:cout << ":(";
	}

}

//target strike
bool Dart::isTheTargetStruck(char board[3]) {
	return (getPlayerTurn() == getComputerTurn());
}

//Empty board
void Dart::emptyBrd(char brd[3]) {
	for (int i = 0; i < 3; ++i)
		brd[i] = ' ';
}

//print board
void Dart::printBoard(char board[3]) {
	for (int i = 0; i < 3; ++i)
		cout << board[i] <<'|';
}


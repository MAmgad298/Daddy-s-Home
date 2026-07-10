#include "PSR.h"

PSR::PSR() {
	bool play=false;
	int usrIn;
	
	do {

		printList();
		cin >> usrIn;

		cout << endl;
		setPlayer(usrIn);
		setComp(getRandomValue());
		
		cout << endl;
		cout << turn(returnPlayer()) << endl;
		cout << turn(returnComp()) << endl;;
		cout << endl;

		gameOver(returnComp(), returnPlayer());

		cout << "\nPlay?\n1.yes\n2.No\n";
		cin >> usrIn;
		play = usrIn == 1 ? true : false;

	} while (play);
	


}


//Gameover
bool PSR::gameOver(int computer_turn, int player_turn) {
	string youWinMsg;
	if (computer_turn == player_turn)
		youWinMsg = "Ends w/ a tie\n";
	else {
		switch (computer_turn) {
		case 1:
			youWinMsg = player_turn == 2 ? "you win\n" : "you lose\n";
			break;
		case 2:
			youWinMsg = player_turn == 3 ? "you win\n" : "you lose\n";
			break;
		case 3:
			youWinMsg = player_turn == 1 ? "you win\n" : "you lose\n";
			break;
		}
	}
	cout << youWinMsg;
	return false;
}

void PSR::setPlayer(int newTurn) {
	player_turn = newTurn;
}
void PSR::setComp(int newTurn) {
	comp_turn = newTurn;
}

int PSR::returnPlayer() {
	return player_turn;
}

int PSR::returnComp() {
	return comp_turn;
}

//turn converter
string PSR::turn(int newTurn) {
	switch (newTurn) {
	case 1: return list[0]; break;
	case 2: return list[1]; break;
	case 3: return list[2]; break;
	}

	return "Not valid\n";
}

//Get Random value
int PSR::getRandomValue() {
	random_device rd;
	mt19937 gen(rd());

	uniform_int_distribution<int> dist(1,3);

	return dist(gen);
}

//print list
void PSR::printList() {
	cout << "Choose your player:\n";
	for (int i = 0; i < 3; ++i)
		cout << i+1 << "." << list[i] << "\n";
}
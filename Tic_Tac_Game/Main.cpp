#include<iostream>
#include "TicTac.h"
#include "Dart.h"
#include "RouletteNumbers.h";

using namespace std;
int main() {
	int userIn;

	cout << "Switch a game:\n1.Dart\t2.TicTac\t3.Dice\n";
	cin >> userIn;

	switch (userIn) {
	case 1: 
		if(userIn ==1)
			Dart d;
		break;
	case 2: 
		if (userIn == 2)
			TicTac t;
		; break;

	case 3:
		if (userIn == 3)
			RouletteNumbers r;
		break;
	default:cout << "Dw, soon will add more games :)\n";
	}

	//cout << 123 % 100;

	/*RouletteNumbers R;*/
	/*R.setPlayerGuess()*/

	return 0;
}
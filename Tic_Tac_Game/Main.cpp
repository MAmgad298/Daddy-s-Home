#include<iostream>
#include "TicTac.h"
#include "Dart.h"

using namespace std;
int main() {
	int userIn;

	cout << "Switch a game:\n1.Dart\t2.TicTac\n";
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
	default:cout << "n't'inquiète pas, soon will add more games :)\n";
	}

	return 0;
}

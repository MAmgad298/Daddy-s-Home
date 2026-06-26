#include "Hangman.h"

Hangman::Hangman() {
	
	char usrIn;

	fillMoviesList(moviesList);
	string compGuess = getPickedMovie(moviesList);
	cout << "\nHint, show name consists of "<<compGuess.size()<<" letters.\n Spaces are NOT counted\n";
	//cout << getMoviesCount();

	for (int i = 0; i < compGuess.size(); ++i)
		result += '-';

	//cout << result;

	while (true) {
		
		drawHangMan(getWrongCnt());

		cout << "\nGuess a Letter:\n";
		cin >> usrIn;

		setPlayerGuess(usrIn);

		if(isMatchedLetter(compGuess))
		{
			
			cout<< "\nWinner Winner chicken dinner !!!";
			break;
		}

		if (isNotMatchedLetter(compGuess))
			wrongCnt++;
		

		if (wrongCnt == 7)
		{
			cout << "\nMan is hanged x_x, you lose\n";
			break;
		}
		
	};
		
}
//Setters
void Hangman::setPlayerGuess(char newUserIn) {
	userIn = newUserIn;
}

void Hangman::setPickedMovie(string newPckMv) {
	pickedMovie = newPckMv;
}

//Getters
//get player guess
char Hangman::getPlayerGuess() {
	return userIn;
}

//get Wrong Counter
int Hangman::getWrongCnt() {
	return wrongCnt;
}

//generate random value
int Hangman::getRandomNo() {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> range(1, getMoviesCount());

	return range(gen);
}

//generate random movie
string Hangman::getPickedMovie(vector<string> mvList) {
	return mvList[getRandomNo()];
}

int Hangman::getMoviesCount() {
	return mvCnt;
}

//fill movies list
void Hangman::fillMoviesList(vector<string>& newMvList) {

	int c = 0;
	string mv;
	ifstream movies;

	movies.open("movies.txt");

	while (!movies.eof()) {
		movies >> mv;
		newMvList.push_back(mv);
		c++;
	}

	//cout << endl << c << " movies";
	mvCnt = c;

	movies.close();

}

//Check if Matched
bool Hangman::isMatchedLetter(string mvName) {

	for (int i = 0; i < mvName.size(); ++i) {
		if (getPlayerGuess() == mvName[i]) {
			result[i] = getPlayerGuess();
			correctCnt++;
		}
	}

	cout << result;

	return (correctCnt == mvName.size());
}

//Check if not Matched
bool Hangman::isNotMatchedLetter(string mvName) {
	bool retResult;
	string notFound="";

	for (int i = 0; i < mvName.size(); ++i)
		if (getPlayerGuess() != mvName[i])
			notFound+='-';

	
	return (notFound.size() == mvName.size());
}

//increase wrong count
//void Hangman::increaseWrongCnt(int newWrongCnt) {
//	newWrongCnt++;
//}
//printer
void Hangman::drawHangMan(int newWrongCnt) {

	cout << "\n";
	if (newWrongCnt >= 1)
		cout << "\n |\n";

	if (newWrongCnt >= 2)
		cout << " O\n";

	if (newWrongCnt >= 3)
		cout << "/";

	if (newWrongCnt >= 4)
		cout << "|";

	if (newWrongCnt >= 5)
		cout << "\\";

	if (newWrongCnt >= 6)
		cout << "\n/";

	if (newWrongCnt >= 7)
		cout << " \\";
		
}


//print movies
void Hangman::printMovies(vector<string> mvs) {
	cout << "\n";
	for (int i = 0; i < mvs.size(); ++i)
		cout << mvs[i]<<"\n";
}
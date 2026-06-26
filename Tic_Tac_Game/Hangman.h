#include<iostream>
#include<random>
#include<vector>
#include<fstream>
using namespace std;

#ifndef HMAN_H
#define HMAN_H

class Hangman {
public:
	//Constructor
	Hangman();

	//setters
	void setPlayerGuess(char);
	void setPickedMovie(string);

	//getters
	char getPlayerGuess();	
	int getRandomNo();
	string getPickedMovie(vector<string>);
	int getWrongCnt();
	int getMoviesCount();

	//fill movies list
	void fillMoviesList(vector<string>&);

	//check the input if equal to the generated movie
	bool isMatchedLetter(string);
	bool isNotMatchedLetter( string);

	//increase wrong count
	//void increaseWrongCnt(int);

	//printers
	void drawHangMan(int);
	void printMovies(vector<string>);
private:

	string result = "";
	int correctCnt = 0;

	int wrongCnt = 0;
	char userIn;

	vector<string> moviesList;

	//char player_guess;
	string pickedMovie;

	int mvCnt;
};

#endif // !

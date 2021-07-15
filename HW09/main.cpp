/***********************************************
Author: Micah Perkins
Date: 11/17/2019
Purpose: to make a guessing game
Sources of Help: internet, classmates, Sirong Lin
Time Spent: Like 4ish hours
***********************************************/
/*
Computing III -- COMP.2010 Honor Statement
The practice of good ethical behavior is essential for maintaining
good order in the classroom, providing an enriching learning
experience for students, and as training as a practicing computing
professional upon graduation. This practice is manifested in the
University’s Academic Integrity policy. Students are expected to
strictly avoid academic dishonesty and adhere to the Academic
Integrity policy as outlined in the course catalog. Violations will
be dealt with as outlined therein.
All programming assignments in this class are to be done by the
student alone. No outside help is permitted except the instructor and
approved tutors.
I certify that the work submitted with this assignment is mine and was
generated in a manner consistent with this document, the course
academic policy on the course website on Blackboard, and the UMass
Lowell academic code.
Date: 11/17/2019
Name:Micah Perkins
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Player {
public:
	virtual int getGuess() {
		return 0;
	}
private:

};

class HumanPlayer :public Player {
public:
	HumanPlayer() { guess = 0; }
	~HumanPlayer() {}

	int getGuess() override {
		cout << "Please enter a guess(Must be a valid integer): ";
		cin >> guess;
		return guess;
	}

private:
	int guess;
};

class ComputerPlayer :public Player {
public:
	ComputerPlayer() { guess = 0; }
	~ComputerPlayer() {}

	int getGuess() override {
		srand(time(NULL));
		guess = rand() % 100;
		return guess;
	}
private:
	int guess;
};
//////////////////////////////////////
// Global functions given in project
//////////////////////////////////////
bool checkForWin(int guess, int answer)
{
	if (answer == guess)
	{
		cout << "You're right! You win!" << endl;
		return true;
	}
	else if (answer < guess)
		cout << "Your guess is too high." << endl;
	else
		cout << "Your guess is too low." << endl;
	return false;
}
// The play function takes as input two Player objects.
void play(Player& player1, Player& player2) {
	int answer = 0, guess = 0;
	srand(time(NULL));
	answer = rand() % 100;
	bool win = false;

	while (!win)
	{
		cout << "Player 1's turn to guess." << endl;
		guess = player1.getGuess();
		win = checkForWin(guess, answer);
		if (win) return;

		cout << "Player 2's turn to guess." << endl;
		guess = player2.getGuess();
		win = checkForWin(guess, answer);
	}
}

int main() {
	HumanPlayer p1;
	HumanPlayer p2;
	ComputerPlayer c1;
	ComputerPlayer c2;

	play(p1, p2);
	play(p1, c1);
	play(c1, c2);

	return 0;
}
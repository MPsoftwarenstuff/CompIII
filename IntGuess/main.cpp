#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//function to control the guessing
void runGame(int min, int max);

int getMin(void);

int getMax(void);

int main(int argc, char* argv[])
{
	//begin game if user presses Y, stop if N
	int min;
	int max;
	char YN;
	
	cout << "Are you ready to play? Choose y or n: ";
	cin >> YN;
	while (YN == 'y' || YN == 'Y')
	{
		//get min and max
		min = getMin();
		max = getMax();
		//run game
		runGame(min, max);
		//prompt user for next game
		cout << "Are you ready to play? Choose y or n: ";
		cin >> YN;
	}

	if (YN == 'N' || YN == 'n')
	{
		exit(1);
	}

	return 0;
}

int getMin(void)
{
	int min;
	//collect min
	cout << "Enter a minimum number larger than 0: ";
	cin >> min;
	//error check
	while (min <= 0)
	{
		cin.clear();
		cout << "Enter a minimum number larger than the minimum: ";
		cin >> min;
	}
	return min;
}

int getMax(void)
{
	int max;
	//collect min
	cout << "Enter a maximum number larger than 0: ";
	cin >> max;
	//error check
	while (max <= 0)
	{
		cin.clear();
		cout << "Enter a maximum number larger than the minimum: ";
		cin >> max;
	}
	return max;
}

void runGame(int min, int max)
{
	//vars for input and calculation
	int num;
	int guess;
	int tries = 0;

	srand(time(0)); //Give random num gen a seed
	num = rand() % (max-min + 1) + min; // Generates a random number from 0 to the maximum number

	//continue playing until guesses run out

	do
	{
		//collect the user's guess
		cout << "Enter a guess between " << min << " and "<< max << " : ";
		cin >> guess;
		if (!guess)
		{
			cout << "Incorrect input type";
			return;
		}
		tries++;

		//evaluate guess
		if (guess > num)
			cout << "Too high!\n\n";
		else if (guess < num)
			cout << "Too low!\n\n";
		else
		{
			cout << "\nCorrect! You got it in " << tries << " guesses!\n";
			return;
		}
	} while (tries < 10);

	return;

}

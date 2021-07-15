#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void clear_keyboard_buffer();

int main(int argc, char* argv[])
{
	int diecnt;

	//get number of dice
	printf("Hello! Enter the number of dice [2-5]: ");
	scanf("%d", &diecnt);

	while (diecnt < 2 || diecnt > 5)
	{
		clear_keyboard_buffer();
		printf("Please enter a valid number between 2 and 5: ");
		scanf("%d", &diecnt);
	}

	//declare vars
	int i;
	int rollarr[5] = { 0 };
	int total = 0;

	//seed random num gen & "roll" die
	srand(time(0));
	for (i = 0; i < diecnt; i++)
	{
		rollarr[i] = rand() % 6 + 1;
		printf("%d\n", rollarr[i]);
		total = total + rollarr[i];
	}
	int average = total / diecnt;
	printf("The sum of all rolls is: %d\n", total);
	printf("The average of the rolls is: %d\n", average);
	return 0;
}

void clear_keyboard_buffer()
{
	char c;
	scanf("%c", &c);
	while (c != '\n')
	{
		scanf("%c", &c);
	}
}
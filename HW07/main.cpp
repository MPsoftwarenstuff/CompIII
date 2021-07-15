/***********************************************
Author: Micah Perkins
Date: 10/17/2019
Purpose: to store and average out movie reviews
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
Date: 10/17/2019
Name:Micah Perkins
*/
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <map>

using namespace std;

ifstream OpenF();
void mapping(ifstream inFile);
int average(int, int);

int main() {
	mapping(OpenF());

	return 0;
}

ifstream OpenF() {
	//file input 
	ifstream inFile;

	//Open file
	inFile.open("HW07.txt", ios::in);

	//Error check
	if (inFile.fail())
	{
		cout << "The file did not open" << endl;
		exit(1); //Exit if file fails to open
	}
	cout << "file opened" << endl << endl;

	return inFile;
}

void mapping(ifstream inFile) {
	string input;
	string strintput;
	string strsize;
	int intput;
	int size;
	map<string, int> review;
	map<string, int> trackavg;

	//pull number of reviews
	getline(inFile, strintput);
	size = stoi(strintput);

	cout << "Testing that file reads correctly:" << endl << endl;
	//store the data 
	for (int i = 0; i < size; i++) {
		getline(inFile, input);
		getline(inFile, strintput);

		intput = stoi(strintput);
		review[input] += intput;
		trackavg[input] += 1;
	}

	//print the entire file for error checking purposes
	typename map<string, int>::iterator ireview;

	for (ireview = review.begin(); ireview != review.end(); ireview++) {
		cout << "\"" << ireview->first << "\"" << " == " << ireview->second << endl;
	}

	cout << endl << "Testing that trackavg map is functioning: " << endl << endl;

	for (ireview = trackavg.begin(); ireview != trackavg.end(); ireview++) {
		cout << "\"" << ireview->first << "\"" << " == " << ireview->second << endl;
	}

	//Print movie names and corresponding averages of reviews
	map<string, int>::iterator iR;
	map<string, int>::iterator iT = trackavg.begin();

	cout << endl << "Average review for each movie: " << endl << endl;
	for (iR = review.begin(); iR != review.end(); iR++) {
		int avg = average(iR->second, iT->second);

		cout << iR->first << " == " << avg << endl;
		iT++;
	}
}

int average(int a, int b) {
	//averages two numbers
	int avg = a / b;
	return avg;
}
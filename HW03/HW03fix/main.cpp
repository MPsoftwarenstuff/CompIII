/***********************************************
Author:	Micah Perkins
Date:	9/14/2019
Purpose:	To read from a file and change certain words to "love"
Sources	of	Help:	internet, my own notes
Time	Spent:	3 hours
***********************************************/
/*
Computing	III	-- COMP.2010	Honor	Statement
The	 practice	 of	 good	 ethical	 behavior	 is	 essential	 for	 maintaining
good	 order	 in	 the	 classroom,	 providing	 an	 enriching	 learning
experience	 for	 students,	 and	 as	 training	 as	 a	 practicing	 computing
professional	 upon	 graduation.	 	 This	 practice	 is	 manifested	 in	 the
University’s	 Academic	 Integrity	 policy.	 Students	 are	 expected	 to
strictly	 avoid	 academic	 dishonesty	 and	 adhere	 to	 the	 Academic
Integrity	 policy	 as	 outlined	 in	 the	 course	 catalog.	 	 Violations	 will
be	dealt	with	as	outlined	therein.
All	 programming	 assignments	 in	 this	 class	 are	 to	 be	 done	 by	 the
student	alone.		No	outside	help	is	permitted	except	the	instructor	and
approved	tutors.
I	certify	that	the	work	submitted	with	this	assignment	is	mine	and	was
generated	 in	 a	 manner	 consistent	 with	 this	 document,	 the	 course
academic	 policy	 on	 the	 course	 website	 on	 Blackboard,	 and	 the	 UMass
Lowell	academic	code.
Date: 9/20/21
Name: Micah Perkins
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

//make things easier
using namespace std;

int main(int argc, char* argv[])
{
	//string storage
	string str;
	const string dislike = "dislike";
	char x;
	//file input 
	ifstream inFile;

	//Open file
	inFile.open("input.txt", ios::in);

	//Error check
	if (inFile.fail())
	{
		cout << "The file did not open" << endl;
		exit(1); //Exit if file fails to open
	}
	cout << "file opened" << endl;

	

	while (inFile >> x)
	{

		for(int i = 0; x == dislike[i]; ++i)
		{
			str.push_back(x);
			inFile >> x;

			if (str == dislike)
			{
				cout << "love";
				str.clear();
			}
		}
		
		cout << str;
		cout << x;
		str.clear();
		/*while (x != ' ')
		{
			cout << "str.pushback" << endl;

			str.push_back(x);
			inFile >> x;

			if (str == dislike)
			{
				str == "love";
				cout << str;
			}
		} */
	}

	inFile.close();

	return 0;
}


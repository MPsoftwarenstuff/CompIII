/***********************************************
Author: Micah Perkins
Date: 9/23/2019
Purpose: manipulate Point data type using classes
Sources of Help: internet, group study sessions
Time Spent:
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
Date: 9/23/2019
Name: Micah Perkins
*/
#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;

//create my Point class
class Point
{
public:
	//constructors
	Point()
	{
		x = 0;
		y = 0;
	}

	Point(int newx, int newy)
	{
		x = newx;
		y = newy;
	}
	//Functions for manipulating & setting the Points
	void setX()
	{
		cout << "Please enter a point on the x-axis: ";
		cin >> x;
		while (!x)
		{
			cin.clear();
			cout << "Please enter a point on the x-axis: ";
			cin >> x;
		}
	}
	void setY()
	{
		cout << "Please enter a point on the y-axis: ";
		cin >> y;
		while (!y)
		{
			cin.clear();
			cout << "Please enter a point on the y-axis: ";
			cin >> y;
		}
	}

	int getX()
	{
		return x;
	}
	int getY()
	{
		return y;
	}

	//moves points based on user input
	void movePoint()
	{
		int newx;
		int newy;

		cout << "please enter the desired shift in the x-coordinate: ";
		cin >> newx;
		while (!newx)
		{
			cin.clear();
			cout << "please enter the desired shift in the x-coordinate (integers only): ";
			cin >> newx;
		}

		cout << "please enter the desired shift in the y-coordinate: ";
		cin >> newy;
		while (!newy)
		{
			cin.clear();
			cout << "please enter the desired shift in the y-coordinate (integers only): ";
			cin >> newy;
		}

		x = x + newx;
		y = y + newy;
	}

	//Performs 90 degree rotations
	void rotatePoint()
	{
		int rotx = y;
		int roty = -x;

		x = rotx;
		y = roty;
	}

private:
	//initialize Points as variables
	int x;
	int y;
};

void display(Point myPoint);

int main(int argc, char* argv[])
{
	//create class myPoint
	Point myPoint;

	int rots;

	//User sets point values
	myPoint.setX();
	myPoint.setY();
	display(myPoint);
	//rotate
	cout << "How many times would you like to rotate your point around the origin: ";
	cin >> rots;

	while (rots > 0)
	{
		myPoint.rotatePoint();
		rots = --rots;
		display(myPoint);
	}

	//move point
	myPoint.movePoint();

	display(myPoint);

	return 0;
}

//display results
void display(Point myPoint)
{
	int x = myPoint.getX();
	int y = myPoint.getY();
	cout << "Your point is: (" << x << ", " << y << ")" << endl;
}
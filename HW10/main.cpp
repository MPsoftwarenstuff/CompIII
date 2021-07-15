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
Date: 11/21/2019
Name: Micah Perkins

Author: Micah Perkins
Date: 11/21/2019
Purpose: somethin wack
Sources of Help: internet, lectures
Time Spent: Always too much time not sure why these sections are even required
***********************************************/

//
// HW10.cpp
//
#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>

using namespace std;

void testPFArrayD(void);
void testException(void);

//exception class for Out of Range exception
class OutofRange {
public:
	//constructors
	OutofRange() { indexLog = 0; message = "You have violated the capacity of the array"; }
	OutofRange(int newIndex, string newMessage) { indexLog = newIndex; message = newMessage; }

	//accessors
	int index(void) const{ return indexLog; }
	string err(void) const{ cout << "Error at index [" << indexLog << "]" << endl; return message; }
private:
	int indexLog;
	string message;
};
//Objects of this class are partially filled arrays of doubles.
class PFArrayD
{
public:
	PFArrayD() { capacity = 50; a = new double[capacity]; used = 0; }
	//Initializes with a capacity of 50.

	PFArrayD(int capacityValue) { capacity = capacityValue; a = new double[capacity]; used = 0; }

	PFArrayD(const PFArrayD& pfaObject) { capacity = pfaObject.capacity; a = pfaObject.a; used = pfaObject.used; }

	void addElement(double element) {
		try {
			if (used >= capacity)
			{
				cout << "Attempted to exceed capacity in PFArrayD.\n";
				throw OutofRange((capacity+1), "Attempted to exceed capacity in PFArrayD\n");
			}
			a[used] = element;
			used++;
		}

		catch (OutofRange r1) {
			cout << r1.err() << endl;
		}
	}
	//Precondition: The array is not full.
	//Postcondition: The element has been added.

	bool full(void) const { return (capacity == used); }
	//Returns true if the array is full, false otherwise.

	int getCapacity(void) const { return capacity; }

	int getNumberUsed(void) const { return used; }

	void emptyArray(void) { used = 0; delete[] a; }
	//Empties the array.

	double& operator[](int index) const {

		try {
			if (index >= used || index < 0)
			{
				throw OutofRange(index, "Violated capacity of array using [] operator\n");
			}
			return a[index];
		}
		catch (OutofRange r1) {
			cout << r1.err() << endl;
		}
	}

	//Read and change access to elements 0 through numberUsed - 1.

	void operator =(const PFArrayD& rightSide) {
		this->emptyArray();
		capacity = rightSide.capacity;
		a = new double[rightSide.capacity];

		for (int i = 0; i < capacity; i++) {
			a[i] = rightSide.a[i];
		}
	}

	~PFArrayD() {
		delete[] a;
	}
private:
	double* a; //for an array of doubles.
	int capacity; //for the size of the array.
	int used; //for the number of array positions currently in use.

};

int main(int argc, char* argv[])
{
	cout << "This program tests the class PFArrayD.\n";
	///////////////////////////////////////////////////
	//NOTE TO GRADER: YOU CAN JUST COMMENT OUT THE 
	//TESTPFARRAYD FUNCTION CALL TO GET TO MY CODE FASTER
	///////////////////////////////////////////////////
	char ans;
	do
	{
		testPFArrayD();
		testException();
		cout << "Test again? (y/n) ";
		cin >> ans;
	} while ((ans == 'y') || (ans == 'Y'));

	return 0;
}

void testPFArrayD()
{
	int cap;
	cout << "Enter capacity of this super array: ";
	cin >> cap;
	PFArrayD temp(cap);

	cout << "Array initialized with " << temp.getCapacity() << " capacity" << endl;
	cout << "Enter up to " << cap << " nonnegative numbers.\n";
	cout << "Place a negative number at the end.\n";

	double next;
	cin >> next;
	while ((next >= 0) && (!temp.full()))
	{
		temp.addElement(next);
		cin >> next;
	}

	cout << "You entered the following "
		<< temp.getNumberUsed() << " numbers:\n";
	int index;
	int count = temp.getNumberUsed();
	for (index = 0; index < count; index++)
		cout << temp[index] << " ";
	cout << endl;
	cout << "(plus a sentinel value.)\n\n";
}


void testException(void) {
	
	int cap;
	cout << "Testing Exception handlers: " << endl;
	cout << "Enter capacity of this super array: ";
	cin >> cap;
	PFArrayD temp(cap);

	cout << "Array initialized with " << temp.getCapacity() << " capacity" << endl;
	cout << "Enter up to " << cap << " nonnegative numbers.\n";
	cout << "Place a negative number at the end.\n";

	double next;
	cin >> next;
	while ((next >= 0) && (!temp.full()))
	{
		temp.addElement(next);
		cin >> next;
	}

	cout << "You entered the following "
		<< temp.getNumberUsed() << " numbers:\n";
	int index;
	int count = temp.getNumberUsed();
	for (index = 0; index < count; index++)
		cout << temp[index] << " ";
	cout << endl;
	cout << "(plus a sentinel value.)\n\n";

	cout << "OPERATOR EXCEPTION SHOULD HAPPEN... NOW! " << endl;
	//access an index that does not exist or is below zero
	temp[index + 1];
	temp[-1];

	cout << "INSERT FUNCTION EXCEPTION SHOULD HAPPEN... NOW! " << endl;
	
	//just a quick loop that will exceed the capacity of the array
	for(int i = 0; i < ((temp.getCapacity()) + 2); i++) {
		temp.addElement(1);
	}
}

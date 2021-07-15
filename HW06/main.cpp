/***********************************************
Author: Micah Perkins
Date: 10/17/2019
Purpose: to create and test a dynamic array of strings without using vectors
Sources of Help: internet, classmates
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

using namespace std;

class DynamicStringArray {
public:
	//constructors
	DynamicStringArray() {
		size = 0;
		arrptr = nullptr;
	}
	DynamicStringArray(DynamicStringArray& old) {
		size = 0;
		arrptr = new string[size];

		for (int i = 0; i < old.size; i++) {
			push(old.arrptr[i]);
		}
	}
	//destructor
	~DynamicStringArray() {
		delete this;
	}

	//accessors
	int getSize() {
		cout << "size" << endl;
		return size;
	}
	string* get(int index) {
		if (index > size) {
			return nullptr;
		}
		string ans = arrptr[index];

		cout << "Retrieved string at array[" << index << "]: " << ans << endl;

		return &arrptr[index];
	}

	//create new array with new entry, then assign the class pointer to the new array. couts are for troubleshooting
	void push(string newstring) {
		size++;

		//create new array ptr
		string* newarrptr = new string[size]{};

		//loop to copy old array into new one
		if (size > 1) {
			for (int i = 0; i < (size - 1); ++i) {
				newarrptr[i] = arrptr[i];
			}
		}
		//put something in the new node of this array
		newarrptr[size - 1] = newstring;

		//reassign ptrs
		delete[] arrptr;
		arrptr = newarrptr;
	}
	//remove string from array
	bool pop(string del) {
		//create new array ptr
		string* newarrptr = new string[size - 1]{};
		cout << " pop" << endl;
		//loop to copy old array into new one if string is found
		if (size > 1) {
			for (int i = 0; i < (size - 1); ++i) {
				if (arrptr[i] == del) {

					for (int j = i; j < size - 1; j++) {
						int k = j + 1;

						newarrptr[j] = arrptr[k];

					}
					//reassign ptrs
					delete[] arrptr;
					arrptr = newarrptr;

					i = size + 1;
					size -= 1;
					return true;
				}

				newarrptr[i] = arrptr[i];
			}


		}
		return false;
	}
	//print the array
	void print() {
		for (int i = 0; i < size; ++i) {
			cout << arrptr[i] << endl;
		}
		cout << endl;
	}

	//assignment overload needs to be member function for ease of use
	void operator=(const DynamicStringArray& old)
	{
		for (int i = 0; i < old.size; i++) {
			push(old.arrptr[i]);
		}
	}
private:
	int size;
	string* arrptr;
};

bool test(void);

int main(int argc, char* argv[]) {
	if (test()) {
		return 0;
	}
	else {
		exit(1);
	}

	return 0;
}

bool test(void) {
	DynamicStringArray arr1;
	string test = "This";
	arr1.push(test);
	arr1.push("Program");
	arr1.push("Works");
	arr1.push("Properly");
	arr1.print();
	arr1.pop("Program");
	arr1.print();

	DynamicStringArray arr2(arr1);
	DynamicStringArray arr3(arr1);
	arr2.print();

	arr3 = arr2;

	string* getTest = arr1.get(2);

	string* getTest2 = arr2.get(2);

	return true;

	
}
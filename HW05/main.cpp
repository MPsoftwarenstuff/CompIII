/***********************************************
Author: Micah Perkins
Date: 9/29/2019
Purpose: to perform operations on fractions that are stored in classes
Sources of Help:
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
Date: 9/29/2019
Name:Micah Perkins
*/
#include <iostream>
#include <cstdlib>

using namespace std;

//class to store fractions
class Rational
{
public:
	//initialize all constructors
	Rational()
	{
		numer = 0;
		denom = 1;
	}
	Rational(int wholeNumber)
	{
		numer = wholeNumber;
		denom = 1;
	}
	Rational(int num, int den)
	{
		numer = num;
		denom = den;
	}
	Rational(const Rational& saveFrac)
	{
		numer = saveFrac.numer;
		denom = saveFrac.denom;
	}
	~Rational()
	{
	}

	//set numbers
	void setNumerThenDenom(int first, int second)
	{
		if (first == NULL)
		{
			Rational();
		}
		numer = first;

		if (second == NULL)
		{
			Rational(first);
		}
		denom = second;
	}

	//Display the fraction
	void showFraction()
	{
		cout << numer << "/" << denom << endl;
	}

	//Normalize a fraction
	int normalize(Rational& other)
	{
		if (getDenom() == other.getDenom()) {
			return getDenom();
		}
		int Numer1 = getNumer();
		int Numer2 = other.getNumer();

		setNumer(Numer1 * other.denom);
		other.setNumer(Numer2 * denom);

		int newDenom = denom * other.denom;

		setDenom(newDenom);
		other.setDenom(newDenom);

		cout << this->getNumer() << "..." << other.getNumer() << endl << getDenom() << ".." << other.getDenom() << endl;

		return newDenom;
	}

	//set or return fraction values if needed
	int getNumer()
	{
		return this->numer;
	}
	int getDenom()
	{
		return this->denom;
	}
	void setNumer(int newnum)
	{
		numer = newnum;
	}
	void setDenom(int newnum)
	{
		while (newnum == 0)
		{
			cout << "The denominator cannot be equal to 0. Please try again: ";
			cin >> newnum;
		}
		denom = newnum;
	}


	//assignment overload needs to be member function for ease of use
	void operator=(const Rational& compare)
	{
		numer = compare.numer;
		denom = compare.denom;
	}

private:
	//initialize fraction variables
	int numer;
	int denom;
};

//overload operators
const Rational operator+(Rational new1, Rational new2)
{
	Rational ans;

	int newDenom = new1.normalize(new2);
	int newNumer = new1.getNumer() + new2.getNumer();
	ans.setNumerThenDenom(newNumer, newDenom);

	return ans;
}
const Rational operator-(Rational new1, Rational new2)
{
	Rational ans;

	int newDenom = new1.normalize(new2);
	int newNumer = new1.getNumer() - new2.getNumer();

	ans.setNumerThenDenom(newNumer, newDenom);

	return ans;
}
const Rational operator*(Rational new1, Rational new2)
{
	Rational ans;
	int newDenom;
	int newNumer;

	newDenom = (new1.getDenom() * new2.getDenom());
	newNumer = new1.getNumer() * new2.getNumer();

	ans.setNumerThenDenom(newNumer, newDenom);

	return ans;
}
const Rational operator/(Rational new1, Rational new2)
{
	Rational ans;
	int newDenom;
	int newNumer;

	new2.setNumerThenDenom(new2.getDenom(), new2.getNumer());
	newDenom = (new1.getDenom() * new2.getDenom());
	newNumer = new1.getNumer() * new2.getNumer();

	ans.setNumerThenDenom(newNumer, newDenom);

	return ans;
}
const bool operator==(Rational& new1, Rational& new2)
{
	new1.normalize(new2);

	if (new1.getNumer() == new2.getNumer())
	{
		return true;
	}
	return false;
}
const bool operator!=(Rational& new1, Rational& new2)
{
	Rational firstFrac(new1);
	Rational secondFrac(new2);

	//make the first fraction GCF
	int newnumer1 = new1.getNumer() * new2.getDenom();
	int newdenom1 = new1.getDenom() * new2.getDenom();

	//cout << "!= Greatest Common Factor:" << newnumer1 << '/' << newdenom1 << endl;

	//GCF the second one
	int newnumer2 = new2.getNumer() * new1.getDenom();
	int newdenom2 = new2.getDenom() * new1.getDenom();

	//cout << "!= Greatest Common Factor:" << newnumer2 << '/' << newdenom2 << endl;


	if (newnumer1 == newnumer2 || newdenom1 == newdenom2)
	{
		return true;
	}
	return false;
}

//Comparison overload operators. did each section in chunks
const bool operator>=(Rational& new1, Rational& new2)
{
	new1.normalize(new2);

	if (new1.getNumer() != new2.getNumer())
	{
		return true;
	}
	return false;
}
const bool operator<=(Rational& new1, Rational& new2)
{
	new1.normalize(new2);

	if (new1.getNumer() <= new2.getNumer())
	{
		return true;
	}
	return false;
}
const bool operator>(Rational& new1, Rational& new2)
{
	new1.normalize(new2);

	if (new1.getNumer() > new2.getNumer())
	{
		return true;
	}
	return false;
}
const bool operator<(Rational& new1, Rational& new2)
{
	new1.normalize(new2);

	if (new1.getNumer() < new2.getNumer())
	{
		return true;
	}
	return false;
}

//shift operators section
ostream& operator<<(ostream& os, Rational& rShift)
{
	const int numer = rShift.getNumer();
	const int denom = rShift.getDenom();

	os << numer << "/" << denom << "     cout operator functioning" << endl;

	return os;
}
istream& operator>>(istream& os, Rational& rShift)
{
	int newnum;

	//what cin should be doing
	cout << "Enter numerator: ";
	cin >> newnum;
	rShift.setNumer(newnum);
	cout << "Enter denominator: ";
	cin >> newnum;
	rShift.setDenom(newnum);

	cout << rShift.getNumer() << '/' << rShift.getDenom() << endl << "cin operator functioning" << endl;

	return os;
}

//unit test program to check all operators and functions
int testRational();

int main(int argc, char argv[])
{
	int result = testRational();

	if (result == 1)
	{
		cout << "Something went wrong!" << endl;
	}

	return 0;

}

int testRational()
{
	//initialize two class objects for comparisons & operations
	Rational Whoo(-20, 5);
	Rational Whaa(4);

	cout << "Made Whoo ";  Whoo.showFraction();
	cout << "Made Whaa "; Whaa.showFraction();
	cout << endl;

	//check pemdas operators
	Rational Add = Whoo + Whaa;
	cout << "Add whoo and whaa:" << endl;
	Add.showFraction();

	Rational Sub = Whoo - Whaa;
	cout << "Subtract whoo and whaa:" << endl;
	Sub.showFraction();

	Rational mult = Whoo * Whaa;
	cout << "Multiply whoo and whaa:" << endl;
	mult.showFraction();

	Rational div = Whoo / Whaa;
	cout << "Divide whoo and whaa:" << endl;
	div.showFraction();

	cout << endl;

	//check constructors
	Rational copy(Whoo);
	Rational cinInit(1, 2);

	if (copy == Whoo)
	{
		cout << "copy constructor is functioning" << endl;
	}
	else if (copy != Whoo)
	{
		cout << "Check copy constructor" << endl;
	}

	//check equal comparison operators
	if (Whoo == Whaa)
	{
		cout << "These fractions are equal to each other" << endl;
	}
	else if (Whoo != Whaa)
	{
		cout << "These fractions are not equal" << endl;
	}

	if (Whoo >= Whaa)
	{
		cout << "Whoo is equal to or greater than Whaa" << endl;
	}
	else if (Whaa >= Whoo)
	{
		cout << "Whaa is equal to or greater than Whoo" << endl;
	}

	if (Whoo > Whaa)
	{
		cout << "Whoo is greater than Whaa" << endl;
	}
	else if (Whaa > Whoo)
	{
		cout << "Whaa is greater than Whoo" << endl;
	}

	cout << endl << "Print out Whoo: " << endl << Whoo << endl;

	//check assignment operator
	cout << "Set Whoo equal to Whaa: " << endl;
	Whoo = Whaa;
	cout << "Whoo: " << Whoo;
	cout << "Whaa: " << Whaa << endl;

	cout << "initialize a new class using cin" << endl;
	cin >> cinInit;

	return 0;
}
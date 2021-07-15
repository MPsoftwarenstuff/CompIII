/***********************************************
Author: Micah Perkins
Date: 9/27/2019
COMP.2010 HW 04 F19 - Dr. Lin
Purpose: my program stores zipcodes and translates them into binary bar codes with error checking
Sources of Help: internet, tutors, and group study
Time Spent: 4 hours
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
Date: 9/27/2019
Name: Micah Perkins
*/
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

//declare class
class ZipCode
{
public:
	//constructors
	ZipCode()
	{
		zipcode = 0;
	}
	ZipCode(int zip)
	{
		zipcode = zip;
	}
	ZipCode(string bar)
	{
		//if (!test(bar))
		//{
		//	cout << "Error! invalid Barcode" << endl;
		//}
		//else if (test(bar))
		//{
			zipcode = this->barToZip(bar);
		//}
	}

	//retrieve private variables
	int getZipCode()
	{
		return zipcode;
	}
	string getBarCode()
	{
		return zipToBar(this->zipcode);
	}

	//Error checking functions
	bool test(string testbar)
	{
		//if length of bar code is not 27 something is wrong. Abort
		if (testbar.length() != 27)
		{
			cout << "Invalid bar code!\n";
			return false;
		}
		//if first digit is not 1 something is wrong. Abort
		if (testbar[0] != 1)
		{
			return false;
		}
		//if last digit is not 1 something is wrong. Abort
		if (testbar[26] != 1)
		{
			return false;
		}

		const short GROUP = 5; //groups of five binary digits form each barcode

		//test for exactly two 1's in each group of five digits. count will skip index 0 of string and last digit of string
		for (short count = 1; count < testbar.length() - 1; count += GROUP)
		{
			short ones = 0;



			for (short index = 0; index < GROUP; index++)
			{
				if (testbar[count + index] == '1')
					++ones;
			}
			if (ones != 2)//if set of five binary digits does not contain exactly two "1" digits
			{
				cout << "Invalid bar code!\n";
				return false;
			}
		}

		return true;
	}
private:
	int zipcode;

	string zipToBar(int zip)
	{
		const short GROUP = 5;//number of binary digits per group
		const short ENCODE[] = { 7, 4, 2, 1, 0 };

		string bar;
		short zipdigit = 0;
		while (zip > 0)
		{
			string group = "00000";//group of five binary digits
			zipdigit = zip % 10;//zipdigit will hold integer from zip code starting in reverse order
			zip = zip / 10;//zip is truncated to have one less integer

			for (short i = 0; i < GROUP; i++)
			{
				for (short u = i + 1; u < GROUP; u++)
				{
					if (zipdigit == 0 && ENCODE[i] + ENCODE[u] == 11)
					{
						group[i] = '1';
						group[u] = '1';
						bar.insert(0, group);
					}
					if (zipdigit == ENCODE[i] + ENCODE[u])
					{
						group[i] = '1';
						group[u] = '1';
						bar.insert(0, group);
					}
				}
			}
		}

		bar.insert(0, "1");
		bar.insert(bar.length(), "1");

		return bar;
	}

	int barToZip(string bar)
	{
		const short GROUP = 5;//number of binary digits per group
		const short ENCODE[] = { 7, 4, 2, 1, 0 };
		const string barcode = bar;

		string strzip;
		short count = 1;
		while (count < (short)(barcode.length() - 1))
		{
			int mult = 0;
			for (short i = 0; i < GROUP; i++)
			{
				mult += (barcode[count++] - 48) * ENCODE[i];
				if (mult == 11)
					mult = 0;
			}
			strzip += to_string(mult);
		}
		
		int zip = atoi(strzip.c_str());
		return zip;
	}
};

int main(int argc, char* argv[]) {
	ZipCode zip(99504),
		zip2("100101010011100001100110001"),
		zip3(12345),
		zip4(67890);

	cout << zip.getZipCode() << "'s bar code is '"
		<< zip.getBarCode() << "'" << endl;
	cout << zip2.getZipCode() << "'s bar code is '"
		<< zip2.getBarCode() << "'" << endl;
	cout << zip3.getZipCode() << "'s bar code is '"
		<< zip3.getBarCode() << "'" << endl;
	cout << zip4.getZipCode() << "'s bar code is '"
		<< zip4.getBarCode() << "'" << endl;

	cout << endl;

	// Test a range of values by constructing a zip code
	// using an integer, then retrieving the bar code and using
	// that to make another ZipCode.
	int zip_int = 0;
	for (int i = 0; i < 25; i++)
	{
		// Make an arbitrary 5-digit zip code integer, construct a ZipCode
		int five_digit_zip = (zip_int * zip_int) % 100000;
		ZipCode z1(five_digit_zip);

		// Construct a second ZipCode from the first's bar code
		string z1_barcode = z1.getBarCode();
		ZipCode z2(z1_barcode);

		cout.width(3);
		cout << (i + 1) << ": ";
		cout.width(5);
		cout << z2.getZipCode() << " has code '"
			<< z1_barcode << "'";

		if ((z1_barcode == z2.getBarCode()) &&
			(z1.getZipCode() == z2.getZipCode()) &&
			(z2.getZipCode() == five_digit_zip))
		{
			cout << " [OK]" << endl;
		}
		else
		{
			cout << " [ERR]" << endl;
		}

		// Increment the test value arbitrarily
		zip_int += (233 + zip_int % 7);
	}
	cout << endl;

	// Test some error conditions. This test assumes that
	// ZipCode will simply set its value to a flag that indicates
	// an error, and will not exit the program.
	string bad_zips[][2] = {
		{ "100101010011100001100110000", "bad start/end character" },
		{ "100101010011100001100110021", "bad digit" },
	};

	const int BAD_ZIP_COUNT = 2;
	for (int i = 0; i < BAD_ZIP_COUNT; i++)
	{
		cout << "Testing: " << bad_zips[i][1] << " " << bad_zips[i][0] << endl;
		ZipCode test(bad_zips[i][0]);
		cout << endl;
	}

	cout << "Enter a character to quit." << endl;
	char c;
	cin >> c;
	return 0;
}
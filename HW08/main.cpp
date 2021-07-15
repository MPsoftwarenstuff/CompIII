#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Person {
public:
	//Constructors
	Person() : name("No name") {}
	Person(string theName) : name(theName) {}
	Person(const char* theName) : name(theName) {}
	Person(const Person& theName) : name(theName.name) {} //Copy Constructor

	//Accessor methods
	string getName() const {
		return name;
	}

	//Overloaded assignment operator
	Person& operator =(const Person& thePerson) {
		this->name = thePerson.name;
		return *this;
	}
	friend istream& operator>>(istream& inStream, Person& personObject) {
		inStream >> personObject.name;
		return inStream;
	}
	friend ostream& operator<<(ostream& outStream, const Person& personObject) {
		outStream << personObject.name;
		return outStream;
	}
private:
	string name;
};

class Vehicle {
public:
	//Constructors
	Vehicle() : manuName("No Manufacturer"), numCyl(0), owner("No Owner") {}
	Vehicle(string theManuName, int theNumCyl, const Person& theOwner)
		: manuName(theManuName),
		numCyl(theNumCyl),
		owner(theOwner) {}
	Vehicle(const Vehicle& theVehicle)
		: manuName(theVehicle.manuName),
		numCyl(theVehicle.numCyl),
		owner(theVehicle.owner) {}

	//Accessor methods
	string getManuName() {
		return manuName;
	}
	int getNumCyl() {
		return numCyl;
	}
	Person getOwner() {
		return owner;
	}

	//Overloaded Assignment Operator
	Vehicle& operator =(const Vehicle& theVehicle) {
		this->manuName = theVehicle.manuName;
		this->numCyl = theVehicle.numCyl;
		this->owner = theVehicle.owner;
		return *this;
	}
	friend ostream& operator<<(ostream& outStream, const Vehicle &vehicleObject) {
		outStream << vehicleObject.manuName << ", Cylinders: " << vehicleObject.numCyl << ", Owner: " << vehicleObject.owner << endl << endl;

		return outStream;
	}

protected:
	string manuName;
	int numCyl;
	Person owner;
};

class Truck : public Vehicle {
public:
	//Constructors
	Truck() : capTons(0.0), capPounds(0) {}
	Truck(double theCapTons, int theCapPounds, string theManuName, int theNumCyl, const Person& theOwner)
		: Vehicle(theManuName, theNumCyl, theOwner),
		capTons(theCapTons),
		capPounds(theCapPounds) {}
	Truck(const Truck& theTruck) //Copy Constructor.
		: Vehicle(theTruck),
		capTons(theTruck.capTons),
		capPounds(theTruck.capPounds) {}
	//Overloaded Assigment Operator
	Truck& operator =(const Truck& theTruck) {
		Vehicle::operator =(theTruck);
		capTons = theTruck.capTons;
		capPounds = theTruck.capPounds;
		return *this;
	}
	friend ostream& operator<<(ostream& outStream, const Truck& truckObject) {
		outStream << truckObject.manuName << ", Cylinders: " << truckObject.numCyl << ", Owner: " << truckObject.owner << ", Load Cap: " << truckObject.capPounds << ", Tow Cap: " << truckObject.capTons << endl << endl;

		return outStream;
	}
	//Accessor methods
	double getCapTons() {
		return capTons;
	}
	int getCapPounds() {
		return capPounds;
	}
private:
	double capTons;
	int capPounds;
};

void test(void);

int main() {

	test();

	return 0;
}

void test(void) {
	cout << "//////////////// TESTING PERSON CLASS ////////////////" << endl;
	Person p1("Sirong Lin");
	Person p2;
	Person p3(p1);

	cout << "Testing default constructor: Name: " << p2.getName() << endl << endl;
	cout << "Testing string constructor: Name: " << p1.getName() << endl << endl;
	cout << "Testing copy constructor : Name: " << p3.getName() << endl << endl;
	cout << "Testing >> overload: Enter your name: ";
	cin >> p2;
	cout << endl << "Validate operation: You entered: " << p2.getName() << endl << endl;
	/////////////////////////////////////////////////////////////////////////
	cout << "//////////////// TESTING VEHICLE CLASS ////////////////" << endl;
	Vehicle v1("Ford Van", 8, p1);
	Vehicle v2;
	Vehicle v3(v1);


	cout << "Testing default constructor: Vehicle info: " << endl << v2.getManuName() << ", Cylinders: " << v2.getNumCyl() << ", Owner: " << v2.getOwner() << endl << endl;
	cout << "Testing string constructor: Vehicle info: " << endl << v1.getManuName() << ", Cylinders: " << v1.getNumCyl() << ", Owner: " << v1.getOwner() << endl << endl;
	cout << "Testing copy constructor : Vehicle info: " << endl << v3.getManuName() << ", Cylinders: " << v3.getNumCyl() << ", Owner: " << v3.getOwner() << endl << endl;

	v2 = v3;

	cout << "Testing = overload: " << endl << v2.getManuName() << ", Cylinders: " << v2.getNumCyl() << ", Owner: " << v2.getOwner() << endl << endl;
	cout << "Testing << overload: " << endl << v1;
	///////////////////////////////////////////////////////////////////////
	cout << "//////////////// TESTING TRUCK CLASS ////////////////" << endl;
	Truck t1(250.0, 2000, "Mac", 8, "Mike Elf");
	Truck t2;
	Truck t3(t1);


	cout << "Testing default constructor: Truck info: " << endl << t2.getManuName() << ", Cylinders: " << t2.getNumCyl() << ", Owner: " << t2.getOwner() << ", Load Cap: " << t2.getCapPounds() << ", Tow Cap: " << t2.getCapTons() << endl << endl;
	cout << "Testing string constructor: Truck info: " << endl << t1.getManuName() << ", Cylinders: " << t1.getNumCyl() << ", Owner: " << t1.getOwner() << ", Load Cap: " << t1.getCapPounds() << ", Tow Cap: " << t1.getCapTons() << endl << endl;
	cout << "Testing copy constructor : Truck info: " << endl << t3.getManuName() << ", Cylinders: " << t3.getNumCyl() << ", Owner: " << t3.getOwner() << ", Load Cap: " << t3.getCapPounds() << ", Tow Cap: " << t3.getCapTons() << endl << endl;

	t2 = t3;

	cout << "Testing = overload: " << endl << t2.getManuName() << ", Cylinders: " << t2.getNumCyl() << ", Owner: " << t2.getOwner() << ", Load Cap: " << t2.getCapPounds() << ", Tow Cap: " << t2.getCapTons() << endl << endl;
	cout << "Testing << overload: " << endl << t1;

}

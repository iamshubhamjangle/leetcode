/*
OOPS.cpp

Reference: OOPS.md
*/

#include <bits/stdc++.h>
using namespace std;


class AbstractCar {
	virtual void start() = 0;		// every car should have start
	virtual void stop() = 0;		// every car should have stop
};


// Base Class - Parent class
class Car: AbstractCar {
protected:
	string name;		// if child class has to access properties of parent without making it public.
private: 
	string color;
	int year;

public:
	Car() {}
	Car(string Name, string Color, int Year) {
		name = Name;
		color = Color;
		year = Year;
	}

	string getName() { return name; }
	void print() { cout << name << " is " << color << " in color manufactured in year " << year << endl; }
	void start() { cout<< name <<" is started!"<< endl; }
	void stop() { cout<< name <<" is stopped!"<< endl; }
	virtual void fuel() { cout << name << " is fuel up with Petrol" << endl; }	// Polymorphism - check if same class is present in child. If yes run it.
};


// Inherited class - Child Class
class Electric: public Car {
	int battery;

public:
	Electric() {}
	Electric(string Name, string Color, int Year, int Battery): Car(Name, Color, Year) { battery = Battery; }

	void drive() { cout << getName() << " has started driving!" << endl; }
	void fuel() { cout << name << " is charged with electicity." << endl; }
};

int main(){
	Car car1("Porche", "NightSky", 2022);
	car1.start();
	car1.print();
	car1.fuel();

	Electric car2("Tesla", "Texas", 2025, 100);
	car2.start();		// make inheritance public to access the methods of parent
	car2.drive();
	car2.fuel();		// Polymorphism - overwritten base class method
	Car* c = &car2;		// Parent can hold reference to child.
	c -> fuel();		// And call child's method if virtual keyword present in parent method
}
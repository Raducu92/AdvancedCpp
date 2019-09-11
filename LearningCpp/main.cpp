#include <iostream>
#include <vector>
#include "AdvancedCpp.h"
#include <conio.h>
using namespace std;

// fast tests
class dummyClass {

public:
	string name;
	int age;

	int* v;
	int accessCounter;

	dummyClass() {
		this->age = 0;
		this->accessCounter = 0;
		this->name = "dummy name";
		this->v = (int*)calloc(10, sizeof(int));
	}

	// if we remove &, const will be useless because, the function will return a copy of name
	//					it will not make the ref const after call
	const string& getName() {	
		return name;
	}
	  
	string getName() const {
		return name;
	}

	void printName() const {	// this type of function will not change any member of class (1)
								// a const function can call only const functions	(2)
		cout << "const function : " << name << endl << endl;
		//this->age++; // case 1
		//getName(); // case 2
		cout << "call another const-function " << getName() << endl << endl; // legal

	}

	void printName()  {	
		cout << "non-const function : " << name << endl << endl;
		cout << "call a non-const-function " << getName() << endl << endl;

	}

	/*
		difference between printName()  and printName const :	
			printName const will be invoked only if dummyClass obj is const
			printName will be invoked only if dummyClass obj is not-const

		This will happen only if we have 2 methods with the same name (overloading)
	*/

	// CONSTNESS Tests
	void printVector() {
		for (int i = 0; i < 10; i++) {	// ?
			cout << v[i] << " ";
		}
		cout << endl;
	}

	// int *v -> toate elementele pe 0
	void setVectorItem(int index, int x) const {
		*(v + index) = x;
	}
	// main setVectorItem(0, 9);

	~dummyClass() {
		_getch();
	}




};

int main() {

	dummyClass dc;	// -> will invoke printName()
	// const dummyClass dc;	-> will invoke printName() const
	//const string& test = dc.getName();
	// ilegal, getName returns a const string&, so after you catch it into a variabile will be not be able to change it
	//test = "TryChange"; 
	//cout << test << endl << endl;

	//dc.printName();
	//dc.setVectorItem(0, 9);
	//dc.printVector();

	//AdvancedCpp tutorial;

	//tutorial.loadLesson(AdvancedCpp::CONST);  // 1
	//tutorial.loadLesson(AdvancedCpp::CONST_AND_FUNCTIONS); // 2
	//tutorial.loadLesson(AdvancedCpp::CONSTNESS); // 3

	return 0;
}
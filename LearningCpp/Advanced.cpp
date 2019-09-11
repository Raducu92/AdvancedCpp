#include "AdvancedCpp.h"
#include <stdlib.h> // random
#include <iostream>
#include<conio.h>
using namespace std;

AdvancedCpp::~AdvancedCpp() {
	cout << "AdvancedCpp destructor called." << endl;
	_getch();
}

void AdvancedCpp::loadLesson(Lessons  lesson)
{
	switch (lesson) {
		case Lessons::CONST: 
			this->constLesson();
			break;
		case Lessons::CONST_AND_FUNCTIONS:
			this->constAndFunctionLesson();
			break;
		case Lessons::CONSTNESS:
			this->constness();
			break;

		default:
			cout << "Lesson not reached";
			break;
	}
}

// constHelper

int AdvancedCpp::constHelper(const int i)
{
	cout << "const_cast through function ! before: " << i << endl;
	return const_cast<int&>(i) = rand() % 100;
}
void AdvancedCpp::constLesson() {
	cout << "CONST LESSON \n\n";
	cout << "const = A compile time constraint that an object can not be modified\n";
	cout << "Rules : if const is on the left of *, data is const otherwise pointer is const\n\n";
	int j = 10;
	const int i = 9;
	//i = 6 -> error

	const int *p1 = &i; // data is const, pointer is not
	int* const p2 = &j;
	cout << "\nint* const p2 = &j where j = 10 \, ++(*p2) = " << ++(*p2);

	cout << "\nconst int i = 9; \nconst int *p1 = &i;" << endl << endl;
	cout << "&i = " << &i << endl;
	cout << "p1 = " << p1 << endl;
	cout << "*p1 = " << *p1 << endl;
	cout << "&p1 = " << &p1 << endl;

	cout << "\nconst_cast<int&>(*p1)++; won't increase the i value, need to be ++const_cast<int&>(*p1)\n\n";
	cout << ++const_cast<int&>(*p1) << endl;

	int nonConstValue = 0;
	cout << "\nAfter after " << constHelper(nonConstValue) <<  "\n\n";
	

	cout << "const_cast -> convert a const into a non-const\nstatic_cast -> convert a non-const to a const";
	cout << endl;
	int k = 9;
	static_cast<const int&>(k); // k is const now
	++k;
	cout << "\nint k = 9; \nstatic_cast<const int&>(k) -> temp const; ++k; k = " << k << endl; // now is not, and can change it
}

// end constHelper

//==========================================================================

// constAndFunctionLesson

void AdvancedCpp::constAndFunctionLesson() {
	cout << "CONST AND FUNCTIONS LESSON \n\n";
	Dog d;
	
	int i = 9;
	const int j = 10;
	d.setAge(i);
	cout << i << endl;

	d.setAge(j);
	cout << j << endl;


}


Dog::Dog() {
	cout << "Dog constructor called." << endl;
	this->age = 3;
	this->name = "dummy";
}

Dog::~Dog() {
	cout << "\n\nDog destructor called." << endl;
	_getch();
}

void Dog::setAge(int &a) {	// will be called if my parameter ref is not a const
	cout << "\n non-const function called." << endl;
	this->age = a;
	// a++; legal if function is not const,  int& a  as parameter
}

/*
	setAge(int a) {}
	setAge(const int a ) {}
	-- error,  both functions are the same, cannot be overloaded
*/


// @overloding
void Dog::setAge(const int& a) { // will be called if my paramter ref is const
	cout << "\n const function called." << endl;
	this->age = 69;
	// a++; ilegal, won't work, because a   is const
}

// end constAndFunctionLesson

//==========================================================================

// constness

void AdvancedCpp::constness() {
	cout << "CONSTNESS LESSON \n\n See dummyTest class from main file.\n\n";

	// mutable is used to allow you to change class variable value even if the function is const
	/*
		class A {

			int a;
			mutual int a2;
			A() {
				this->a = 0;
				this->a2 = 0;
			}

			void changeA() const {
				this->a++; // ilegal
				this->a2++; // legal, thanks to mutual (solution 1)
				const_cast<A*>(this)->a++; (solution 2)
			}

		};
	*/

}

// end constness
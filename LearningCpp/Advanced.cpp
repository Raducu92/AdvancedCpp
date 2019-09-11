#include "AdvancedCpp.h"

#include <iostream>
using namespace std;
void AdvancedCpp::loadLesson(Lessons  lesson)
{
	switch (lesson) {
		case Lessons::CONST: 
			this->constLesson();
			break;
		case Lessons::CONST_AND_FUNCTIONS:
			this->constAndFunctionLesson();
			break;

		default:
			cout << "Lesson not reached";
			break;
	}
}

int AdvancedCpp::constHelper(const int i)
{
	cout << "const_cast through function ! i before : " << i << endl;
	return const_cast<int&>(i) = 10;
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

	cout << constHelper(i);
	cout << "\ni after \n\n";

	cout << "const_cast -> convert a const into a non-const\nstatic_cast -> convert a non-const to a const";
	cout << endl;
	int k = 9;
	static_cast<const int&>(k); // k is const now
	++k;
	cout << "\nint k = 9; \nstatic_cast<const int&>(k) -> temp const; ++k; k = " << k << endl; // now is not, and can change it
}

void AdvancedCpp::constAndFunctionLesson() {
	cout << "CONST AND FUNCTIONS LESSON \n\n";
}
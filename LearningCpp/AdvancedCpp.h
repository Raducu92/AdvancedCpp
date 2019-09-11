#pragma once
#ifndef __ADVANCED_CPP__
#define __ADVANCED_CPP_

#include <string>
using namespace std;

class AdvancedCpp {
private:
	void constLesson();
	int constHelper(const int i);
	void constAndFunctionLesson();
	void constness();

public:
	const enum Lessons
	{
		CONST,
		CONST_AND_FUNCTIONS,
		CONSTNESS
	};
	void loadLesson(Lessons lesson);
	~AdvancedCpp();
};


class Dog {

	int age;
	string name;

public:
	Dog();
	~Dog();
	void setAge(int& a);
	void setAge(const int &a);

};

#endif // !__ADVANCED_CPP__


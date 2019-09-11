#pragma once
#ifndef __DOG_H_
#define __DOG_H_
#include <iostream>
using namespace std;
class Dog {

	int age;
	string name;

public:
	Dog();
	~Dog();
	void setAge(const int a);
	int getAge();
	void setName(string name);
	string getName();

	void printTest();
	void printTest() const;

	void printA(int& a);
	void printA(const int& a);

};


#endif // !__DOG_H_


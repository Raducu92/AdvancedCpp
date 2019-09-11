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

};

#endif // __DOG_H_

// Teste.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include "Dog.h"
using namespace std;
int main()
{
	Dog d;
	d.setAge(69);
	cout << "Age = " << d.getAge() << endl;
	
    return 0;
}


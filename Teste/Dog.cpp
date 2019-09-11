#include "Dog.h"

Dog::Dog() {
	cout << "Constructor called." << endl;
}

Dog::~Dog() {
	cout << "Destructor called." << endl;
}

int Dog::getAge() {
	return this->age;
}

void Dog::setAge(const int a) {
	this->age = a;
}

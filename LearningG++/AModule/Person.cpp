#include <iostream>
#include "Person.h"

using namespace std;

Person::Person(int age){
    this->age = age;
    cout << "constructor : Person(int age) " << endl;
}


Person::~Person(){
    cout << "destructor : ~Person() " << endl;
}

void Person::printAge(){
    cout << "Person : printAge() " << this->age << endl;
}


void Person::doSomething(){
    cout << "Perosn : doSomething " << endl;
    cout << "Person : modified the second version" << endl;
}



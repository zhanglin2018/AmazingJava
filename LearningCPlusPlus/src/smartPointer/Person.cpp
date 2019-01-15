/**
 * Copyright by Advantest, 2019
 *
 * @author  linzhang
 * @date    Jan 11, 2019
 *
 *
 *
 */


#include "Person.h"
#include <iostream>
using std::cout;
using std::endl;


Person::Person(string name, string sex){
  std::cout << "constructor: Person(string name, string sex) \n " <<
      name << ": " << sex << std::endl;
  this->name = name;
  this->sex = sex;
}


Person::~Person(){
  std::cout << "delete constructor : ~Person() \n    " <<
        name << ": " << sex << std::endl;
}

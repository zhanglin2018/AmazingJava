/**
 * Copyright by Advantest, 2019
 *
 * @author  linzhang
 * @date    Jan 13, 2019
 */
#pragma once
#include <iostream>
#include <boost/smart_ptr.hpp>
using namespace std;

class Parent;
class Child;

class Parent{
public:
  Parent(){
    cout << "constructor : Parent" << endl;
  }
  ~Parent(){
    cout << "delete constructor : Parent" << endl;
  }

  boost::shared_ptr<Child> child;
};

class Child{
public:
  Child(){
    cout << "constructor : Child" << endl;
  }
  ~Child(){
    cout << "delete constructor : Child" << endl;
  }

  boost::shared_ptr<Parent> parent;
};






/**
 * Copyright by Advantest, 2019
 *
 * @author  linzhang
 * @date    Jan 13, 2019
 */
#pragma once

#include <iostream>
using namespace std;


/*
 * summary:
 *  Polimophism:
 *      one: virtual
 *      two: pointer
 *      three: subClass derived superClass
 *
 *  virtual destructors are usually used in superclass.
 */


class Base {
public:
  Base()
  {
    cout << "Base::Base()" << endl;
  }

  virtual ~Base()
  {
    cout << "Base::~Base()" << endl;
  }

  virtual void testPublicFunc(){
    cout << "Base : testPublicFunc" << endl;
  }

  void testBase1(){
    cout << "Base : testBase1" << endl;

  }

protected:
  void testProtectedFunc(){
      cout << "Base : testProtectedFunc" << endl;
    }

private:
  void testPrivateFunc(){
        cout << "Base : testPrivateFunc" << endl;
      }
};

class Derived : public Base {
public:
  Derived()
  {
    cout << "Derived::Derived()" << endl;
  }

  virtual ~Derived()
  {
    cout << "Derived::~Derived()" << endl;
  }

  virtual void testPublicFunc(){
      cout << "Derived : testPublicFunc" << endl;
    }

  void testDerived1(){
    cout << "Derived : testDerived1" << endl;

  }

protected:
  void testProtectedFunc(){
        cout << "Derived : testProtectedFunc" << endl;
      }

};

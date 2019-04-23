/**
 * Copyright by Advantest, 2019
 *
 * @author  linzhang
 * @date    Jan 13, 2019
 */

#include <iostream>
#include <boost/smart_ptr.hpp>
#include "BaseAndDerived.hpp"
using namespace std;

/**
 * summary : boost::weak_ptr is specially prepared for boost::shared_ptr.
 *
 *
 */

void testDerivedPtr1()
{
  boost::shared_ptr<Base> base(new Base());
  base->testPublicFunc();
  base->testBase1();
  assert(base.use_count() == 1);

}

void testDerivedPtr2()
{

  boost::shared_ptr<Derived> derived(new Derived);
  derived->testPublicFunc();
  derived->testBase1();
  derived->testDerived1();
  assert(derived.use_count() == 1);
}

void testDerivedPtr4()
{
  Base * base = new Derived();
  base->testBase1();
  base->testPublicFunc();
  delete base;
}

void testDerivedPtr3()
{
  boost::shared_ptr<Base> base(new Derived());
  base->testBase1();
  base->testPublicFunc();
  assert(base.use_count() == 1);
}

void testDerivedPtr5()
{
  boost::shared_ptr<Base> base(new Derived());
  base->testBase1();
  base->testPublicFunc();
  assert(base.use_count() == 1);

  cout << "\n" << endl;
  boost::weak_ptr<Base> base1(base);
  assert(base1.use_count() == 1);
  base1.lock()->testBase1();
  base1.lock()->testPublicFunc();
}

int mainSmartDerived(int argc, char **argv)
{
//  testDerivedPtr1();
//  testDerivedPtr2();
//  testDerivedPtr3();
//  testDerivedPtr4();
  testDerivedPtr5();


  int array[10];

  for (int i=0; i<10; i++){
    array[i] = i;
  }

  for (int i=0; i<10; i++){
    cout << array[i] << endl;
  }

//  char *str = "abcd";
//  str[10] = 'A';
//
//  cout << str << endl;

  return 0;
}


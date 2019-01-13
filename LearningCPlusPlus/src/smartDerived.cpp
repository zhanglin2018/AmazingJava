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

int main(int argc, char **argv)
{
//  testDerivedPtr1();
//  testDerivedPtr2();
//  testDerivedPtr3();
  testDerivedPtr4();
  return 0;
}


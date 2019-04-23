/**
 * Copyright by Advantest, 2019
 *
 * @author  linzhang
 * @date    Jan 13, 2019
 */

#include <iostream>
#include <boost/smart_ptr.hpp>
#include "Simple.h"
using namespace std;

/**
 * summary : boost::weak_ptr is specially prepared for boost::shared_ptr.
 *
 * boost::weak_ptr is mainly used in software architecture design.
 */

void testWeakPtr1()
{
  boost::shared_ptr<Simple> memory(new Simple(1));

  if (memory.get()) {
    memory->printSomething();
    memory->info_extend = "Addition";

    memory->printSomething();
    (*memory).info_extend += " other";

    memory->printSomething();
  }

  cout << "testWeakPtr1.use_count : " << memory.use_count() << endl;

  boost::shared_ptr<Simple> memory2 = memory;

  cout << "testWeakPtr1.use_count : " << memory.use_count() << endl;


  boost::shared_ptr<Simple> memory3(memory2);

  cout << "testWeakPtr1.use_count : " << memory.use_count() << endl;


}

/*
 *
 */
void testWeakPtr2()
{
  boost::shared_ptr<Simple> memory(new Simple(1));

  if (memory.get()) {
    memory->printSomething();
    memory->info_extend = "Addition";

    memory->printSomething();
    (*memory).info_extend += " other";

    memory->printSomething();
  }

  cout << "testWeakPtr1.use_count : " << memory.use_count() << endl;

  boost::weak_ptr<Simple> memory3 = memory;

  cout << "testWeakPtr1.use_count : " << memory.use_count() << endl;

}

/*
 *
 */
void testWeakPtr3()
{
  boost::shared_ptr<Simple> sp(new Simple(1));
  assert(sp.use_count() == 1);

  boost::weak_ptr<Simple> wp(sp);
  assert(wp.use_count() == 1);
  assert(sp.use_count() == 1);

  if (!wp.expired()){  // is expired
    boost::shared_ptr<Simple> sp2 = wp.lock();
    assert(sp2.use_count() == 2);
    assert(wp.use_count() == 2);
  }

  assert(wp.use_count() == 1);
  assert(sp.use_count() == 1);

  boost::shared_ptr<Simple> sp3 = wp.lock();
  assert(sp3.use_count() == 2);
  assert(wp.use_count() == 2);
}

/*
 * Test the reset function of the boost::shared_ptr smart pointer.
 */
void testWeakPtr4()
{
  boost::shared_ptr<Simple> sp(new Simple(1));
  assert(sp.use_count() == 1);

  boost::weak_ptr<Simple> wp(sp);
  assert(wp.use_count() == 1);
  assert(sp.use_count() == 1);

  sp.reset();
  assert(sp.use_count() == 0);

  assert(wp.expired());
  assert(wp.lock() == NULL);
}

int mainWeak(int argc, char **argv)
//int main(int argc, char **argv)
{
//  testWeakPtr1();
//  testWeakPtr2();
//  testWeakPtr3();
  testWeakPtr4();
  return 0;
}


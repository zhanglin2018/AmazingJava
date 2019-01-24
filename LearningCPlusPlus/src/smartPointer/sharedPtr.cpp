/**
 * Copyright by Advantest, 2019
 *
 * @author  linzhang
 * @date    Jan 13, 2019
 */

#include <iostream>
#include <boost/smart_ptr.hpp>
#include "Simple.h"
#include "circleRef.hpp"
#include "circleRef_Weak.hpp"
using namespace std;

/**
 * summary : boost::shared_ptr smart pointer can share pointer and transform the manager power.
 */

/*
 * You don't need to use reference or const reference.
 */
void sharedPtr(boost::shared_ptr<Simple> memory)
{
  memory->printSomething();
  cout << "sharedPtr(boost::shared_ptr<Simple> memory).use_count: "
      << memory.use_count() << endl;
}

void testSharedPtr1()
{
  boost::shared_ptr<Simple> memory(new Simple(1));

  if (memory.get()) {
    memory->printSomething();
    memory->info_extend = "Addition";

    memory->printSomething();
    (*memory).info_extend += " other";

    memory->printSomething();
  }

}

/**
 * summary: shared_ptr could transform the access.
 */
void testSharedPtr2()
{
  cout << "\ntestSharedPtr2:" << endl;
  boost::shared_ptr<Simple> memory(new Simple(1));

  if (memory.get()) {
    memory->printSomething();
    memory->info_extend = "Addition";

    memory->printSomething();
    (*memory).info_extend += " other";

    memory->printSomething();
  }

  cout << "testSharedPtr2.use_count : " << memory.use_count() << endl;

  sharedPtr(memory);

  cout << "testSharedPtr2.use_count : " << memory.use_count() << endl;
}

// The delete constrctor function was called twice, resulting in an error.
void testSharedPtr3()
{
  cout << "\ntestSharedPtr3:" << endl;
  Simple* simple = new Simple(1);
  boost::shared_ptr<Simple> memory(simple);
//  boost::shared_ptr<Simple> memory2(simple);
}

void testSharedPtr4()
{
  boost::shared_ptr<Simple> memory(new Simple(10));

    if (memory.get()) {
      memory->printSomething();
      memory->info_extend = "Addition";

      memory->printSomething();
      (*memory).info_extend += " other";

      memory->printSomething();
    }
}


/**
 * Problem:
 *     circular references cause memory leaks.
 */
void testCircleRef(){
  boost::shared_ptr<Parent> parent(new Parent());
  boost::shared_ptr<Child> child(new Child());

  cout << "parent.use_count" << parent.use_count() << endl;
  cout << "child.use_count" << child.use_count() << endl;

  parent->child = child;
  child->parent = parent;

  cout << "parent.use_count" << parent.use_count() << endl;
  cout << "child.use_count" << child.use_count() << endl;
}

/**
 * Problem:
 *     circular references cause memory leaks.
 * Solution:
 *     Use the boost::weak_ptr instead of boost::shared_ptr in the parent and child class.
 */
void testCircleRefWeak(){
  boost::shared_ptr<ParentWeak> parent(new ParentWeak());
  boost::shared_ptr<ChildWeak> child(new ChildWeak());

  cout << "parent.use_count" << parent.use_count() << endl;
  cout << "child.use_count" << child.use_count() << endl;

  parent->child = child;
  child->parent = parent;

  cout << "parent.use_count" << parent.use_count() << endl;
  cout << "child.use_count" << child.use_count() << endl;
}

int mainSharedPtr(int argc, char **argv)
{
//  testSharedPtr1();
//  testSharedPtr2();
//  testSharedPtr3();
//  testSharedPtr4();
//  testCircleRef();
  testCircleRefWeak();

  return 0;
}


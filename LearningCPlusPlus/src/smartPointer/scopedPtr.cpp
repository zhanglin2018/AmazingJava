/**
 * Copyright by Advantest, 2019
 *
 * @author  linzhang
 * @date    Jan 13, 2019
 */

#include <iostream>
#include "Simple.h"
#include <boost/smart_ptr.hpp>
using namespace std;

/**
 * summary: scoped_ptr
 * one: copy constructor / assign constructor / operator == / operator != is private function, and the
 *      out can not invoke these funcitons.
 *
 * two: boost::scoped_ptr smart pointer can not be presented as parameters of any functions.
 *
 *
 */

void testScopedPtr1(){
  boost::scoped_ptr<Simple> memory(new Simple(1));

  if (memory.get()){
    memory->printSomething();
    memory->info_extend = "Addition";

    memory->printSomething();
    (*memory).info_extend += " other";

    memory->printSomething();

    //scoped ptr has not release funtion.
  }

}

/**
 * summary: scoped_ptr
 * copy constructor / assign constructor / operator == / operator != is private function, and the
 * out can not invoke these funcitons.
 */
void testScopedPtr2(){
  boost::scoped_ptr<Simple> memory(new Simple(1));

    if (memory.get()){
      memory->printSomething();
      memory->info_extend = "Addition";

      memory->printSomething();
      (*memory).info_extend += " other";

      memory->printSomething();

//      boost::scoped_ptr<Simple> memory2;
//      memory2 = memory;
//      boost::scoped_ptr<Simple> memory2(memory); error
    }
}

/**
 * boost::scoped_ptr smart pointer can not be presented as parameters of any functions.
 * @param memory
 */
void testScoped(boost::scoped_ptr<Simple> memory){
  memory->printSomething();
}

/**
 * summary: scoped_ptr
 * copy constructor / assign constructor / operator == / operator != is private function, and the
 * out can not invoke these funcitons.
 */
void testScopedPtr3(){
  boost::scoped_ptr<Simple> memory(new Simple(1));

    if (memory.get()){
//      testScoped(memory);
    }
}

int mainScoped(int argc, char **argv) {
  testScopedPtr1();
  testScopedPtr2();
  testScopedPtr3();
}



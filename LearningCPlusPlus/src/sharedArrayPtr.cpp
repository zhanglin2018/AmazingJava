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
 * summary : boost::shared_array smart pointer can share pointer and transform the manager power.
 */


/*
 * You don't need to use reference or const reference.
 */
void sharedArrayPtr(boost::shared_array<Simple> memory){
  cout << "sharedArrayPtr(boost::shared_array<Simple> memory).use_count: " << memory.use_count() << endl;
}

void testSharedArrayPtr1(){
  boost::shared_array<Simple> memory(new Simple[2]);

  if (memory.get()){
    memory[0].printSomething();
    memory[0].info_extend = "Addition";
    memory[0].printSomething();
    memory[0].info_extend += " other";
    memory[0].printSomething();

    memory[1].printSomething();
    memory[1].info_extend = "Addition";
    memory[1].printSomething();
    memory[1].info_extend += " other";
    memory[1].printSomething();
  }
}

void testSharedArrayPtr2(){
  cout << "\ntestSharedArrayPtr2:" << endl;
  boost::shared_array<Simple> memory(new Simple[2]);

    if (memory.get()){
      memory[0].printSomething();
      memory[0].info_extend = "Addition";
      memory[0].printSomething();
      memory[0].info_extend += " other";
      memory[0].printSomething();

      memory[1].printSomething();
      memory[1].info_extend = "Addition";
      memory[1].printSomething();
      memory[1].info_extend += " other";
      memory[1].printSomething();
    }

    cout << "testSharedArrayPtr2.use_count : " << memory.use_count() << endl;

    sharedArrayPtr(memory);

    cout << "testSharedArrayPtr2.use_count : " << memory.use_count() << endl;

}

int mainSharedArray(int argc, char **argv) {
  testSharedArrayPtr1();
  testSharedArrayPtr2();
  return 0;
}



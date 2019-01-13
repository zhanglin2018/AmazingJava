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
 * summary: boost::scoped_array<T>
 * one: copy constructor / assign constructor / operator == / operator != is private function, and the
 *      out can not invoke these funcitons.
 *
 * two: boost::scoped_ptr smart pointer can not be presented as parameters of any functions.
 *
 *
 */

void testScopedArrayPtr1(){
  boost::scoped_array<Simple> memory(new Simple[2]);

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

//    memory[2].printSomething();
//    memory[2].info_extend = "Addition";
//    memory[2].printSomething();
//    memory[2].info_extend += " other";
//    memory[2].printSomething();
  }

//  boost::scoped_array<Simple> memory2 = memory;
//  boost::scoped_array<Simple> memory2(memory);
}

int mainScopedArray(int argc, char **argv) {
  testScopedArrayPtr1();
  int *array = new int[10];
  for (int i=0; i<100; i++){
    cout << array[i] << endl;
  }
//  array[1] = 1;
//  array[100] = 1;
}



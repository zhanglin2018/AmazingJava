/**
 * Copyright by Advantest, 2019
 *
 * @author  linzhang
 * @date    Jan 13, 2019
 */

#include <iostream>
#include <memory>
#include "Simple.h"
using namespace std;

/**
 * summary : the auto_ptr smart pointer has been deprecated.
 */

// run OK.
void testAutoPtr1(){
  std::auto_ptr<Simple> memory(new Simple(1));

  if (memory.get()){
    memory->printSomething();

    memory.get()->info_extend = "Additon";

    memory->printSomething();

    memory->info_extend += " other";

    memory->printSomething();
  }

}

// A memory leak occur.
void testAutoPtr2(){
  std::auto_ptr<Simple> memory(new Simple(1));

  if (memory.get()){
    std::auto_ptr<Simple> memory2;

    memory2 = memory;

    memory2->printSomething();

    memory->printSomething();
  }
}

// A memory leak occur.
void testAutoPtr3(){
  std::auto_ptr<Simple> memory(new Simple(1));

  if (memory.get()){
    memory.release();
  }
}

//int main(int argc, char **argv) {
//  testAutoPtr1();
//  testAutoPtr2();
//  testAutoPtr3();
//}

int mainAutoPtr(int argc, char **argv) {
  testAutoPtr1();
//  testAutoPtr2();
  testAutoPtr3();
}


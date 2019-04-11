//============================================================================
// Name        : LearningUnix.cpp
// Author      : Laughing zhang
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <thread>
using namespace std;

class TestStatic{
public:
  static void fun(){
    cout << "fun()" << endl;
  }

};


void func(int a){
  cout << "This function is callable: " << a << endl;
}

class Object{
  void operator()(int a ){
    cout << "This object is callable: " << a << endl;
  }
};

void subThread(){
  cout << "This is a test!" << endl;
}

#include <iostream>
#include <thread>
#include <chrono>

void foo()
{
    // simulate expensive operation
    std::cout << "foo()" << endl;
    std::this_thread::sleep_for(std::chrono::seconds(5));
}

void bar()
{
    // simulate expensive operation
    std::cout << "bar()" << endl;
    std::this_thread::sleep_for(std::chrono::seconds(5));
}

int testJoin()
{
    std::cout << "starting first helper...\n";
    std::thread helper1(foo);

    std::cout << "starting second helper...\n";
    std::thread helper2(bar);

    std::cout << "waiting for helpers to finish..." << std::endl;
    helper1.join();
    helper2.join();

    std::cout << "done!\n";
}

void testJoin1()
{
  TestStatic::fun();
  std::cout << "cpu is : " << std::thread::hardware_concurrency()
      << " thread . " << std::endl;
  //  std::thread thread1(func, 1);
  //  cout << "thread1 thread_id: " << thread1.get_id() << " joinable " << thread1.joinable() << endl;
  //
  //  std::thread thread2;
  //  cout << "thread2 thread_id: " << thread2.get_id() << " joinable " << thread2.joinable() << endl;
  thread t(subThread);
  t.join();
  cout << "main thread : " << endl;
}

int main(int argc, char** argv)
{
//  testJoin1();
  testJoin();
  return 0;
}

//============================================================================
// Name        : LearningCPlusPlus.cpp
// Author      : Laughing zhang
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <mutex>
#include <boost/smart_ptr.hpp>
#include "Person.h"
#include "BaseAndDerived.hpp"

using namespace std;
using namespace boost;

int count()
{
  static int a = 0;
  a++;
  return a;
}

void swap(int a, int b)
{
  int temp = a;
  a = b;
  b = temp;
}

void swapByRef(int &a, int &b)
{
  int temp = a;
  a = b;
  b = temp;
}

void testStatic()
{
  cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
  cout << count() << endl;
  cout << count() << endl;
  cout << count() << endl;
}

void testSwapByVariable()
{
  // swap by variable
  int c = 3;
  int d = 4;
  cout << " c = " << c << ", d = " << d << endl;
  swap(c, d);
  cout << " c = " << c << ", d = " << d << endl;
}

void testSwapByReference()
{
  // swap by reference
  int c = 30;
  int d = 40;
  cout << " c = " << c << ", d = " << d << endl;
  swapByRef(c, d);
  cout << " c = " << c << ", d = " << d << endl;
}

void testClass()
{
  // stack variable : automatically release memory.
  Person person("zhanglin", "man");
  cout << person.getName() << " " << person.getSex() << endl;

  // A memory leak occur because the contents were not released.

  Person* person1 = new Person("jiafu", "man");
  cout << person1->getName() << " " << person1->getSex() << endl;

  boost::shared_ptr<Person> shared_Person(new Person("lixiao", "woman"));
  cout << shared_Person->getName() << " " << shared_Person->getSex() << endl;
}



void testSharedPtr()
{
  cout << "start testSharedPtr() -->" << endl;

  boost::shared_ptr<Person> person1(new Person("zhanglin", "man"));
  cout << person1->getName() << " " << person1->getSex() << " "
      << person1.use_count() << endl;


  boost::shared_ptr<Person> person2(person1);
  cout << person1->getName() << " " << person1->getSex() << " "
      << person1.use_count() << endl;
  cout << person2->getName() << " " << person2->getSex() << " "
      << person2.use_count() << endl;


  Person* person3 = person1.get();
  cout << person3->getName() << " " << person3->getSex() << endl;


  boost::shared_ptr<Person> person4 = boost::make_shared<Person>("jiafu", "man");
  cout << person4->getName() << " " << person4->getSex() << " "
      << person4.use_count() << endl;

  boost::shared_ptr<Person> person5(person4);
  cout << person5->getName() << " " << person5->getSex() << " "
      << person5.use_count() << endl;
}

//void thr(boost::shared_ptr<Base> p)
//{
//  std::this_thread::sleep_for(std::chrono::seconds(1));
//  std::shared_ptr<Base> lp = p;  // thread-safe, even though the shared use_count is incremented
//  {
//    static std::mutex io_mutex;
//    std::lock_guard<std::mutex> lk(io_mutex);
//    std::cout << "local pointer in a thread:\n" << "  lp.get() = " << lp.get()
//        << ", lp.use_count() = " << lp.use_count() << '\n';
//  }
//}
//
//int test_shared_ptr1()
//{
//        boost::shared_ptr<Base> p = boost::make_shared<Derived>();
//
//        std::cout << "Created a shared Derived (as a pointer to Base)\n"
//                << "  p.get() = " << p.get()
//                << ", p.use_count() = " << p.use_count() << '\n';
////        std::thread t1(thr, p), t2(thr, p), t3(thr, p);
//
////        p.reset(); // release ownership from main
////        std::cout << "Shared ownership between 3 threads and released\n"
////                << "ownership from main:\n"
////                << "  p.get() = " << p.get()
////                << ", p.use_count() = " << p.use_count() << '\n';
////        t1.join(); t2.join(); t3.join();
//        std::cout << "All threads completed, the last one deleted Derived\n";
//
//        return 0;
//}
//
//
/////////////////////////////////////////////////
//// reference: http://www.cplusplus.com/reference/memory/shared_ptr/shared_ptr/
//int test_shared_ptr2()
//{
//        struct C { int* data; };
//
//        // shared_ptr constructor example
//        boostshared_ptr<int> p1;
//        boostshared_ptr<int> p2(nullptr);
//        boostshared_ptr<int> p3(new int);
//        std::shared_ptr<int> p4(new int, std::default_delete<int>());
//        std::shared_ptr<int> p5(new int, [](int* p){delete p; }, std::allocator<int>());
//        std::shared_ptr<int> p6(p5);
//        std::shared_ptr<int> p7(std::move(p6));
//        std::shared_ptr<int> p8(std::unique_ptr<int>(new int));
//        std::shared_ptr<C> obj(new C);
//        std::shared_ptr<int> p9(obj, obj->data);
//
//        std::cout << "use_count:\n";
//        std::cout << "p1: " << p1.use_count() << '\n'; // 0
//        std::cout << "p2: " << p2.use_count() << '\n'; // 0
//        std::cout << "p3: " << p3.use_count() << '\n'; // 1
//        std::cout << "p4: " << p4.use_count() << '\n'; // 1
//        std::cout << "p5: " << p5.use_count() << '\n'; // 2
//        std::cout << "p6: " << p6.use_count() << '\n'; // 0
//        std::cout << "p7: " << p7.use_count() << '\n'; // 2
//        std::cout << "p8: " << p8.use_count() << '\n'; // 1
//        std::cout << "p9: " << p9.use_count() << '\n'; // 2
//
//        return 0;
//}
//
////////////////////////////////////////////////////////////
//// reference: https://oopscenities.net/2013/10/06/smart-pointers-part-4-shared_ptr/
//class Integer
//{
//        int n;
//public:
//        Integer(int n) : n(n) { }
//        ~Integer() { printf("Deleting %d\n", n); }
//        int get() const { return n; }
//};
//
//int test_shared_ptr3()
//{
//        auto a = std::make_shared<Integer>(10);
//        auto b = std::make_shared<Integer>(20);
//        auto c = a;
//        auto d = std::make_shared<Integer>(30);
//        auto e = b;
//        a = d;
//        b = std::make_shared<Integer>(40);
//        auto f = c;
//        b = f;
//
//        printf("%d\n", a->get());
//        printf("%d\n", b->get());
//        printf("%d\n", c->get());
//        printf("%d\n", d->get());
//        printf("%d\n", e->get());
//        printf("%d\n", f->get());
//
//        return 0;
//}
//
////////////////////////////////////////////////
//// reference: http://www.linux-magazin.de/Ausgaben/2013/04/C-11
//struct MyInt{
//        MyInt(int v) :val(v){
//                std::cout << "  Hello: " << val << std::endl;
//        }
//        ~MyInt(){
//                std::cout << "  Good Bye: " << val << std::endl;
//        }
//        int val;
//};
//
//int test_shared_ptr4()
//{
//        std::shared_ptr<MyInt> sharPtr(new MyInt(1998));
//        std::cout << "    My value: " << sharPtr->val << std::endl;
//        std::cout << "sharedPtr.use_count(): " << sharPtr.use_count() << std::endl;
//
//        {
//                std::shared_ptr<MyInt> locSharPtr(sharPtr);
//                std::cout << "locSharPtr.use_count(): " << locSharPtr.use_count() << std::endl;
//        }
//        std::cout << "sharPtr.use_count(): " << sharPtr.use_count() << std::endl;
//
//        std::shared_ptr<MyInt> globSharPtr = sharPtr;
//        std::cout << "sharPtr.use_count(): " << sharPtr.use_count() << std::endl;
//        globSharPtr.reset();
//        std::cout << "sharPtr.use_count(): " << sharPtr.use_count() << std::endl;
//
//        sharPtr = std::shared_ptr<MyInt>(new MyInt(2011));
//
//        return 0;
//}
//
//////////////////////////////////////////////////////////
//// reference: http://www.linux-magazin.de/Ausgaben/2013/04/C-11
//template <typename T>
//struct Deleter{
//        void operator()(T *ptr){
//                ++Deleter::count;
//                delete ptr;
//        }
//        static int count;
//};
//
//template <typename T>
//int Deleter<T>::count = 0;
//
//typedef Deleter<int> IntDeleter;
//typedef Deleter<double> DoubleDeleter;
//typedef Deleter<MyInt> MyIntDeleter;
//
//int test_shared_ptr5()
//{
//        {
//                std::shared_ptr<int> sharedPtr1(new int(1998), IntDeleter());
//                std::shared_ptr<int> sharedPtr2(new int(2011), IntDeleter());
//                std::shared_ptr<double> sharedPtr3(new double(3.17), DoubleDeleter());
//                std::shared_ptr<MyInt> sharedPtr4(new MyInt(2017), MyIntDeleter());
//        }
//
//        std::cout << "Deleted " << IntDeleter().count << " int values." << std::endl;
//        std::cout << "Deleted " << DoubleDeleter().count << " double value." << std::endl;
//        std::cout << "Deleted " << MyIntDeleter().count << " MyInt value." << std::endl;
//
//        return 0;
//}


int main1()
{
  testStatic();
  // swap by variable
  testSwapByVariable();
  // swap by reference
  testSwapByReference();
//  testClass();
  testSharedPtr();

//  test_shared_ptr1();
//  test_shared_ptr2();
//  test_shared_ptr3();
//  test_shared_ptr4();
//  test_shared_ptr5();

  return 0;
}


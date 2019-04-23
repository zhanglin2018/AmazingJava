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
    {
        Person person("zhanglin", "man");
        cout << person.getName() << " " << person.getSex() << endl;
    }
    // A memory leak occur because the contents were not released.

    {
        Person* person1 = new Person("jiafu", "man");
        cout << person1->getName() << " " << person1->getSex() << endl;
    }

    {
        boost::shared_ptr<Person> shared_Person(new Person("lixiao", "woman"));
        cout << shared_Person->getName() << " " << shared_Person->getSex()
                << endl;
    }
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

    boost::shared_ptr<Person> person4(new Person("zhanglin", "man"));

    cout << person4->getName() << " " << person4->getSex() << " "
            << person4.use_count() << endl;

    boost::shared_ptr<Person> person5(person4);

    cout << person5->getName() << " " << person5->getSex() << " "
            << person5.use_count() << endl;
}

void testSharedPtr11()
{
    cout << "start testSharedPtr() -->" << endl;
    {
        boost::shared_ptr<Person> person1(new Person("zhanglin", "man"));

        cout << person1->getName() << " " << person1->getSex() << " "
                << person1.use_count() << endl;

        boost::shared_ptr<Person> person2(person1);

        cout << person1->getName() << " " << person1->getSex() << " "
                << person1.use_count() << endl;
        cout << person2->getName() << " " << person2->getSex() << " "
                << person2.use_count() << endl;

    }

    {
        boost::shared_ptr<Person> person4(new Person("zhanglin", "man"));

        cout << person4->getName() << " " << person4->getSex() << " "
                << person4.use_count() << endl;

        boost::shared_ptr<Person> person5;

        person5 = person4;

        cout << person5->getName() << " " << person5->getSex() << " "
                << person5.use_count() << endl;
    }
}

int main1221()
{
    testStatic();
    // swap by variable
    testSwapByVariable();
    // swap by reference
    testSwapByReference();
    testClass();
    testSharedPtr();
    testSharedPtr11();

    return 0;
}


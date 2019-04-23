/**
 * Copyright by Advantest, 2019
 *
 * @author  linzhang
 * @date    Jan 11, 2019
 */

#include<string>
#include <iostream>
#include "Person.h"
using namespace std;

namespace myDetail {

    class sp_counted_base {
    public:
        sp_counted_base() :
                use_count(1), weak_count(1)
        {
            ptrInt = new int(1000);
        }

        virtual ~sp_counted_base()
        {
            delete ptrInt;
            cout << "~sp_counted_base()" << endl;
        }

        void release() // nothrow
        {

            dispose();
            destroy();

        }

        void destroy()
        {
            cout << &use_count << endl;
            cout << &weak_count << endl;
            cout << this << endl;
            delete this;
        }

        virtual void dispose() = 0;

        void print()
        {
            cout << "use_count: " << use_count << endl;
            cout << "weak_count: " << weak_count << endl;
        }

    private:
        int use_count;
        int weak_count;
        int *ptrInt;
    };

    class sp_counted_imp : public sp_counted_base {
    public:
        sp_counted_imp() :
                sp_counted_base()
        {
            pInt = new int(10);
            pPerson = new Person("hello", "world");
        }

        virtual ~sp_counted_imp()
        {
            delete pInt;
            delete pPerson;
        }

        void dispose()
        {
            cout << "sp_counted_imp: dispose" << endl;
        }

        void printImp()
        {
            cout << *pInt << endl;
            cout << pPerson->getName() << " " << pPerson->getSex() << endl;
        }

        int * pInt;
        Person * pPerson;

    };

    class shared_count {
    public:
        shared_count()
        {
            pBase = new sp_counted_imp();
        }

        ~shared_count()
        {
            pBase->release();
        }

    public:
        sp_counted_base * pBase;
    };

    class TestInt {
    public:
        TestInt() :
                age(1), work(1)
        {

        }

        ~TestInt()
        {

        }

    public:
        int age;
        int work;
    };

}

using namespace myDetail;


sp_counted_base* pBase1 = NULL;

void testPBase()
{
    {
        sp_counted_base* pBase = new sp_counted_imp();
        pBase1 = pBase;
        delete pBase;
    }
    pBase1->print();
    ((sp_counted_imp*) (pBase1))->printImp();
}

int mainTest(int argc, char* argv[])
{
    sp_counted_base * pBase = NULL;
    {
        myDetail::shared_count share;
        pBase = share.pBase;
    }

    pBase->print();




    TestInt* pInt = NULL;
    {
        TestInt* pInt1 = new TestInt();
        pInt = pInt1;
        delete pInt1;
    }

    cout << pInt->age << endl;
    cout << pInt->work << endl;

    testPBase();
    ((sp_counted_imp*) (pBase1))->printImp();


    sp_counted_base* pBase2 = pBase1;

    return 0;
}


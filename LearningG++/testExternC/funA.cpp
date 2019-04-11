#include "funA.h"
#include <stdio.h>
#include <iostream>
using namespace std;


void funC()
{
        cout << "funC()" << endl;
}

void funA()
{
    //printf("%s", "funA()");
    	cout << "funA()" << endl;
}

void funB()
{
    //printf("%s", "funB()");
	cout << "funB()" << endl;
}

extern "C" void funD()
{
	cout << "funD()" << endl;
}

//============================================================================
// Name        : LearningUnix.cpp
// Author      : Laughing zhang
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdlib.h>
using namespace std;

static void myExit1(void){
  cout << "first exit handler" << endl;
}

static void myExit2(void){
  cout << "second exit handler" << endl;
}

void testExit()
{
  cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
  if (atexit(myExit1) != 0) {
    cout << "can't register myExit1" << endl;
  }
  if (atexit(myExit1) != 0) {
    cout << "can't register myExit1" << endl;
  }
  if (atexit(myExit2) != 0) {
    cout << "can't register myExit2" << endl;
  }
  cout << "main is done" << endl;
}

void testParameters(int argc, char** argv)
{
  for (int i = 0; i < argc; i++) {
    cout << "argv[" << i << "] : " << argv[i] << " " << endl;
  }
}

int main(int argc, char **argv)
{
  testExit();

  testParameters(argc, argv);

  return 0;
}

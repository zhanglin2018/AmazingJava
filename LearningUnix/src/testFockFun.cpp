////============================================================================
//// Name        : LearningUnix.cpp
//// Author      : Laughing zhang
//// Version     :
//// Copyright   : Your copyright notice
//// Description : Hello World in C++, Ansi-style
////============================================================================
//
//#include <iostream>
//#include <stdlib.h>
//#include <pthread.h>
//using namespace std;
//
///**
// * learn fork function
// */
//
//int global = 10;
//char buf[100] = "hello world";
//
//void testFork()
//{
//  int var = 100;
//  pid_t pid;
//  cout << "before fork" << endl;
//  pid = fork();
//  if (pid < 0) {
//    cout << "fork error" << endl;
//  } else if (pid == 0) {
//    cout << "child process. " << endl;
//    global++;
//    var++;
//  } else {
//    cout << "father process. " << endl;
//    sleep(2);
//  }
//
//  cout << "pid = " << getpid() << " " << global << " : " << var << endl;
//}
//
//pthread_t ntid;
//
//void printId(const char *s){
//  pid_t pid;
//  pthread_t tid;
//
//  pid = getpid();
//  tid = pthread_self();
//
//  cout << s <<  "print the pid and tid : " << pid << " : " << tid << endl;
//}
//
//void *thr_fn(void *arg){
//  printId("new thread: ");
//  return (void *)0;
//}
//
//int mainFock(int argc, char** argv)
//{
////  testFork();
//
//  int err = pthread_create(&ntid, NULL, thr_fn, NULL);
//
//  if (err != 0){
//    cout << "can't create a new thread" << endl;
//  }
//
//  printId("main thread: ");
//  sleep(1);
//
//  return 0;
//}

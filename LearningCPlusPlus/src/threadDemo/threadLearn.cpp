///**
// * Copyright by Advantest, 2019
// *
// * @author  linzhang
// * @date    Jan 15, 2019
// */
//
//
//#include <iostream>
//#include <thread>
//using namespace std;
//
//class Father{};
//
//class Son : public Father{
//private:
//  char * pData;
//public :
//  Son(){
//    pData = new char[32];
//
//  }
//
//  ~Son(){
//    delete pData;
//  }
//};
//
//class Student
//{
//private:
//        char *name;
//public:
//        Student(const Student &s){
//
//        }
//};
//
//
//class Person{
//public:
//  void doSomething(int a);
//  void doSomething(float a);
//  virtual void print(int a) = 0;
//};
//
//class Man : public Person{
//  void print(int a){
//  }
//};
//
////
//
//
//
//int main(int argc, char** argv)
//{
//  Father * p = new Son();
//  delete p;
//  return 0;
//}

#include <iostream>
#include <vector>
using namespace std;

void bestSolution(int *array, int len)
{
  if (len <= 0) {
    return;
  }
  cout << "Best buy sell solution is:" << endl;

  int minPriceIndex = 0;
  int maxPriceIndex = 0;
  for (int i = 1; i < len; i++) {
    if (array[i] > array[i - 1]) {
      maxPriceIndex = i;
    }
    if (array[i] < array[i - 1]) {
      if (maxPriceIndex > minPriceIndex) {
        cout << "Buy on day: " << minPriceIndex << "  " << "Sell on Day: "
            << maxPriceIndex << endl;
      }
      minPriceIndex = i;
      maxPriceIndex = i;
    }
  }

  if (maxPriceIndex > minPriceIndex) {
    cout << "Buy on day: " << minPriceIndex << "  " << "Sell on Day: "
        << maxPriceIndex << endl;
  }
}

int mainTest()
{
  int array[8] = { 1290, 1293, 1307, 1297, 1283, 1302, 1322, 1340 };
  bestSolution(array, 8);

  int array1[8] = { 1,2,3,4,5,6,7,8 };
  bestSolution(array1, 8);

  int array2[8] = { 8,7,6,4,3,2,1,0 };
  bestSolution(array2, 8);
}


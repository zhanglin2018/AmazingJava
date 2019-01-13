/**
 * Copyright by Advantest, 2019
 *
 * @author  linzhang
 * @date    Jan 13, 2019
 */
#pragma once



#include <iostream>
using namespace std;


class Simple{
public:
  Simple(int para = 0){
    number = para;
    cout << "Simple: " << number << endl;
  }

  ~Simple(){
    cout << "~Simple: " << number << endl;
  }

  void printSomething(){
    cout << "printSomething: " << info_extend.c_str() << endl;
  }

  std::string info_extend;
  int number;
};

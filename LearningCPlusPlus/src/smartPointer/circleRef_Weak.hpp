/**
 * Copyright by Advantest, 2019
 *
 * @author  linzhang
 * @date    Jan 13, 2019
 */
#pragma once
#include <iostream>
#include <boost/smart_ptr.hpp>
using namespace std;

class ParentWeak;
class ChildWeak;

class ParentWeak{
public:
  ParentWeak(){
    cout << "constructor : ParentWeak" << endl;
  }
  ~ParentWeak(){
    cout << "delete constructor : ParentWeak" << endl;
  }

  boost::weak_ptr<ChildWeak> child;
};

class ChildWeak{
public:
  ChildWeak(){
    cout << "constructor : ChildWeak" << endl;
  }
  ~ChildWeak(){
    cout << "delete constructor : ChildWeak" << endl;
  }

  boost::weak_ptr<ParentWeak> parent;
};






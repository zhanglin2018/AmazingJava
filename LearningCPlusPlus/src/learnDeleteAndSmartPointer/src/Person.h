/**
 * Copyright by Advantest, 2019
 *
 * @author  linzhang
 * @date    Jan 11, 2019
 */
#pragma once
#include<string>
using namespace std;


class Person {
public:
  Person(string name, string sex);
  ~Person();

  const string& getName() const
  {
    return name;
  }

  void setName(const string& name)
  {
    this->name = name;
  }

  const string& getSex() const
  {
    return sex;
  }

  void setSex(const string& sex)
  {
    this->sex = sex;
  }

private:
  string name;
  string sex;
};


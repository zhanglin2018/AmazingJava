/**
 * Copyright by Advantest, 2019
 *
 * @author  linzhang
 * @date    Jan 15, 2019
 */

#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

void vectorInitialization()
{
  std::vector<int> vec;
  assert(vec.size() == 0);

  cout << "vector size = " << vec.size() << endl;
  for (int i = 0; i < 5; i++) {
    vec.push_back(i);
  }

  cout << "extended vector size = " << vec.size() << endl;
  for (int i = 0; i < 5; i++) {
    cout << "value of vec [" << i << "] = " << vec[i] << endl;
  }

  std::vector<int>::iterator v = vec.begin();
  while (v != vec.end()) {
    cout << "value of v = " << *v << endl;
    v++;
  }

  for (int i : vec) {
    cout << "value of v = " << i << endl;
  }
}

void vectorSize()
{
  std::vector<int> vec;
  for (int i : vec) {
    cout << "value of v = " << i << endl;
  }
  std::cout << "vec.size() == " << vec.size() << " vec.capacity() = "
      << vec.capacity() << std::endl;
  vec.reserve(10);
  std::cout << "v.size() == " << vec.size() << " vec.capacity() = "
      << vec.capacity() << std::endl;
  vec.resize(10);
  std::cout << "v.size() == " << vec.size() << " vec.capacity() = "
      << vec.capacity() << std::endl;
  vec.push_back(0);
  std::cout << "v.size() == " << vec.size() << " vec.capacity() = "
      << vec.capacity() << std::endl;
}

void vectorInitialization1()
{

  vector<int> vec1;
  vector<int> vec2(vec1);
  vector<int> vec3(vec1.begin(), vec1.end());
  vector<int> vec4(10);
  vector<int> vec5(10, 4);
  vec1.push_back(100);
  cout << vec1[0] << endl;
  vec1.insert(vec1.end(), 5, 3);
  vec1.pop_back();
  vec1.erase(vec1.begin(), vec1.begin() + 2);
  vector<int>::iterator iter = vec1.begin();
  vector<int>::const_iterator c_iter = vec1.begin();
  vec1.clear();
  int length = vec1.size();
  for (int i = 0; i < length; i++) {
    cout << vec1[i];
  }
  cout << endl << endl;
  vector<int>::iterator iter1 = vec1.begin();
  for (; iter1 != vec1.end(); iter1++) {
    cout << *iter;
  }
}

void stringVectorToString(vector<string> & val)
{
//add assignment event
  string valStr = "";
  vector<string>::const_iterator iter = val.begin();
  for (; iter < val.end(); ++iter)
  {
    valStr += *iter;
    valStr += ",";
  }
  int lastSign = valStr.find_last_of(',');
  string subStr = valStr.substr(0, lastSign);
}



int mainVector()
{
  vectorInitialization();
  vectorSize();
  vectorInitialization1();
  return 0;
}


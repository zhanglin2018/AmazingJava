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

int main()
{
  vectorInitialization();
  vectorSize();
  return 0;
}


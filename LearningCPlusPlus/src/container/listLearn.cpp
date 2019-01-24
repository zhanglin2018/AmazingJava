/**
 * Copyright by Advantest, 2019
 *
 * @author  linzhang
 * @date    Jan 15, 2019
 */

#include <iostream>
#include <list>
#include <assert.h>
using namespace std;

void listInitialization()
{
  list<int> lst1;
  list<int> lst2(3);
  list<int> lst3(3, 2);
  list<int> lst4(lst2);
  list<int> lst5(lst2.begin(), lst2.end());


  lst1.assign(lst2.begin(), lst2.end());
  lst1.push_back(10);
  lst1.pop_back();
  lst1.begin();
  lst1.end();
  lst1.clear();
  lst1.erase(lst1.begin(), lst1.end());
  lst1.front();
  lst1.back();
  lst1.insert(lst1.begin(), 3, 2);
  lst1.rbegin();
  lst1.remove(2);
  lst1.reverse();
  lst1.size();
  lst1.sort();
  lst1.unique();

  for (list<int>::const_iterator iter = lst1.begin(); iter != lst1.end();
      iter++) {
    cout << *iter;
  }

  for (int i=0; i<10; i++ ){
    lst1.push_back(i);
  }

  for (list<int>::const_iterator iter = lst1.begin(); iter != lst1.end();
      iter++) {
    cout << *iter << endl;
  }

  for (list<int>::const_iterator iter = lst1.begin(); iter != lst1.end();
      iter++) {
    cout << *iter << endl;
  }

}

int mainList()
{
  listInitialization();
  return 0;
}


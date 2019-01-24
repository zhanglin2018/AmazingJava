/**
 * Copyright by Advantest, 2019
 *
 * @author  linzhang
 * @date    Jan 15, 2019
 */

#include <iostream>
#include <map>
#include <assert.h>
using namespace std;

void mapInitialization()
{
  map<int, string> map1;

  map1[3] = "Saniya";
  map1.insert(map<int, string>::value_type(2, "Diyabi"));
  map1.insert(make_pair<int, string>(4, "V5"));

  string str = map1[3];

  map<int, string>::iterator iter_map = map1.begin();
  int key = iter_map->first;
  string value = iter_map->second;
  cout << key << ": " << value << endl;

  for (map<int, string>::iterator iter = map1.begin(); iter != map1.end();
      iter++) {
    int keyk = iter->first;
    string valuev = iter->second;
    cout << keyk << ": " << valuev << endl;
  }

  map1.erase(iter_map);
  map1.erase(3);
  map1.size();
  map1.empty();
  map1.clear();

}

int mainMap()
{
  mapInitialization();
  return 0;
}


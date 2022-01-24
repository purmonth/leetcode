#include <iostream>
#include <list>
#include <vector>
using namespace std;

class MyHashMap {
  int size = 173;
  int hash(int key) { return key % size; }
  vector<list<pair<int, int>>> myhashmap;
  list<pair<int, int>>::iterator myFind(int index, int key) {
    return find_if(myhashmap[index].begin(), myhashmap[index].end(),
                   [key](pair<int, int> tmp) { return tmp.first == key; });
  }

 public:
  MyHashMap() : myhashmap(size, list<pair<int,int>>()) {}
  void put(int key, int value) {
    int index = hash(key);
    list<pair<int, int>>::iterator iter = myFind(index, key);
    if (iter == myhashmap[index].end()) {
      myhashmap[index].push_front({key,value});
    } else {
      iter->second = value;
    }
  }
  int get(int key) {
    int index = hash(key);
    list<pair<int, int>>::iterator iter = myFind(index, key);
    if (iter == myhashmap[index].end()) {
      return -1;
    } else {
      return iter->second;
    }
  }
  void remove(int key) {
    int index = hash(key);
    list<pair<int, int>>::iterator iter = myFind(index, key);
    if (iter == myhashmap[index].end()) {
      return;
    } else {
      myhashmap[index].erase(iter);
    }
  }
};

int main() {
  MyHashMap* obj = new MyHashMap();
  obj->put(1, 1);
  obj->put(2, 2);
  obj->get(1);
  obj->get(3);
  obj->put(2, 1);
  obj->get(2);
  obj->remove(2);
  obj->get(2);
  return 0;
}
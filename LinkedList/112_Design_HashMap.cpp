/*
Design_HashMap.cpp

Design a HashMap without using any built-in hash table libraries.

Implement the MyHashMap class:

- MyHashMap() initializes the object with an empty map.
- void put(int key, int value) inserts a (key, value) pair into the HashMap. 
  If the key already exists in the map, update the corresponding value.
- int get(int key) returns the value to which the specified key is mapped, 
  or -1 if this map contains no mapping for the key.
- void remove(key) removes the key and its corresponding value 
  if the map contains the mapping for the key.

https://leetcode.com/problems/design-hashmap/
  - Method 1: Using vector of max size(<1e7). If more required use hashing.
  - Method 2: Using hash function and vector pair of doubly linked list 
  reference: https://www.youtube.com/watch?v=xVEGczCJCHs

*/


// Method 1: Using vector of max size(<1e7). If more required use hashing.
class MyHashMap1 {
public:
	vector<int> v;
	int siz;

    MyHashMap() {
    	siz = 1e6+1;
    	v.resize(siz);
    	fill(v.begin(), v.end(), -1);    
    }
    
    void put(int key, int value) {
        v[key] = value;
    }
    
    int get(int key) {
        return v[key];
    }
    
    void remove(int key) {
        v[key] = -1;
    }
};



// Method 2: 
class MyHashMap {
public:
  vector<list<pair<int, int>>> v;
  int siz;

    MyHashMap() {
      siz = 100;
      v.resize(siz);
    }

    int hash(int key) {
      return key%siz;
    }

    list<pair<int, int>> :: iterator search(int key) {
      int i = hash(key);
      // loop the linked it and check if key exist
        list<pair<int, int>> :: iterator it = v[i].begin();
      while(it != v[i].end()) {
        if(it->first == key) return it;
        it++;
      }
      return it;
    }
    
    void put(int key, int value) {
      int i = hash(key);
      remove(key);    // remove if already exist
      v[i].push_back({key, value});
    }
    
    int get(int key) {
      int i = hash(key);
      list<pair<int,int>> :: iterator it = search(key);
      if(it == v[i].end()) return -1;
      return it->second;
    }
    
    void remove(int key) {
    int i = hash(key);
      list<pair<int,int>> :: iterator it = search(key);
      if(it != v[i].end()) v[i].erase(it);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
/*
Design_HashSet.cpp

Design a HashSet without using any built-in hash table libraries.

Implement MyHashSet class:
- void add(key) Inserts the value key into the HashSet.
- bool contains(key) Returns whether the value key exists in the HashSet or not.
- void remove(key) Removes the value key in the HashSet. If key does not exist in the HashSet, do nothing.

https://leetcode.com/problems/design-hashset/
	- Method 1: Using array of size = given constraint.
	- Method 2: Using hash function and vector of doubly linked list

*/

// Method 1: Using array of size = given constraint.
class MyHashSet1 {
public:
    vector<int> m;
    int siz;
    
    MyHashSet1() {
        siz = 1e6+1;
        m.resize(siz);
    }
    
    void add(int key) {
        m[key] = 1;
    }
    
    void remove(int key) {
        m[key] = 0;
    }
    
    bool contains(int key) {
        return m[key];
    }
};


// Method 2: Using hash function and vector of doubly linked list
class MyHashSet {
    vector<list<int>> m;
    int siz;
    
    public:
    MyHashSet() {
        siz = 100;
        m.resize(siz);
    }
    
    int hash(int key) {
        return key % siz;
    }
    
    list<int> :: iterator search(int key) {
        int i = hash(key);
        return find(m[i].begin(), m[i].end(), key);
    }
    
    void add(int key) {
        if(contains(key)) return;
        int i = hash(key);
        m[i].push_back(key);
    }
    
    void remove(int key) {
        if(!contains(key)) return;
        int i = hash(key);
        m[i].erase(search(key));
    }
    
    bool contains(int key) {
        int i = hash(key);
        return (search(key) != m[i].end());
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */








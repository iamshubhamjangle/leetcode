/*
Design_HashMap.cpp

https://leetcode.com/problems/design-hashmap/description/
*/

#include <bits/stdc++.h>
using namespace std;

// class MyHashMap {
// public:
//     vector<int> v;
//     int size;

//     // initializes the object with an empty map.
//     MyHashMap() {
//         size = 1e6+1;
//         v.resize(size);
//         fill(v.begin(), v.end(), -1);
//     }
    
//     // inserts a (key, value) pair into the HashMap. If the key already exists in the map, update the corresponding value.
//     void put(int key, int value) {
//         v[key] = value;
//     }
    
//     // returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.
//     int get(int key) {
//         return v[key];
//     }
    

//     void remove(int key) {
//         v[key] = -1;
//     }
// };


class Node {
public:
    int key;
    int value;
    Node* next;

    Node(int key, int value, Node* next) {
        this->key = key;
        this->value = value;
        this->next = next;
    }
};

class MyHashMap {
public:
    const static int size = 10000;
    vector<Node*> v = {};

    MyHashMap() {
        v.resize(size);
    }

    int hash(int key) {
        return (int)(key % size);
    }

    void put(int key, int value) {
        remove(key);
        int h = hash(key);
        Node* node = new Node(key, value, v[h]);    // v[h] is the prev value can be null initially
        v[h] = node;
    }

    int get(int key) {
        int h = hash(key);
        Node* node = v[h];

        if(!node) return -1;
        if(node->key == key) return node->value;

        while(node) {
            if(node->key == key) return node->value;
            node = node->next;
        }

        return -1;
    }

    void remove(int key) {
        int h = hash(key);
        Node* node = v[h];

        if(!node) return;
        if(node->key == key) { v[h] = node->next; return; }

        while(node->next != NULL) {
            if(node->next->key == key) {
                Node* temp = node->next;
                node->next = temp->next;
                delete temp;
                return;
            }
            node = node->next;
        }

        return;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
int main(){
    cout << "Hello World!" << endl;

    MyHashMap* hm = new MyHashMap();
    hm->put(1, 2);
    hm->put(2, 4);
    hm->put(3, 6);
    cout << hm->get(1) << endl;
    cout << hm->get(2) << endl;
    cout << hm->get(3) << endl;
    cout << hm->get(4) << endl;
    cout << hm->get(5) << endl;

    cout << "-----------" << endl;

    MyHashMap hm2;
    hm2.put(1,2);
    hm2.put(2, 4);
    hm2.put(3, 6);
    cout << hm2.get(1) << endl;
    cout << hm2.get(2) << endl;
    cout << hm2.get(3) << endl;
    cout << hm2.get(4) << endl;
    cout << hm2.get(5) << endl;
}
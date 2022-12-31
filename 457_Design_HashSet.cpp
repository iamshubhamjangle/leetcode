/*
Design_HashSet.cpp

https://leetcode.com/problems/design-hashset/
*/
#include <bits/stdc++.h>
using namespace std;

// class MyHashSet {
// public:
//     vector<bool> v;
//     int size = 1e6+1;

//     MyHashSet() {
//         v.resize(size);
//         fill(v.begin(), v.end(), false);
//     }
    
//     void add(int key) {
//         v[key] = true;
//     }
    
//     void remove(int key) {
//         v[key] = false;
//     }
    
//     bool contains(int key) {
//         return v[key] == true;
//     }
// };


class Node {
public:
    int key;
    Node* next;

    Node(int key, Node* next) {
        this->key = key;
        this->next= next;
    }
};

class MyHashSet {
public:
    vector<Node*> v;
    static const int size = 10000;

    MyHashSet() {
        v.resize(size);
    }
    
    int hash(int key) {
        return key % size;
    }

    void add(int key) {
        remove(key);
        int h = hash(key);
        Node* node = new Node(key, v[h]);   // v[h] is the prev value can be null initially
        v[h] = node;           
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
    }
    
    bool contains(int key) {
        int h = hash(key);
        Node* node = v[h];

        if(!node) return false;
        if(node->key == key) return true;

        while(node != NULL) {
            if(node->key == key) return true;
            node = node->next;
        }

        return false;
    }
};


int main(){
    MyHashSet hs;
    hs.add(1);
    hs.add(2);
    hs.add(3);
    hs.add(4);
    hs.add(4);

    hs.remove(2);
    hs.remove(3);

    cout << hs.contains(2) << endl; // 0
    cout << hs.contains(4) << endl; // 1
}

/*
LRU_Cache.cpp

https://leetcode.com/problems/lru-cache/
Method 1: Use Doubly linkedlist, unordered_map<key, addr(ll)>

We have to design a key, value Cache.
- get: First move the value to start of linkedlist and return the value.
    list1.splice(iterator position, list2, iterator i) - Transfer only the
    element pointed by i from list1 into the list2 at some position.

- put: if key exist in map. put the new value at m[key] address.
    If not, check the size: if(list.size() == size) capacity full
    get the key from ll and delete the map[key] and pop_back the linkedlist
    push the element to front. save the address in m[key] = l.begin();
*/

class node {
    public:
    int key, val;
    node* next, *prev;

    node(int _key, int _val) {
        key = _key;
        val = _val;
    }
};

class LRUCache {
    public:
    node * head = new node(-1, -1);
    node * tail = new node(-1, -1);

    int cap;
    unordered_map < int, node * > m;

    LRUCache(int capacity) {
        cap = capacity;
        head -> next = tail;
        tail -> prev = head;
    }

    void addnode(node * newnode) {
        node * temp = head -> next;
        newnode -> next = temp;
        newnode -> prev = head;
        head -> next = newnode;
        temp -> prev = newnode;
    }

    void deletenode(node * delnode) {
        node * delprev = delnode -> prev;
        node * delnext = delnode -> next;
        delprev -> next = delnext;
        delnext -> prev = delprev;
    }

    int get(int key_) {
        if (m.find(key_) != m.end()) {
            node * resnode = m[key_];
            int res = resnode -> val;
            m.erase(key_);
            deletenode(resnode);
            addnode(resnode);
            m[key_] = head -> next;
            return res;
        }
        return -1;
    }

    void put(int key_, int value) {
        if (m.find(key_) != m.end()) {
            node * existingnode = m[key_];
            m.erase(key_);
            deletenode(existingnode);
        }
        if (m.size() == cap) {
            m.erase(tail -> prev -> key);
            deletenode(tail -> prev);
        }

        addnode(new node(key_, value));
        m[key_] = head -> next;
    }
};





/*------------------LRU CACHE------------------*/
/*
class LRUCache {
public:
    list<pair<int, int>> l; // linkedlist of key and value
    unordered_map<int, list<pair<int, int>> :: iterator> m; //map of key, *linkedlistptr
    int size;   // max capacity of LL and map
    
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if(m.find(key) == m.end()) return -1;   // input key doesnt exist
        l.splice(l.begin(), l, m[key]);         // move the value at ptr(m[key]) to l.begin() of list l
        return m[key]->second;                  // return the value at addr m[key]
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end()) {            // key exist in map
            l.splice(l.begin(), l, m[key]);     // bring to front in ll
            m[key]->second = value;             // update the value at m[key] addr.
            return;
        }
        if(l.size() == size) {                          // linklist is full?
            auto keyOfLastLLElement = l.back().first;   // save key of last LL element
            m.erase(keyOfLastLLElement);                // erase the key from map
            l.pop_back();                               // remove the last element
        }
        // Now we have one space in LL & map
        l.push_front({key, value});         // add the key,value in ll
        m[key] = l.begin();                 // add the addr of ll to map at key
    }
};
*/
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

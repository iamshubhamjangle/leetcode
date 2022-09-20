/*
LFU_Cache.cpp



*/

class Node {
    int key;
    int value;
    int count;
    Node* next;
    Node* prev;
    
    public:
    Node(int _key, int _value) {
        key = _key;
        value = _value;
        count = 1;
        next = NULL;
        prev = NULL;
    }
};

struct List {
    int size;   // curr size of list
    Node* head;
    Node* tail;

    List() {
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addFront(Node* node) {
        Node* temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
        size++;
    }

    void removeNode(Node* node) {
        Node* delprev = node->prev;
        Node* delnext = node->next;
        delprev->next = delnext;
        delnext->prev = delprev;
        size--;
    }
};


class LFUCache {
public:
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);    
    
    int size;
    unordered_map<int,pair<Node*, int>> um; // key, <addr, freq>
    
    void addNode(Node* node) {
        Node* temp = 
    }
    
    void delete(Node* node) {
        
    }
    
    LFUCache(int capacity) {
        size = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(um.find(key) == um.end()) return -1;
        int ans = um[key].first->value;
        
        (um[key].second)++;
        
        return ans;
    }
    
    void put(int key, int value) {
        if()
        
        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
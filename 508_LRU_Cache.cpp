#include <bits/stdc++.h>
using namespace std;

template<typename T>
void print(vector<T> &v) { cout << "vector<T> = ["; for(int i=0; i<v.size(); i++) { cout << v[i]; if(i<v.size()-1) cout << ","; } cout << "]" << endl; }

template<typename T>
void print(vector<vector<T>> &v) { int n = v.size(); int m = v[0].size(); cout << "vector<vector<T>> = ["; for(int i=0; i<n; i++) { cout << "["; for(int j=0; j<m; j++) {cout << v[i][j]; if(j<m-1) cout << ","; } cout << "]"; } cout << "]" << endl; }


class Node {
public:
	Node *next, *prev;
	int key, value;

	Node(int _key, int _val) {
		key = _key;
		value = _val;
	}
};

class LRUCache {
public: 
	Node *head = new Node(-1, -1);
	Node *tail = new Node(-1, -1);

	int capacity;
	unordered_map<int, Node*> um;	// key, addr in DLL

	LRUCache(int _capacity) {
		capacity = _capacity;
		head->next = tail;
		tail->prev = head;
	}

	int get(int key) {
		// If key doesn't exist
		if(um.find(key) == um.end()) return -1;
		
		// Remove from LL and insert back
		Node* node = um[key];
		int tvalue = node->value;
		um.erase(key);
		removeNodeFromLL(node);
		addNodeToLL(node);

		// return the value
		return tvalue;
	}

	void put(int key, int value) {
		// If key exist in map? remove from LL & Map
		if(um.find(key) != um.end()) {
			Node* node = um[key];
			um.erase(key);
			removeNodeFromLL(node);
		}

		// Add to map and LL
		if(um.size() == capacity) { // overcapacity
			um.erase(tail->prev->key);
			removeNodeFromLL(tail->prev);
		}

		addNodeToLL(new Node(key, value));
		um[key] = head->next;
	}

	void addNodeToLL(Node* newNode) {
		Node* tail = head->next;
		newNode->next = tail;
		newNode->prev = head;
		head->next = newNode;
		tail->prev = newNode;
	}

	void removeNodeFromLL(Node* node) {
		Node* delHead = node->prev;
		Node* delTail = node->next;
		delHead->next = delTail;
		delTail->prev = delHead;
		delete node;
	}
};


int main(){
	LRUCache* lc = new LRUCache(2);
	lc->put(1, 1);
	cout << lc->get(1);
}
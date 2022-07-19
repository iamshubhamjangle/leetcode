#include<bits/stdc++.h>
using namespace std;

class TrieNode {
public:
	char data;
	TrieNode** children;
	bool isTerminal;

	TrieNode(char data) {
		this->data = data;
		children = new TrieNode*[26];
		for(int i=0; i<26; i++) {
			children[i] = NULL;	
		}
		isTerminal = false;
	}
};


class Trie {
	TrieNode* root;

	public:
	Trie() {
		root = new TrieNode('\0');
	}

	void insertWord(TrieNode* root, string word) {
		if(word.size() == 0) {
			root -> isTerminal = true;
			return;
		}

		int index = word[0] - 'a';		// a - 'a' = 0
		TrieNode* child = root -> children[index];
		if(child == NULL) {
			child = new TrieNode(word[0]);
			root -> children[index] = child;
		}

		insertWord(child, word.substr(1));
	}

	void insertWord(string word) {
		insertWord(root, word);
		return;
	}

	bool searchWord(TrieNode* root, string word) {
		if(word.size() == 0) {
			return root -> isTerminal;
		}

		int index = word[0] - 'a';
		TrieNode* child = root -> children[index];
		if(child == NULL) {
			return false;
		}

		return searchWord(child, word.substr(1));
	}

	bool searchWord(string word) {
		return searchWord(root, word);
	}

	void removeWord(TrieNode* root, string word) {
		if(word.size() == 0) {
			root->isTerminal = false;
			return;
		}

		int index = word[0] - 'a';
		TrieNode* child = root -> children[index];
		if(child == NULL) {
			return;
		}
		removeWord(child, word.substr(1));
	}

	void removeWord(string word) {
		removeWord(root, word);
	}
};



int main() {
	Trie t;
	t.insertWord("and");
	t.insertWord("are");
	t.insertWord("not");
	t.insertWord("dot");

	cout << t.searchWord("are") << endl;	// True
	t.removeWord("are");
	cout << t.searchWord("are") << endl;	// False
}
/*
Implement_Trie_Prefix_Tree.cpp
https://leetcode.com/problems/implement-trie-prefix-tree/
*/

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

	void insert(string word) {
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

	bool search(string word) {
		return searchWord(root, word);
	}
    
    bool startsWithHelper(TrieNode* root, string prefix) {
        if(prefix.size() == 0)
            return true;
        
        TrieNode* child = root->children[prefix[0]-'a'];
        if(child==NULL)
            return false;
        else{
            return startsWithHelper(child ,prefix.substr(1));
        }
    }
    
    bool startsWith(string prefix) {
        return startsWithHelper(root,prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */	

/*
Binary_Search_Tree_Iterator.cpp

Implement the BSTIterator class that represents an iterator over the
 in-order traversal of a binary search tree (BST):

https://leetcode.com/problems/binary-search-tree-iterator/
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
	stack<TreeNode*> s;

    // push all the left nodes to stack 
    BSTIterator(TreeNode* root) {
    	TreeNode* temp = root;

        while(temp != NULL) {
        	s.push(temp);
        	temp = temp->left;
        }
    }
    
    // top element of stack is our next. we will push all elements to it node->right->left... to stack
    int next() {
        TreeNode* temp = s.top();
        s.pop();
        int ans = temp->val;

        if(temp->right != NULL) {
        	temp = temp->right;
        	while(temp != NULL) {
        		s.push(temp);
        		temp = temp->left;
        	}
        }

        return ans;
    }
    

    // If stack is empty it is not having next.
    bool hasNext() {
        return !s.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
/*
Two_Sum_IV_Input_is_a_BST.cpp

Given the root of a Binary Search Tree and a target number k, return true 
if there exist two elements in the BST such that their sum is equal to the given target.

Input: root = [5,3,6,2,4,null,7], k = 9
Output: true

Input: root = [5,3,6,2,4,null,7], k = 28
Output: false

https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
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

// // 1. Form sorted array and use normal two pointer method.. TC: O(N) SC: O(N) ASC: O(H)
// class Solution {
// public:
// 	void inorder(TreeNode* root, vector<int> &v) {
// 		if(root == NULL) return;

// 		inorder(root->left, v);
// 		v.push_back(root->val);
// 		inorder(root->right, v);
// 	}

// 	bool twoSum(vector<int> &v, int k) {
// 		int n = v.size();
// 		int i = 0;
// 		int j = n-1;

// 		while(i < j) {
// 			if(v[i] + v[j] == k)
// 				return true;
// 			else if(v[i] + v[j] > k)
// 				j--;
// 			else
// 				i++;
// 		}

// 		return false;
// 	}

//     bool findTarget(TreeNode* root, int k) {
// 		vector<int> v;
// 		inorder(root, v);
// 		sort(v.begin(), v.end());
// 		return twoSum(v, k);
//     }
// };


// 2. Using BST Iterator. TC: O(H) SC: O(N) 
class BSTIterator {
    stack<TreeNode *> myStack;
    bool reverse = true; 
public:
    BSTIterator(TreeNode *root, bool isReverse) {
        reverse = isReverse; 
        pushAll(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !myStack.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *tmpNode = myStack.top();
        myStack.pop();
        if(!reverse) pushAll(tmpNode->right);
        else pushAll(tmpNode->left);
        return tmpNode->val;
    }

private:
    void pushAll(TreeNode *node) {
        for(;node != NULL; ) {
             myStack.push(node);
             if(reverse == true) {
                 node = node->right; 
             } else {
                 node = node->left; 
             }
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false; 
        BSTIterator l(root, false); 
        BSTIterator r(root, true); 
        
        int i = l.next(); 
        int j = r.next(); 
        while(i<j) {
            if(i + j == k) return true; 
            else if(i + j < k) i = l.next(); 
            else j = r.next(); 
        }
        return false; 
    }
};
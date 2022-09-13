/*
Recover_Binary_Search_Tree.cpp

You are given the root of a binary search tree (BST), where the values of 
exactly two nodes of the tree were swapped by mistake. 
Recover the tree without changing its structure.

Input: root = [1,3,null,null,2]
Output: [3,1,null,null,2]

Input: root = [3,1,4,null,null,2]
Output: [2,1,4,null,null,3]

https://leetcode.com/problems/recover-binary-search-tree/
1. Inorder -> sort -> replace. TC: O(2N + NlogN) SC: O(N)
2. 

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


// // 1. Inorder -> sort -> replace. TC: O(2N + NlogN) SC: O(N)
// class Solution {
// public:
//     int i = 0;
    
// 	void inorder(TreeNode* root, vector<int> &v) {
// 		if(root == NULL) return;

// 		inorder(root->left, v);
// 		v.push_back(root->val);
// 		inorder(root->right, v);
// 	}

// 	void inorderReplace(TreeNode* root, vector<int> &v) {
// 		if(root == NULL) return;

// 		inorderReplace(root->left, v);
// 		if(root->val != v[i])
// 			root->val = v[i];
// 		i++;
// 		inorderReplace(root->right, v);
// 	}

//     void recoverTree(TreeNode* root) {
//         vector<int> v;
//         inorder(root, v);
//         sort(v.begin(), v.end());
//         inorderReplace(root, v);
//     }
// };



// 2. 
class Solution {
private:
	TreeNode* first;
	TreeNode* mid;
	TreeNode* last;
	TreeNode* prev;
public:
	void inorder(TreeNode* root) {
		if(root == NULL) return;

		inorder(root->left);

		if(prev != NULL && (root->val < prev->val)) {
			if(first == NULL) {
				first = prev;
				mid = root;
			} else {
				last = root;
			}
		}
		prev = root;

		inorder(root->right);
	}

    void recoverTree(TreeNode* root) {
        first = mid = last = NULL;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        if(first && last) swap(first->val, last->val);
        else if(first && mid) swap(first->val, mid->val);
    }
};
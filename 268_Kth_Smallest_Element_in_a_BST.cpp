/*
Kth_Smallest_Element_in_a_BST.cpp

Given the root of a binary search tree, and an integer k, return the kth 
smallest value (1-indexed) of all the values of the nodes in the tree.

Input: root = [3,1,4,null,2], k = 1
Output: 1

Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3

https://leetcode.com/problems/kth-smallest-element-in-a-bst/
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

// // 1. Preorder, sort. TC: O(NlogN) SC: O(N) ASC: O(logN)
// class Solution {
// public:
// 	void dfs(TreeNode* root, vector<int> &v) {
// 		if(root == NULL) return;

// 		v.push_back(root->val);
// 		if(root->left) dfs(root->left, v);
// 		if(root->right) dfs(root->right, v);
// 	}

//     int kthSmallest(TreeNode* root, int k) {
//         vector<int> v;
//         dfs(root, v);				// preorder
//         sort(v.begin(), v.end());	// sort
//         return v[k-1];				// return
//     }
// };


// keep a counter while printing. TC: O(N) SC: O(1) ASC: O(logN)
class Solution {
public:
	int ans;
	void dfsInorder(TreeNode* root, int &k) {
		if(root == NULL) return;

		if(root->left) dfsInorder(root->left, k);
		k--; if(k == 0) ans = root->val;
		if(root->right) dfsInorder(root->right, k);
	}

    int kthSmallest(TreeNode* root, int k) {
        dfsInorder(root, k);				// inorder
        return ans;
    }
};




class Solution {
public:
    int ans;
    void dfsInorder(TreeNode* root, int &k) {
        if(root == NULL) return;

        if(root->left) dfsInorder(root->left, k);
        k--; if(k == 0) ans = root->val;
        if(root->right) dfsInorder(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        dfsInorder(root, k);                // inorder
        return ans;
    }
};
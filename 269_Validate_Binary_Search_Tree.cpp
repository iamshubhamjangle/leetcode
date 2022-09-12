/*
Validate_Binary_Search_Tree.cpp

Given the root of a binary tree, determine if it is a valid binary search tree (BST).

https://leetcode.com/problems/validate-binary-search-tree/
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


class Solution {
public:
    bool dfsPostorder(TreeNode* root, long int min, long int max) {
        if(root == NULL) 
        	return true;

    	if(root->val <= min || root->val >= max)
    		return false;

        bool l = dfsPostorder(root->left, min, root->val);
        bool r = dfsPostorder(root->right, root->val, max);

        return l && r;
    }
    
    bool isValidBST(TreeNode* root) {
        return dfsPostorder(root, long.INT_MIN, long.INT_MAX);
    }
};
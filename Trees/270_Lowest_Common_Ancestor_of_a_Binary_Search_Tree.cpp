/*
Lowest_Common_Ancestor_of_a_Binary_Search_Tree.cpp

Given a binary search tree (BST), find the lowest common ancestor (LCA)
 node of two given nodes in the BST.

https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// we are returning root in all cases except when val(root) < or > both p, q
// go left or right if both values are in that direction
class Solution {
public:
	//Recursive:  TC: O(H) SC: O(1) ASC: O(H)		~ H is logN
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
        	return root;

		if(p->val < root->val && q->val < root->val) {
        	root = root->left;
        	return lowestCommonAncestor(root, p, q);
        }
        else if(p->val > root->val && q->val > root->val) {
        	root = root->right;
        	return lowestCommonAncestor(root, p, q);
        } else {
        	return root;
        }
    }

    // Iterative TC: O(H) SC: O(1) ASC: O(H)		~ H is logN
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root != NULL) {
	        if(p->val < root->val && q->val < root->val) {
	        	root = root->left;
	        }
	        else if(p->val > root->val && q->val > root->val) {
	        	root = root->right;
	        } 
	        else {
	        	return root;
	        }
        }
        return NULL;	// if root becomes NULL
    }
};
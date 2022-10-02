/*
Insert_into_a_Binary_Search_Tree.cpp

You are given the root node of a binary search tree (BST) and a value to 
insert into the tree. Return the root node of the BST after the insertion. 
It is guaranteed that the new value does not exist in the original BST.

https://leetcode.com/problems/insert-into-a-binary-search-tree/
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
    	if(root == NULL)
    		return new TreeNode(val);

    	TreeNode* curr = root;

    	while(true) {
    		if(curr->val <= val) {
    			if(curr->right != NULL) {
    				curr = curr->right;
    			}
    			else {
    				curr->right = new TreeNode(val);
    				break;
    			}
    		} else {
    			if(curr->left != NULL) {
    				curr = curr->left;
    			} else {
    				curr->left = new TreeNode(val);
    				break;
    			}
    		}
    	}

    	return root;
    }
};
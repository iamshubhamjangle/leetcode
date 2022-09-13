/*
Inorder_Successor_in_bst.cpp

Given a binary tree and a node, we need to write a program to find inorder successor of this node.
Inorder Successor of a node in binary tree is the next node in Inorder traversal of the Binary Tree. 
Inorder Successor is NULL for the last node in Inorder traversal.

https://leetcode.com/problems/inorder-successor-in-bst/  **PREMIUM**
1. Iterate, store (sorted as bst), binary search next greater. TC: O(N) SC: O(N)
2. Iterate, keep track of node element greater than k.	TC: O(N) SC: O(1)
3. Using BST left/right property, moving height wise. TC: O(H) SC: O(1)

*/

class Solution {
public:
	TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
		TreeNode* successor = NULL;

		while(root != NULL) {
			if(root->val <= p->val) {
				root = root->right;
			} else {
				successor = root;
				root = root->left;
			}
		}

		return successor;
	}
}
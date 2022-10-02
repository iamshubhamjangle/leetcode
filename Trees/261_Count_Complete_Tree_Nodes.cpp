/*
Count_Complete_Tree_Nodes.cpp

Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, is completely filled in 
a complete binary tree, and all nodes in the last level are as far left as possible. 
It can have between 1 and 2h nodes inclusive at the last level h.

Design an algorithm that runs in less than O(n) time complexity.
Input: root = [1,2,3,4,5,6]
Output: 6

Input: root = []
Output: 0

Input: root = [1]
Output: 1

https://leetcode.com/problems/count-complete-tree-nodes/
*/


class Solution {
public:
	// Method 1:
	// TC: findHeight * traverse x nodes
	// TC: O(logN) * O(logN)
	// SC: O(logN)
	int findLeftHeight(TreeNode* node) {
		int height = 0;
		while(node) {
			height++;
			node = node->left;
		}
		return height;
	}

	int findRightHeight(TreeNode* node) {
		int height = 0;
		while(node) {
			height++;
			node = node->right;
		}
		return height;
	}

    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;

        int lh = findLeftHeight(root);
        int rh = findRightHeight(root);

        // if both height are equal return (2^n - 1)
        if(lh == rh) return (1<<lh) - 1;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
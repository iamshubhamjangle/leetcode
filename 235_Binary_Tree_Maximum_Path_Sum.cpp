/*
Binary_Tree_Maximum_Path_Sum.cpp

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path.

https://leetcode.com/problems/binary-tree-maximum-path-sum/
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
    int maxPathSum(TreeNode* root) {
		int maxi = INT_MIN;
		maxPathDown(root, maxi);
		return maxi;
    }

    int maxPathDown(TreeNode* node, int &maxi) {
    	if(node == NULL) return 0;
    	int left = max(0, maxPathDown(node->left, maxi));	// 0 to skip negative
    	int right = max(0, maxPathDown(node->right, maxi));	// 0 to skip negative
    	maxi = max(maxi, left + right + node->val);
    	return max(left, right) + node->val;
    }
};
/*
Symmetric_Tree.cpp

Given the root of a binary tree, check whether it is a mirror of itself 
(i.e., symmetric around its center).

https://leetcode.com/problems/symmetric-tree/
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
    bool solve(TreeNode* left, TreeNode* right) {
        if(left == NULL || right == NULL)
            return left == right;

        if(left->val != right->val)
            return false;

        return solve(left->left, right->right) && solve(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        return root == NULL || solve(root->left, root->right);
    }
};
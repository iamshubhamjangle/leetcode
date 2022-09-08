/*
Root_Equals_Sum_of_Children.cpp

You are given the root of a binary tree that consists of exactly 3 nodes: 
the root, its left child, and its right child.
Return true if the value of the root is equal to the sum of the values of 
its two children, or false otherwise.

https://leetcode.com/problems/root-equals-sum-of-children/
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
    // bool checkTree(TreeNode* root) {
    //     int left = root->left->val;
    //     int right = root->right->val;
    //     return root->val == (left + right);
    // }
    
    bool checkTree(TreeNode* root) {
        return root->val == (root->left->val + root->right->val);
    }
};
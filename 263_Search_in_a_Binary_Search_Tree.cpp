/*
Search_in_a_Binary_Search_Tree.cpp

You are given the root of a binary search tree (BST) and an integer val.
Find the node in the BST that the node's value equals val and return the 
subtree rooted with that node. If such a node does not exist, return null.

https://leetcode.com/problems/search-in-a-binary-search-tree/
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
    // Iterative. TC: O(LogN base 2) SC: O(logN)
    TreeNode* searchBST(TreeNode* root, int k) {
        while(root != NULL && root->val != k)
            root = k < root->val ? root->left : root->right;

        return root;
    }


    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) return root;

        TreeNode *node=new TreeNode(); 
        if(val<root->val){
            node=searchBST(root->left,val);
        } else if(val>root->val){
            node=searchBST(root->right,val);
        }
        //  else {
        //     node=root;
        // }
        return node;
    }
};
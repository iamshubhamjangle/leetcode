/*
Binary_Tree_Preorder_Traversal.cpp

https://leetcode.com/problems/binary-tree-preorder-traversal/description/
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
    // // Recursive. TC: O(N) SC: O(1) ASC: O(H)
    // void solve(TreeNode* root, vector<int> &res) {
    //     if(!root) return;
    //     res.push_back(root->val);
    //     if(root->left)  solve(root->left,  res);
    //     if(root->right) solve(root->right, res);
    // }

    // vector<int> preorderTraversal(TreeNode* root) {
    //     vector<int> res = {};
    //     solve(root, res);
    //     return res;
    // }


    // // Iterative.
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return {};

        vector<int> res;
        stack<TreeNode*> s;
        s.push(root);

        while(!s.empty()) {
            TreeNode* node = s.top(); s.pop();
            res.push_back(node->val);

            if(node->right) s.push(node->right);
            if(node->left)  s.push(node->left);
        }

        return res;
    }

};
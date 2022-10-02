/*
Binary_Tree_Preorder_Traversal.cpp

Given the root of a binary tree, return the preorder traversal of its nodes' values.

Input: root = [1,null,2,3]
Output: [1,2,3]

Input: root = []
Output: []

Input: root = [1]
Output: [1]

https://leetcode.com/problems/binary-tree-preorder-traversal/
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
//     // Recursive Traversal. TC: O(# of Nodes) ASC: O(height)
//     void solve(TreeNode* root, vector<int> &ans) {
//         if(root == NULL) return;
        
//         ans.push_back(root->val);
//         solve(root->left, ans);
//         solve(root->right, ans);
//     }
    
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> ans;
//         solve(root, ans);
//         return ans;
//     }
    
    // Iterative. TC: O(# of Nodes) SC: O(Height)
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
         
        stack<TreeNode*> s;
        s.push(root);
                
        while(!s.empty()) {
            TreeNode* node = s.top();
            s.pop();
            
            ans.push_back(node->val);
            if(node->right) s.push(node->right);
            if(node->left) s.push(node->left);
        }
        
        return ans;
    }
};







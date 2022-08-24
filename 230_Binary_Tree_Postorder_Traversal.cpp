/*
Binary_Tree_Postorder_Traversal.cpp   

Given the root of a binary tree, return the postorder traversal of its nodes' values.

Input: root = [1,null,2,3]
Output: [3,2,1]

Input: root = []
Output: []

Input: root = [1]
Output: [1]

https://leetcode.com/problems/binary-tree-postorder-traversal/

*/
/***
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
    
//     // Recursion. TC: O(# nodes) ASC: O(height)
//     void solve(TreeNode* node, vector<int> &ans) {
//         if(node == NULL) return;
        
//         // left, right, root
//         solve(node->left, ans);
//         solve(node->right, ans);
//         ans.push_back(node->val);
//     }
    
//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int> ans;
//         solve(root, ans);
//         return ans;
//     }
    
    
    // Iterative. TC: SC:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        
        stack<TreeNode*> s1, s2;
        s1.push(root);

        while(!s1.empty()) {
            root = s1.top();
            s1.pop();
            s2.push(root);
            if(root->left)  s1.push(root->left);
            if(root->right) s1.push(root->right);
        }
        while(!s2.empty()) {
            ans.push_back(s2.top() -> val);
            s2.pop();
        }

        return ans;
    }
    
};
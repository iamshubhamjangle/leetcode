/*
Binary_Tree_Level_Order_Traversal.cpp

Given the root of a binary tree, return the level order traversal of 
its nodes' values. (i.e., from left to right, level by level).

Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]

Input: root = [1]
Output: [[1]]

Input: root = []
Output: []

https://leetcode.com/problems/binary-tree-level-order-traversal/
TC: O(N) SC: O(N)
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
    // TC: O(N) SC: O(N)
    // we will be using queue and a local level, later push local level to ans.
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if(root == NULL) return ans;

        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            vector<int> level;
            for(int i=0; i<n; i++) {
                TreeNode* node = q.front(); q.pop();
                level.push_back(node->val);
                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.push_back(level);
        }
        
        return ans;
    }
};
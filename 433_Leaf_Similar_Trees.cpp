/*
Leaf_Similar_Trees.cpp

https://leetcode.com/problems/leaf-similar-trees/
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
    // TC: O(2N) SC: O(N) ASC: O(H)
    void solve(TreeNode* root, vector<int> &v) {
        if(!root) return;

        if(!root->left && !root->right)
            v.push_back(root->val);
        
        if(root->left)  solve(root->left,  v);
        if(root->right) solve(root->right, v);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> t1, t2;
        solve(root1, t1);
        solve(root2, t2);
        if(t1.size() != t2.size()) 
            return false;
        for(int i=0; i<t1.size(); i++)
            if(t1[i] != t2[i]) return false;
        return true;
    }
};
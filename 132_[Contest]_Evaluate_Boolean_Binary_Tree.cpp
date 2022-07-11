/*
[Contest]_Evaluate_Boolean_Binary_Tree.cpp

https://leetcode.com/problems/evaluate-boolean-binary-tree/
Method: Recusive: O(N) SC: O(S) - size of stack
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
	bool evaluateTree(TreeNode* root) {
        if (!root->left and !root->right)   return root->val;
        int l = evaluateTree(root->left);
        int r = evaluateTree(root->right);
        return (root->val == 2) ? l or r : l and r;
    }

    bool evaluateTree1(TreeNode* root) {
        if(root==NULL) return true;
        
        bool left = evaluateTree(root->left);
        bool right = evaluateTree(root->right);
        
        if(root->val == 2) {
            return left + right;
        } 
        else if(root->val == 3) {
            return left * right;
        }
        else if(root->val == 0) {
            return false;
        }
        
        return true;
    }
};
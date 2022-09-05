/*
Binary_Tree_Right_Side_View.cpp

Given the root of a binary tree, imagine yourself standing on the right side of it, 
return the values of the nodes you can see ordered from top to bottom.

https://leetcode.com/problems/binary-tree-right-side-view/
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
    // BFS - Iterative - keeping a last variable. TC: O(N) SC: O(N) 
    // -- In worst case all bottom nodes will be stored in queue, to avoid this we go with DFS
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            int n = q.size();
            int last;
            while(n--) {
                TreeNode* tn = q.front(); q.pop();
                
                if(tn->left)  q.push(tn->left);
                if(tn->right) q.push(tn->right);
                
                last = tn->val;
            }
            ans.push_back(last);
        }
        
        return ans;
    }

    // DFS - Reverse Preorder. TC: O(N) SC: O(H)
    // In worst case it can be skew tree so O(H) ~ O(N)

    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;
                
        return solve(root, 0);
    }    
};
/*
Add_One_Row_to_Tree.cpp

https://leetcode.com/problems/add-one-row-to-tree/
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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) { // if depth is 1, then we have to simply add root
		    TreeNode* newNode = new TreeNode(val);
		    newNode -> left = root;
		    return newNode; // now this act as new root
		}
        
        queue<TreeNode*> q;  // node, level
        q.push(root);
        int count = 0;
        
        while(!q.empty()) {
        	int n = q.size();
        	count++;

        	while(n--) {
	            TreeNode* node = q.front(); q.pop();
	            
	            if(count == depth-1) {
	                TreeNode* newNodeLeft = new TreeNode(val);
	                newNodeLeft->left = node->left;
	                node->left = newNodeLeft;

	                TreeNode* newNodeRight = new TreeNode(val);
	                newNodeRight->right = node->right;
	                node->right = newNodeRight;
	            } else {
		            if(node->left) q.push(node->left);
		            if(node->right) q.push(node->right);
	            }
	            
	            
        	}
        }
        
        return root;
    }
};


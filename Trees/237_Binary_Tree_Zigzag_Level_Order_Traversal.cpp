/*
Binary_Tree_Zigzag_Level_Order_Traversal.cpp

Given the root of a binary tree, return the zigzag level 
order traversal of its nodes' values. (i.e., from left 
to right, then right to left for the next level and alternate between).

Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]

Input: root = [1]
Output: [[1]]

Input: root = []
Output: []

https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> ans;
		if(root == NULL) return ans;

		queue<TreeNode*> q;
		q.push(root);
		bool leftToRight = true;

		while(!q.empty()) {
			int n = q.size();
			vector<int> row(n);
			for(int i=0; i<n; i++) {
				TreeNode* node = q.front();
				q.pop();

				int index = leftToRight ? i : (n-i-1);

				row[index] = node->val;
				if(node->left) q.push(node->left);
				if(node->right) q.push(node->right);
			}

			leftToRight = !leftToRight;
			ans.push_back(row);
		}
		
		return ans;
    }
};
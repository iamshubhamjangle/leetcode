/*
Path_to_Given_Node.cpp

Given a Binary Tree A containing N nodes.
You need to find the path from Root to a given node B.

https://www.interviewbit.com/problems/path-to-given-node/
*/

/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/


// Approach: Inorder traversal. TC: O(N), SC: O(H)
bool getPath(TreeNode* root, vector<int> &ans, int x) {
	if(!root) return false;

	ans.push_back(root->val);

	if(root->val == x) 
		return true;
	if(getPath(root->left, ans, x) || getPath(root->right, ans, x))
		return true;

	ans.pop_back();
	return false;
}

vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> ans;
    if(A == NULL) return ans;

    getPath(A, ans, B);
    return ans;
}


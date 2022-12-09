/*
Maximum_Difference_Between_Node_and_Ancestor.cpp

https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/
*/

// Method 1: DFS. TC: O(N) ASC: O(H)
class Solution {
public:
	int res = 0;

	void dfs(TreeNode* root, int mini, int maxi) {
		if(root == NULL) return;

		int curr = root->val;
		mini = min(curr, mini);
		maxi = max(curr, maxi);
		res = max(abs(maxi - mini), res);

		if(root->left)  dfs(root->left,  mini, maxi);
		if(root->right) dfs(root->right, mini, maxi);
	}

    int maxAncestorDiff(TreeNode* root) {
    	if(!root) return 0;
        dfs(root, root->val, root->val)
        return res;
    }
};
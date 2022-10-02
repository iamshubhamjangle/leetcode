/*
Construct_Binary_Tree_from_Preorder_and_Inorder_Traversal.cpp

Given two integer arrays preorder and inorder where preorder is the preorder traversal of a 
binary tree and inorder is the inorder traversal of the same tree, construct and return the 
binary tree.

https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
*/


class Solution {
public:
	// TC: O(N) SC: O(N)
	TreeNode* solve(vector<int> &preorder, int ps, int pe, vector<int> &inorder, int is, int ie, map<int,int> &mp) {
		if(ps > pe || is > ie)
			return NULL;

		TreeNode* root = new TreeNode(preorder[ps]);
		int inRootPos = mp[root->val];
		int numsToLeft = inRootPos - is;

		root->left = solve(preorder, ps+1, ps+numsToLeft, inorder, is, inRootPos-1, mp);
		root->right = solve(preorder, ps+numsToLeft+1, pe, inorder, inRootPos+1, ie, mp);
		
		return root;
	}

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> mp;

        // create a map of inorder and is position
        for(int i=0; i<inorder.size(); i++) mp[inorder[i]] = i;

        TreeNode* root = solve(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, mp);
    	return root;
    }
};
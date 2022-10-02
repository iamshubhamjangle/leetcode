/*
Construct_Binary_Search_Tree_from_Preorder_Traversal.cpp

Given an array of integers preorder, which represents the preorder traversal of a BST 
(i.e., binary search tree), construct the tree and return its root.

Input: preorder = [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]

Input: preorder = [1,3]
Output: [1,null,3]

https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
	// 1. Bruteforce. TC: O(n*n)
	// 2. Using Build tree from preorder and inorder concept. TC: O(NLogN) SC: O(N)
	// 3. using upperbound concept. TC: O(N) SC: O(1)
*/

//class TreeNode() : val(0), left(nullptr), right(nullptr) {}

class Solution {
public:
	// // 2. Using Build tree from preorder and inorder concept. TC: O(NLogN) SC: O(N)
	// TreeNode* solve(vector<int> &preorder, int ps, int pe, vector<int> &inorder, int is, int ie, map<int,int> &mp) {
	// 	if(ps > pe || is > ie)
	// 		return NULL;

	// 	TreeNode* root = new TreeNode(preorder[ps]);
	// 	int inRootPos = mp[root->val];
	// 	int numsToLeft = inRootPos - is;

	// 	root->left = solve(preorder, ps+1, ps+numsToLeft, inorder, is, inRootPos-1, mp);
	// 	root->right = solve(preorder, ps+numsToLeft+1, pe, inorder, inRootPos+1, ie, mp);
		
	// 	return root;
	// }

 //    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
 //        map<int, int> mp;

 //        // create a map of inorder and is position
 //        for(int i=0; i<inorder.size(); i++) mp[inorder[i]] = i;

 //        TreeNode* root = solve(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, mp);
 //    	return root;
 //    }

 //    TreeNode* bstFromPreorder(vector<int>& preorder) {
 //    	vector<int> inorder(preorder);
 //    	sort(inorder.begin(), inorder.end());
 //    	return buildTree(preorder, inorder);
 //    }


	// 3. using upperbound concept. TC: O(N) SC: O(1)
	TreeNode* build(vector<int> &preorder, int &i, int bound) {
		if(i == preorder.size() || preorder[i] > bound) return NULL;
		TreeNode* root = new TreeNode(preorder[i]);
		i++;
		root->left  = build(preorder, i, root->val	);	// ub = curr val
		root->right = build(preorder, i, bound);		// ub = bound
		return root;
	}

    TreeNode* bstFromPreorder(vector<int>& preorder) {
    	int i = 0;
    	return build(preorder, i, INT_MAX);
    }

};
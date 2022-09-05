/*
Top_View_of_Binary_Tree.cpp

Given below is a binary tree. The task is to print the top view of binary tree.

Input:
      1
   /    \
  2      3
Output: 2 1 3

Input:
       10
    /      \
  20        30
 /   \    /    \
40   60  90    100
Output: 40 20 10 30 100

https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1
*/

class Solution {
    public:
    vector<int> topView(Node *root) {
		vector<int> ans;
		map<int, int> mp;
		queue<pair<Node*, int>> q;
		
		if(root == NULL) return ans;
		
		q.push({root, 0});
		while(!q.empty()) {
			auto it = q.front(); q.pop();
			Node* node = it.first;
			int line = it.second;

			if(mp.find(line) == mp.end())	// only insert first time in map
				mp[line] = node->data;

			if(node->left) q.push({node->left, line-1});
			if(node->right) q.push({node->right, line+1});
		}

		for(auto it: mp) {
			ans.push_back(it.second);
		}

		return ans;
    }
};
/*
Bottom_View_of_Binary_Tree.cpp

Given a binary tree, print the bottom view from left to right.

https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1
*/

class Solution {
  public:
  	// As this is BFS traversal, if we use DFS, right side of the tree nodes will be considered later
  	// this may cause using prev level node appearing in the line map.

    // vector<int> bottomView(Node *root) {
    //     vector<int> ans;
    //     queue<pair<Node*, int>> q;
    //     unordered_map<int, int> um;

    //     if(root == NULL) return ans;

    //     q.push({root, 0});
    //     while(!q.empty()) {
    //     	int n = q.size();
    //     	while(n--) {
    //     		pair<Node*, int> temp = q.front(); q.pop();

    //     		if(temp.first->left) q.push({temp.first->left, temp.second - 1});
    //     		if(temp.first->right) q.push({temp.first->right, temp.second + 1});

    //     		um[temp.second] = temp.first->data;
    //     	}
    //     }

    //     vector<pair<int,int>> sorted; 
    //     for(auto i: um) {
    //     	sorted.push_back({i.first, i.second});
    //     }
    //     sort(sorted.begin(), sorted.end());

    //     for(auto i: sorted)
    //     	ans.push_back(i.second);

    //     return ans;
    // }



    vector<int> bottomView(Node *root) {
        vector<int> ans;
        queue<pair<Node*, int>> q;
        map<int, int> mp;

        if(root == NULL) return ans;

        q.push({root, 0});
        while(!q.empty()) {
        	int n = q.size();
        	while(n--) {
        		pair<Node*, int> temp = q.front(); q.pop();

        		if(temp.first->left) q.push({temp.first->left, temp.second - 1});
        		if(temp.first->right) q.push({temp.first->right, temp.second + 1});

        		mp[temp.second] = temp.first->data;
        	}
        }

        for(auto i: mp)
        	ans.push_back(i.second);

        return ans;
    }
};
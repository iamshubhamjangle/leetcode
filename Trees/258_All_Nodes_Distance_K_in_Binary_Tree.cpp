/*
All_Nodes_Distance_K_in_Binary_Tree.cpp

Given the root of a binary tree, the value of a target node target, 
and an integer k, return an array of the values of all nodes that have 
a distance k from the target node.

You can return the answer in any order.

https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
*/

/**
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
	void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent_track) {
		queue<TreeNode*> q;
		q.push(root);

		while(!q.empty()) {
			TreeNode* front = q.front(); q.pop();
			if(front->left) {
				parent_track[front->left] = front;
				q.push(front->left);
			}
			if(front->right) {
				parent_track[front->right] = front;
				q.push(front->right);
			}
		}
	}

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent_track;	// node->parent relation
        unordered_map<TreeNode*, bool> visited;	// node->true
        markParents(root, parent_track);

        // lets do BFS from target node
        // if target node not provide find it using DFS - preorder/inorder
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        int curr_level = 0;		// we will go upto k

        while(!q.empty()) {
        	int n = q.size();
        	curr_level++;
        	if(curr_level == k) break;

        	while(n--) {
        		TreeNode* curr = q.front(); q.pop();
        		// we will go left, right, parent
        		if(curr->left && !visited[curr->left]) {
        			q.push(curr->left);
        			visited[curr->left] = true;
        		}
        		if(curr->right && !visited[curr->right]) {
        			q.push(curr->right);
        			visited[curr->right] = true;
        		}
        		if(parent_track[curr] && !visited[parent_track[curr]]) {
        			q.push(parent_track[curr]);
        			visited[parent_track[curr]] = true;
        		}
        	}
        }

        vector<int> ans;	// we need to return all three nodes at depth k
        while(!q.empty()) {
        	TreeNode* curr = q.front(); q.pop();
        	ans.push_back(curr->val);
        }

        return ans;
    }
};
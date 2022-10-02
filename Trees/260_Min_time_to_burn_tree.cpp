/*
Min_time_to_burn_tree.cpp

Given a binary tree and a node called target. Find the minimum time required to 
burn the complete binary tree if the target is set on fire. It is known that in 
1 second all nodes connected to a given node get burned. That is its left child, 
right child, and parent.

https://practice.geeksforgeeks.org/problems/burning-tree/1
*/


class Solution {
    // map the parent and also return the target node
    Node* mapParent(Node* root, unordered_map<Node*, Node*> &parent, int target) {
        queue<Node*> q;
        q.push(root);
        Node* temp;
        
        while(!q.empty()) {
            int n = q.size();
            while(n--) {
                Node* curr = q.front(); q.pop();
                if(curr->data == target)
                    temp = curr;
                    
                if(curr->left) {
                    parent[curr->left] = curr;
                    q.push(curr->left);
                }
                
                if(curr->right) {
                    parent[curr->right] = curr;
                    q.push(curr->right);
                }
            }
        }
        
        return temp;
    }
    
    
    int func(unordered_map<Node*, Node*> &um, Node* target) {
        queue<Node*> q;
        q.push(target);
        
        int ans = 0;
        unordered_map<Node*, bool> visited;
        
        visited[target] = true;
        
        while(!q.empty()) {
            int n = q.size();
            int nodeBurned = false;
            
            while(n--) {
                Node* curr = q.front(); q.pop();
                
                // burn left node
                if(curr->left && !visited[curr->left]) {
                    nodeBurned = true;
                    visited[curr->left] = true;
                    q.push(curr->left);
                }
                
                // burn right node
                if(curr->right && !visited[curr->right]) {
                    nodeBurned = true;
                    visited[curr->right] = true;
                    q.push(curr->right);
                }
                
                // burn parent
                if(um[curr] && !visited[um[curr]]) {
                    nodeBurned = true;
                    visited[um[curr]] = true;
                    q.push(um[curr]);
                }
            }
            
            if(nodeBurned)
                ans++;
        }
        
        return ans;
    }
    
    
    public:
    int minTime(Node* root, int target) {
        if(root == NULL) return 0;
        
        unordered_map<Node*, Node*> um;
        Node* targetNode = mapParent(root, um, target);
        
        return func(um, targetNode);
    }
};
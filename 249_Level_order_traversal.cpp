/*
Level_order_traversal.cpp
Given a binary tree, find its level order traversal.
Level order traversal of a tree is breadth-first traversal for the tree.

Input:
    1
  /   \ 
 3     2
Output:1 3 2

https://practice.geeksforgeeks.org/problems/level-order-traversal/1
*/

class Solution {
    // Function to reverse the queue
    void reverseQueue(queue<int>& Queue) {
        stack<int> Stack;
        while (!Queue.empty()) {
            Stack.push(Queue.front());
            Queue.pop();
        }
        while (!Stack.empty()) {
            Queue.push(Stack.top());
            Stack.pop();
        }
    }

    public:
    vector<int> levelOrder(Node* node) {
        queue<Node*> q;
        vector<int> ans;
        if(node == NULL) return ans;

        q.push(node);
        while(!q.empty()) {
            int n = q.size();
            while(n--) {
                Node* up = q.front(); q.pop();
                
                

                if(up->left) q.push(up->left);
                if(up->right) q.push(up->right);
            }
        }

        return ans;
    }
};

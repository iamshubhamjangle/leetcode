/*
Height_of_Binary_Tree.cpp

Given a binary tree, find its height.

https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1
*/

//Function to find the height of a binary tree.
class Solution{
    public:
    // 1. TC: O(N) - no of nodes SC: O(1) ASC: O(N)
    int height(struct Node* node){
        if(node == NULL) {
            return 0;
        }
        
        int l = height(node->left);
        int r = height(node->right);
        
        return 1 + max(l, r);
    }

    // looking at constraints there will be 1 minimun node so root will never be NULL
    // hence lets avoid calls to null pointers.
    int height(struct Node* node){
        int l = node->left ? height(node->left) : 0;
        int r = node->right ? height(node->right) : 0;
        
        return 1 + max(l, r);
    }};
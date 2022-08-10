/*
Root_to_leaf_path_sum.cpp

Input:
Tree = 
            1
          /   \
        2      3
S = 4

Output: 1

https://practice.geeksforgeeks.org/problems/root-to-leaf-path-sum/1
*/

class Solution {
public:
    bool hasPathSum(Node *root, int S) {
        if(root->left == NULL && root->right == NULL) {
            return S == root->data;
        }
        
        bool l = root->left && hasPathSum(root->left, S - root->data);
        bool r = root->right && hasPathSum(root->right, S - root->data);
        
        return l || r;
    }
};
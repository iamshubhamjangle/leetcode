/*
Mirror_Tree.cpp

https://practice.geeksforgeeks.org/problems/mirror-tree/1
*/

class Solution {
  public:
    void mirror(Node* node) {
        if(node == NULL) {
            return;
        }
        
        mirror(node->left);
        mirror(node->right);
        
        Node* temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
};
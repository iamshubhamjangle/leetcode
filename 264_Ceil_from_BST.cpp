/*
Ceil_from_BST.cpp

Ninja is given a binary search tree and an integer. Now he is 
given a particular key in the tree and returns its ceil value. 
Can you help Ninja solve the problem?

https://www.codingninjas.com/codestudio/problems/ceil-from-bst_920464
*/


/**
class BinaryTreeNode {
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;
};
**/

int findCeil(BinaryTreeNode<int> *root, int x){
    int ceil = -1;
    
    while(root != NULL) {
        if(root->data == x) {
            ceil = root->data;
            return ceil;
        }
        
        if(root->data < x) {
            root = root->right;
        } else {
            ceil = root->data;
            root = root->left;
        }
    }
    
    return ceil;
}














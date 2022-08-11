/*
Sum_of_Binary_Tree.cpp

Constraints:
1<=T<=100
1<=N<=100

Input:
2
2
1 2 L 1 -1 N
6
1 2 L 1 3 R 2 -1 N 2 -1 N 3 3 L 3 -1 N
Output:
3
9

https://practice.geeksforgeeks.org/problems/sum-of-binary-tree/1
*/

/*Structure of the node of the binary tree
struct Node
{
	int key;
	Node* left, *right;
};
*/

// Method 1: TC: O(2^n), SC: O(1) ASC: O(N)
long int sumBT(Node* root) {
    if(root == NULL) {
        return 0;
    }
    
    return root -> key + sumBT(root -> left) + sumBT(root -> right);
}

// looking at constraints there will be 1 minimun node so root will never be NULL
// hence lets avoid calls to null pointers.
long int sumBT(Node* root) {
    return root->key + (root->left ? sumBT(root->left) : 0) + (root->right ? sumBT(root->right) : 0);
}
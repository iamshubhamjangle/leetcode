/*
Left_View_of_Binary_Tree.cpp

Given a Binary Tree, print Left view of it. Left view of a Binary Tree is set of nodes 
visible when tree is visited from Left side. The task is to complete the function leftView(), 
which accepts root of the tree as argument.

https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1
*/

/* A binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root) {
    // DFS with first variable
    vector<int> ans;
    if(root==NULL) return ans;
    
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()) {
        int n = q.size();
        int first = -1;
        while(n--) {
            Node* node = q.front(); q.pop();
            
            if(node->left)  q.push(node->left);
            if(node->right) q.push(node->right);
            
            if(first == -1) first = node->data;
        }
        ans.push_back(first);
    }
    
    return ans;
}


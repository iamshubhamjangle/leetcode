/*
Boundary_Traversal_of_Binary_Tree.cpp

class TreeNode {
    public :
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;
}

https://www.codingninjas.com/codestudio/problems/boundary-traversal_790725
*/

void addLeftBoundary(TreeNode* root, vector<int> &res) {
	Node* curr = root->left;
	while(curr != NULL) {
		if(!isLeaf(curr)) res.push_back(curr->data);
		if(curr->left) curr = curr->left;
		else curr = curr->right;
	}
}

void addLeaves(TreeNode* root, vector<int> &res) {
	if(isLeaf(root)) {
		res.push_back(root->data);
		return;
	}
	if(root->left) addLeaves(root->left, res);
	if(root->right) addLeaves(root->right, res);
}

void addRightBoundary(TreeNode* root, vector<int> &res) {
	Node* curr = root->right;
	vector<int> tmp;
	while(curr) {
		if(!isLeaf(curr)) tmp.push_back(curr->data);
		if(curr->right) curr = curr->right;
		else curr = curr->left;
	}
	for(int i=tmp.size()-1, i>=0, --i) {
		res.push_back(tmp[i]);
	}
}

vector<int> traverseBoundary(TreeNode<int>* root){
    vector<int> ans;
    if(root == NULL) return ans;
    if(!isLeaf(root)) ans.push_back(root->data);
    addLeftBoundary(root, ans);
    addLeaves(root, ans);
    addRightBoundary(root, ans);
    return ans;
}


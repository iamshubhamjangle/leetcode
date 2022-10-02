/*
Check_if_a_node_exists_in_BT.cpp
*/
#include <iostream>
using namespace std;

struct Node {
	int data;
	struct Node *left, *right;
	Node(int data)
	{
		this->data = data;
		left = right = NULL;
	}
};

// Function to traverse the tree in preorder
// and check if the given node exists in it
bool ifNodeExists(struct Node* node, int key)
{
	if (node == NULL)
		return false;

	if (node->data == key)
		return true;

	bool res1 = ifNodeExists(node->left, key);
	if(res1) 
		return true;
	
	bool res2 = ifNodeExists(node->right, key);
	return res2;
}

Node* dfs(Node* root, int target) {
	if(root == NULL)
		return NULL;
	
	if(root->data == target)
		return root;

	if(root->left)
		return dfs(root->left, target);

	if(root->right)
		return dfs(root->right, target);

	return NULL;
}

// Driver Code
int main()
{
	struct Node* root = new Node(0);
	root->left = new Node(1);
	root->left->left = new Node(3);
	root->left->left->left = new Node(7);
	root->left->right = new Node(4);
	root->left->right->left = new Node(8);
	root->left->right->right = new Node(9);
	root->right = new Node(2);
	root->right->left = new Node(5);
	root->right->right = new Node(6);

	int key = 4;

	if (ifNodeExists(root, key))
		cout << "YES";
	else
		cout << "NO";

	Node* temp = dfs(root, 8);
	if(temp) cout << "temp: " << temp->data;

	return 0;
}

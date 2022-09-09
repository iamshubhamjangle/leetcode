/*
Floor_in_BST.cpp



https://www.codingninjas.com/codestudio/problems/floor-from-bst_920457
*/

/*
class TreeNode {
   public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;
};
*/

int floorInBST(TreeNode<int> * root, int x) {
    int floor = -1;

    while(root != NULL) {
    	if(root->data == x) {
    		floor = root->data;
    		return floor;
    	}

    	if(root->data < x) {
    		floor = root->data;
    		root = root->right;
    	} else {
    		root = root->left;
    	}
    }

    return floor;
}
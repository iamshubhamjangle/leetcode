/*
Flatten_linked_list.cpp

https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1
*/

/* Node structure  used in the program
struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

5 > 10 > 19 > 28
7	20	 22	  35
8        50   40
30            45

*/



Node* merge(Node* left, Node* right) {
	Node* dummy = new Node(-1);
	Node* temp = dummy;

	while(left && right) {
		if(left->data < right->data) {
			dummy->bottom = left;
			left = left->bottom;
			dummy = dummy->bottom;
		} else {
			dummy->bottom = right;
			dummy = dummy->bottom;
			right = right->bottom;
		}
	}

	if(left) dummy->bottom = left;
	else dummy->bottom = right;

	return temp->bottom;
}


Node *flatten(Node *root) {
   if(!root || !root->next) return root;
   return merge(root, flatten(root->next));
}
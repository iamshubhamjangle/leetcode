/*
Copy_List_with_Random_Pointer.cpp

A linked list of length n is given such that each node contains an additional 
random pointer, which could point to any node in the list, or null.

Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]

Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]

https://leetcode.com/problems/copy-list-with-random-pointer/
	- Method 1: Un-map. TC: O(N) SC: O(N)
	- Method 2: Merge list and copy random. TC: O(N) SC: O(1)

Method 1: Use unorderedmap to store new nodes addr. TC: O(N) SC: O(N)
	- un-map to store addr of copy node corresponding to original node.
	- loop from head to null to create copy nodes and add its addr to un-map 
	- loop from head to null and replicate head->next and head->random values to new list wrt new pointer in un-map 



// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/


class Solution {
public:
	// Method 1: Un-map. TC: O(N) SC: O(N)
    Node* copyRandomList1(Node* head) {
        unordered_map<Node*, Node*> um;     // map to store addr of copy node corresponding to original node.
        Node* temp = head;

        while(temp != NULL) {               // create map of old nodes and newNodes
            Node* newNode = new Node(temp->val);
            um[temp] = newNode;
            temp = temp->next;
        }
        
        temp = head;    // repoint temp to head
        while(temp != NULL) {
            um[temp]->next = um[temp->next];
            um[temp]->random = um[temp->random];
            temp = temp->next;
        }
        
        return um[head];
    }
    
    
    // Method 2: Merge list and copy random. TC: O(N) SC: O(1)
    Node* copyRandomList(Node* head) {
    	if(head == NULL) return NULL;
 
    	Node* temp = head;
    	while(temp != NULL) {
    		Node* newNode = new Node(temp->val);		// Cloned node with same val as head
    		// Insert the cloned node next to the original node
            // If A->B->C is the original linked list,
            // Linked list after weaving cloned nodes would be
            // A->A'->B->B'->C->C'
    		newNode->next = temp->next;
    		temp->next = newNode;
            temp = newNode->next;
    	}

    	// Link random pointers of the newly created nodes
        // and iterate through the newly created list and
        // use original node's random pointers
    	temp = head;
    	while(temp != NULL) {
    		temp->next->random = (temp->random) ? temp->random->next : NULL;
    		temp = temp->next->next;
    	}

    	// Unweave the current linked list to get back the 
        // original linked list and the cloned one.
    	temp = head;        			// A->B->C
    	Node* newList = head->next;		// A'->B'->C'
    	Node* tail = head->next;		// to iterate copied list

    	while(temp != NULL) {
    		temp->next = tail->next;
    		tail->next = tail->next ? tail->next->next : NULL;
    		temp = temp->next;
            tail = tail->next;
    	}

    	return newList;
    }
};


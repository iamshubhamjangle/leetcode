/*
Copy_List_with_Random_Pointer.cpp

https://leetcode.com/problems/copy-list-with-random-pointer/description/

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

// Create the copy of given linkedlist without random. 
// Also keep a map of (curr node addr == corresponding new node addr)
// Start copying random, new node addr can be found from map.
// TC: O(N) SC: O(N)
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;

        unordered_map<Node*, Node*> addr;   // old addr -> new addr
        
        Node* node = head;
        Node* res = new Node(-1);
        Node* dummy = res;

        while(node) {
            dummy->next = new Node(node->val);
            addr[node] = dummy->next;
            node = node->next;
            dummy = dummy->next;
        }

        node = head;
        dummy = res->next;

        while(node) {
            if(node->random)
                dummy->random = addr[node->random];
            else
                dummy->random = NULL;
            node = node->next;
            dummy = dummy->next;
        }

        return res->next;
    }
};





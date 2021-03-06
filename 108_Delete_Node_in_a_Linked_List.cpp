/*
Delete_Node_in_a_Linked_List.cpp

Write a function to delete a node in a singly-linked list. 
You will not be given access to the head of the list, instead you will be given 
access to the node to be deleted directly.

It is guaranteed that the node to be deleted is not a tail node in the list.

Input: head = [4,5,1,9], node = 5
Output: [4,1,9]

Input: head = [4,5,1,9], node = 1
Output: [4,5,9]

237. Delete Node in a Linked List
https://leetcode.com/problems/delete-node-in-a-linked-list/
Method: Swap elements and remove node. TC: O(1) SC: O(1)

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        // If current node is tail node
        if(node->next == NULL) {
            delete node;
            return;
        }
        
        swap(node->val, node->next->val);
        
        ListNode* temp2 = node->next;
        node->next = temp2 -> next;
        delete temp2;
    }
};

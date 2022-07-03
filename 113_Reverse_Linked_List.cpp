/*
Reverse_Linked_List.cpp

Given the head of a singly linked list, reverse the list, and return the reversed list.

Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

Input: head = [1,2]
Output: [2,1]

Input: head = []
Output: []

Constraints:
The number of nodes in the list is the range [0, 5000].
-5000 <= Node.val <= 5000

https://leetcode.com/problems/reverse-linked-list/
	- Method 1: Iterative TC: O(N). SC: O(1)
	- Method 2: Recusive TC: O(N). SC: O(N)


*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // Method 1: Iterative    
    ListNode* reverseList1(ListNode* head) {
        if(head == NULL) return NULL;
        
        ListNode* c = head;
        ListNode* n = head -> next;
        ListNode* p = NULL;
        
        while(c != NULL) {
            c->next = p;
            p = c;
            c = n;
            if(n != NULL)
                n = n -> next;
        }
        
        return p;
    }
    
    // Method 2: Recusive
    ListNode* reverse(ListNode* head) {
        if(head->next == NULL)
            return head;
        
        ListNode* reverseHead = reverse(head -> next);
        head->next->next = head;
        head->next = NULL;
        return reverseHead;
    }
    
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return NULL;
        return reverse(head);
    }
};
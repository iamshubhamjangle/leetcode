/*
Remove_Duplicates_from_Sorted_List.cpp

Given the head of a sorted linked list, delete all duplicates such that 
each element appears only once. Return the linked list sorted as well.

Input: head = [1,1,2]
Output: [1,2]

Input: head = [1,1,2,3,3]
Output: [1,2,3]

https://leetcode.com/problems/remove-duplicates-from-sorted-list/
	- Method 1: Recursion. TC: O(N) SC: O(N)
    - Method 2: Iterative. TC: O(N) SC: O(1)

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

	// Method 1: Recursion. TC: O(N) SC: O(N)
	// - Base condition
	// - Call recusion on head->next to get a newHead without duplicates
	// - We will check if newHead->val == head->val
	// - If yes return newHead else join it with head and return head.
    ListNode* deleteDuplicates(ListNode* head) {
		if(head==NULL || head->next==NULL) 
			return head;

		ListNode* newHead = deleteDuplicates(head->next);

		if(head->val == newHead->val) {
			return newHead;
		} else {
			head -> next = newHead;
			return head;
		}
    }

    // Method 2: Iterative. TC: O(N) SC: O(1)
    ListNode* deleteDuplicates(ListNode* head) {
		if(head==NULL || head->next==NULL) 
			return head;
    	
    	ListNode* h = head;
    	while(h->next != NULL) {
    		if(h->val == h->next->val) {
    			ListNode* del = h->next;
    			h->next = del->next;
    			delete del;
    		} else {
    			h = h->next;
    		}
    	}
    	return head;
    }
};
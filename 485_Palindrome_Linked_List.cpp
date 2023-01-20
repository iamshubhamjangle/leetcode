/*
Palindrome_Linked_List.cpp

https://leetcode.com/problems/palindrome-linked-list/
*/

class Solution {
public:
	// Reverse the linkedlist and return the head
	ListNode* reverseLinkedListFrom(ListNode* node) {
		if(!node || !node->next) return node;

		ListNode* prev = NULL;
		ListNode* curr = node;
		ListNode* temp = curr->next;

		while(curr) {
			curr->next = prev;
			prev = curr;
			curr = temp;
			if(temp) temp = temp->next;
		}

		return prev;
	}

	
    bool isPalindrome(ListNode* head) {
        // Edge cases
        if(head==NULL||head->next==NULL)
            return true;

        // Find the mid using slow
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        // Reverse the list from slow->next
        slow->next = reverseList(slow->next);
        slow = slow->next;
        while(slow!=NULL){
            if(head->val!=slow->val)
                return false;
            head=head->next;
            slow=slow->next;
        }
        return true;
    }
};
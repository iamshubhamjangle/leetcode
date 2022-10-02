/*
Remove_Linked_List_Elements.cpp

Given the head of a linked list and an integer val, remove all the 
nodes of the linked list that has Node.val == val, and return the new head.

Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]

Input: head = [], val = 1
Output: []

https://leetcode.com/problems/remove-linked-list-elements/
Method 1: Iterative. TC: O(N) SC: O(1)
Method 2: Recursive. TC: O(N) SC: O(N)
*/

// Method 1: Iterative. TC: O(N) SC: O(1)
ListNode* removeElements1(ListNode* head, int k) {
    if(head == NULL) return NULL;
    
    ListNode* dummy = new ListNode(-1);
    ListNode* curr = dummy;
    curr->next = head;
    while(curr->next != NULL) {
        if(curr->next->val == k) {
            ListNode* temp = curr->next->next;
            delete curr->next;
            curr->next = temp;
        } else {
            curr = curr->next;
        }
    }
    return dummy->next;
}

// Method 2: Recursive. TC: O(N) SC: O(N)
ListNode* removeElements(ListNode* head, int k) {
    if(head == NULL)
        return head;

    ListNode* newHead = removeElements(head->next, k);
    if(head->val == k) {
    	head->next = NULL;
    	delete head;
        return newHead;
    }
    head -> next = newHead;
    return head;
}
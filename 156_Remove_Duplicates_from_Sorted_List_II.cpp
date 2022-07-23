/*
Remove_Duplicates_from_Sorted_List_II.cpp

Given the head of a sorted linked list, delete all nodes that have duplicate numbers, 
leaving only distinct numbers from the original list. Return the linked list sorted as well.

Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]

Input: head = [1,1,1,2,3]
Output: [2,3]

https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
- Method: Using map. TC: O(N) SC: O(N)
- Method: Using two pointer. TC: O(N) SC: O(1)

*/

// Method: Using map. TC: O(N) SC: O(N)
ListNode* deleteDuplicates(ListNode* head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }
    
    ListNode* temp = head;
    
    unordered_map<int, int> listFrequency;
    for(auto i=temp; i; i=i->next) {
        listFrequency[i->val]++;
    }
    
    ListNode* dummy = new ListNode(INT_MIN);
    dummy->next = head;
    temp = dummy;
    
    while(temp->next != NULL) {
        int valOfNext = temp->next->val;
        if(listFrequency[valOfNext] > 1) {
            temp->next = temp->next->next;
        } else {
            temp=temp->next;
        }
    }
    
    return dummy->next;
}

// Method: Using two pointer. TC: O(N) SC: O(1)
ListNode* deleteDuplicates(ListNode* head) {
	if(head == NULL || head->next == NULL) {
        return head;
    }

	ListNode* dummy = new ListNode(INT_MIN);
	dummy->next = head;

    ListNode* curr = dummy;

    while(curr->next != NULL || curr->next->next != NULL) {
    	if(curr->next->val != curr->next->next->val) {
    		curr = curr->next;
    	} else {
    		int value = curr->next->val;
    		while(curr->next->val == value) {
    			curr->next = curr->next->next;
    		}
    	}
    }

    return dummy->next;
}
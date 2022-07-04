/*
Merge_Two_Sorted_Lists.cpp

- You are given the heads of two sorted linked lists list1 and list2.
- Merge the two lists in a one sorted list. 
  The list should be made by splicing together 
  the nodes of the first two lists.
- Return the head of the merged linked list.

https://leetcode.com/problems/merge-two-sorted-lists/
	- Recursive: TC: O(N), SC: O(M+n)
	- Iterative: TC: O(N), SC: O(1)
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
	// Recursive: TC: O(N), SC: O(M+n)
	ListNode* merge(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;

        if(l1->val < l2->val) {
        	l1->next = merge(l1->next, l2);
        	return l1;
        } else {
        	l2->next = merge(l1, l2->next);
        	return l2;
        }
	}

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    	return merge(l1, l2);
    }


    // // Iterative - 1
    // ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    // 	if(l1==NULL) return l2;
    // 	if(l2==NULL) return l1;
    // 	ListNode* ans;
    // 	ListNode* tail;

    // 	if(l1->val < l2->val) {
    // 		ans = l1;
    // 		tail = l1;
    // 		l1 = l1->next;
    // 	} else {
    // 		ans = l2;
    // 		tail = l2;
    // 		l2 = l2->next;
    // 	}

    // 	while(l1 != NULL && l2 != NULL) {
    // 		if(l1->val < l2->val) {
    // 			tail->next = l1;
    // 			tail = l1;
    // 			l1 = l1->next;
    // 		} else {
    // 			tail->next = l2;
    // 			tail = l2;
    // 			l2 = l2->next;
    // 		}
    // 	}

    // 	if(l1 == NULL) 
    // 		tail->next = l2;
    // 	else 
    // 		tail->next = l1;
    
    // 	return ans;
    // }


    // Iterative TC: O(N) SC: O(1)
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    	if(l1==NULL) return l2;
    	if(l2==NULL) return l1;
    	ListNode* ans = new ListNode(-1);
    	ListNode* tail = ans;

    	while(l1 != NULL && l2 != NULL) {
    		if(l1->val < l2->val) {
    			tail->next = l1;
    			tail = l1;
    			l1 = l1->next;
    		} else {
    			tail->next = l2;
    			tail = l2;
    			l2 = l2->next;
    		}
    	}

    	if(l1 == NULL) 
    		tail->next = l2;
    	else 
    		tail->next = l1;
    
    	return ans->next;
    }
};

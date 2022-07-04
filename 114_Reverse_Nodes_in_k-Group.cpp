/*
Reverse_Nodes_in_k-Group.cpp

Given the head of a linked list, reverse the nodes of the list k at a time, 
and return the modified list.
k is a positive integer and is less than or equal to the length of the linked list. 
If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
You may not alter the values in the list's nodes, only nodes themselves may be changed.

Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]

Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]

https://leetcode.com/problems/reverse-nodes-in-k-group/
	- Method 1: Recusive. TC: O(N) SC: O(N/K)
	reference: https://youtu.be/TeDcLjOOiK4
*/

void reverse(ListNode* s, ListNode* e) {
	// after reverse e will be the head;
	ListNode *p = NULL;
	ListNode *c = s;
	ListNode *n = s->next;

	while(p != e) {
		c->next = p;
		p = c;
		c = n;
		if(n != NULL) n = n->next;
	}
}

// Method 1: Recusive. TC: O(N) SC: O(N/K)
ListNode* reverseKGroup(ListNode* head, int k) {
    if(head == NULL|| head->next == NULL || k==1)
        return head;

	ListNode* s = head;
	ListNode* e = head;
	int inc = k-1;		// no times to increment end pointer

	while(inc--) {
		e = e->next;
		if(e == NULL)	// if size of LL gets < K. while recursive call / initially
			return head;
	}

	ListNode* nextHead = reverseKGroup(e->next, k);
	reverse(s, e);
	s->next = nextHead;
	return e;	// e will be the new node
}


// ===================== Iterative =================== //
void reverse(ListNode* s, ListNode* e) {
	// after reverse e will be the head;
	ListNode *p = NULL;
	ListNode *c = s;
	ListNode *n = s->next;

	while(p != e) {
		c->next = p;
		p = c;
		c = n;
		if(n != NULL) n = n->next;
	}
}

// Method 2: Iterative - space optimized. TC: O(N) SC: O(1)
ListNode* reverseKGroup(ListNode* head, int k) {
    if(head == NULL|| head->next == NULL || k==1)
        return head;
    ListNode* dummy = new ListNode(-1);
    dummy->next = head;		// new head
	ListNode* beforeStart = dummy;
	ListNode* e = head;
	
	int i = 0;
	while(e != NULL) {
		i++;
		if(i%k == 0) {	// is end at correct position as per k
			// reverse the range s - e
			ListNode* s = beforeStart -> next;
			ListNode* temp = e -> next;
			reverse(s, e);	// custom reverse function
			beforeStart -> next = e;
			s -> next = temp;

			beforeStart = s;
			e = temp;
		} else {
			e = e->next;
		}
	}

	return dummy -> next;
}
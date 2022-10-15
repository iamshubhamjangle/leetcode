/*
Delete_the_Middle_Node_of_a_Linked_List.cpp

https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
*/


class Solution {
public:

 	// Method 1: Fast n Slow pointer. 
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next == NULL) return NULL;
	    // we will now have min 2 nodes
        if(head->next->next == NULL) {
            head->next->val = head->val;
            return head->next;
        }
        
        ListNode* slow = head, *fast = head;
        while(fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        if(slow->next) {
            slow->val = slow->next->val;
            slow->next = slow->next->next;        
        }
        
        return head;
    }


	// Method 2: Fast n Slow pointer. Start head from head->next->next so the slow reaches mid-1 hence no swap is needed;
    ListNode* deleteMiddle(ListNode* head) {
        if (head->next == nullptr)
            return nullptr;
        auto slow = head, fast = head->next->next;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }

};
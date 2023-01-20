/*
Rotate_list.cpp

https://leetcode.com/problems/rotate-list/description/
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
// 1. K times remove the last node and add to front. TC: O(k*n) SC: O(1)
// 2. find len and join last to first, break the node. TC: O(n) SC: O(1)
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        ListNode* node = head;
        
        // find length
        int len = 1; 
        while(node->next) len++, node=node->next;

        // point last node to first
        node->next = head;
        
        // we have to go to this node and break the link
        node = head;
        k = len - k%len - 1;

        while(k--) node = node->next;
        ListNode* start = node->next;
        node->next = NULL;

        return start;
    }
};




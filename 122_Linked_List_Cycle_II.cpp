/*
Linked_List_Cycle_II.cpp

Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.
There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.
Do not modify the linked list.

Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1

Input: head = [1,2], pos = 0
Output: tail connects to node index 0

Input: head = [1], pos = -1
Output: no cycle

https://leetcode.com/problems/linked-list-cycle-ii/
Method 1: find common & iterate. TC: O(N) SC: O(1)
    - find a common point in linkedlist loop. then while head != slow/fast iterate
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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if(fast==slow) break;
        }
        
        if(fast==NULL || fast->next==NULL) return NULL;

        // At this point fast=slow will be pointing to a common point in loop,
        // not neccesary it is at cycle beginning
        // to find cycle beginning again take a ptr to head and other at slow/fast
        // loop until ptr1 == ptr2
    
        ListNode* ptr1 = head;
        ListNode* ptr2 = slow;  // point to loop intersection
        while(ptr1 != ptr2) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return ptr1;
    }
};
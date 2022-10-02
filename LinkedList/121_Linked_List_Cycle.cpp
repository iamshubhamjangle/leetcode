/*
Linked_List_Cycle.cpp

Given head, the head of a linked list, determine if the linked list has a cycle in it.
There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
Return true if there is a cycle in the linked list. Otherwise, return false.

Input: head = [3,2,0,-4], pos = 1
Output: true

Input: head = [1,2], pos = 0
Output: true

Input: head = [1], pos = -1
Output: false

https://leetcode.com/problems/linked-list-cycle/
	- Method 1: Using unordered_set. TC: O(N) SC: O(N)
    - Method 2: Using Slow-Fast pointer. TC: O(N) SC: O(1)

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
	// Method 1: Using unordered_set. TC: O(N) SC: O(N)
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return false;
        
        unordered_set<ListNode*> us;
        ListNode* temp = head;
        while(temp != NULL) {
            if(us.find(temp) != us.end()) {
                return true;
            }
            us.insert(temp);
            temp = temp->next;
        }
        
        return false;
    }

    // Method 2: Using Slow-Fast pointer. TC: O(N) SC: O(1)
    // Assuming it mathematically proved that they will meet at some point
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow) return true;
            // At this point fast=slow will be pointing to a common point in loop,
            // not neccesary it is at cycle beginning
        }
        
        return false;
    }
};
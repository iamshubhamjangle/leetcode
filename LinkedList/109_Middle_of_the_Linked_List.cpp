/*
Middle_of_the_Linked_List.cpp

Given the head of a singly linked list, return the middle node of the linked list.
If there are two middle nodes, return the second middle node.

Input: head = [1,2,3,4,5]
Output: [3,4,5]

Input: head = [1,2,3,4,5,6]
Output: [4,5,6]

https://leetcode.com/problems/middle-of-the-linked-list/submissions/
	- Method 1: Two iteration. TC: O(N) SC: O(1)
	- Method 2: Slow & Fast pointer. Single iteration. TC: O(N). SC: O(1)

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
    // Method 1: Two iteration. TC: O(N) SC: O(1)
    ListNode* middleNode1(ListNode* head) {
        ListNode* node = head;
        int n = 0;
        
        while(node != NULL) {
            n++;
            node = node->next;
        }
        
        int half = n/2;
        node = head;
        while(half--) {
            node = node->next;
        }
        
        return node;
    }
    
    // Method 2: Slow & Fast pointer. Single iteration. TC: O(N). SC: O(1)
    ListNode* middleNode(ListNode* head) {
        ListNode* slow;
        ListNode* fast;
        
        while(fast != NULL && fast->next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        return slow;
    }
        
};
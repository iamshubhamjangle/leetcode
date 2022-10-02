/*
Convert_Binary_Number_in_a_Linked_List_to_Integer.cpp
1290. Convert Binary Number in a Linked List to Integer

Given head which is a reference node to a singly-linked list. 
The value of each node in the linked list is either 0 or 1. 
The linked list holds the binary representation of a number.

Return the decimal value of the number in the linked list.

Input: head = [1,0,1]
Output: 5

Input: head = [0]
Output: 0

https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/

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
    // Method 1: TC: O(2N) SC: O(1)
    // Find length and then iterate the linkedlist with ans = ans + 2^(--n)
    int getDecimalValue1(ListNode* head) {
    	ListNode* temp = head;
    	int n = 0;
    	while(temp != NULL) {
    		n++;
    		temp = temp->next;
    	}

    	temp = head;
    	int ans = 0;
    	while(temp != NULL) {
    		ans += (temp->val) * pow(2, --n);
            temp = temp->next;
    	}

    	return ans;
    }


    // Method 2: TC: O(N) SC: O(1)
    int getDecimalValue2(ListNode* head) {
        ListNode *temp = head;
        int ans = 0;
        
        while(temp != NULL) {
            ans *= 2;
            ans += (temp->val);
            temp = temp->next;
        }
        
        return ans;
    }
};
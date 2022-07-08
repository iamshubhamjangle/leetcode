/*
Intersection_of_Two_Linked_Lists.cpp

Given the heads of two singly linked-lists headA and headB, return the node 
at which the two lists intersect. If the two linked lists have no intersection at all, return null.

For example, the following two linked lists begin to intersect at node c1:

https://leetcode.com/problems/intersection-of-two-linked-lists/
Method 1: Bruteforce TC: O(N*M) SC: O(1)
Method 2: Using Hashmap/Hashset TC: O(N) SC: O(N)
Method 3: Length diff TC: O(N) SC: O(1)
Method 4: Iterate opposite TC: O(N) SC: O(1)

Method 1: TC: O(N*M) SC: O(1)
Loop over both linkedlist in O(n*m) fashion.
For each nth element find if n == m. If yes return n; reset list2 after each iteration.
If we reach the end of n return NULL;

Method 2: TC: O(N) SC: O(N)
Iterate list 1, save its address in unordered map/set.
Iterate through list 2, If address of list item 2 exist in list 1 return it. else NULL.

Method 3: TC: O(N) SC: O(1)
If we can make the size of both the linkedlist equal. we can find the common element in single iteration.
Find the length of both linkedlist. make them equal and iterate upto n == m; or return NULL at end.

Method 4: TC: O(N) SC: O(1)
Method 3 can be improved: as lenght(A) + length(B) == length(B) + length(A)
so once a pointer travel list1. move to to list2 and same with b pointer.
In next iteration both pointer will be at same indexes.

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
    // Method 1: Bruteforce. TC: O(N*M) SC: O(1)
    ListNode *getIntersectionNode1(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB==NULL) return NULL;

        ListNode* ptr1 = headA;
        ListNode* ptr2 = headB;

        while(ptr1 != NULL) {
            ptr2 = headB;
            while(ptr2 != NULL) {
                if(ptr1 == ptr2) return ptr1;
                ptr2 = ptr2->next;
            }
            ptr1 = ptr1->next;
        }

        return ptr1;
    }

    // Method 2: Using Hashmap/Hashset TC: O(N) SC: O(N)
    ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB==NULL) return NULL;
        ListNode* ptr1 = headA;
        ListNode* ptr2 = headB;
        unordered_set<ListNode*> us;

        while(ptr1 != NULL) {
            us.insert(ptr1);
            ptr1=ptr1->next;
        }

        while(ptr2 != NULL) {
            if(us.find(ptr2) != us.end()) return ptr2;
            ptr2=ptr2->next;
        }

        return NULL;
    }

    // Method 3: Find length diff and start iterating from same position. TC: O(N) SC: O(1)
    ListNode *getIntersectionNode3(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB==NULL) return NULL;
        ListNode* ptr1 = headA;
        ListNode* ptr2 = headB;

        int lengthA = 0;
        int lengthB = 0;
        
        while(ptr1 != NULL) {
            lengthA++;
            ptr1=ptr1->next;
        }

        while(ptr2 != NULL) {
            lengthB++;
            ptr2=ptr2->next;
        }

        if(lengthA == 0 || lengthB == 0) return NULL;
        
        ptr1 = headA;
        ptr2 = headB;

        int diff = abs(lengthA - lengthB);
        if(lengthA > lengthB) {
            while(diff--) ptr1 = ptr1->next;
        } 
        else if(lengthB > lengthA) {
            while(diff--) ptr2 = ptr2->next;
        }

        while(ptr1 != NULL && ptr2 != NULL) {
            if(ptr1 == ptr2) return ptr1;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

        return NULL;
    }

    // Method 4: TC: O(N) SC: O(1)
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* ptr1 = headA;
        ListNode* ptr2 = headB;

        while(ptr1 != ptr2) {
            if(ptr1 == NULL) ptr1 = headB;
            else ptr1 = ptr1->next;

            if(ptr2 == NULL) ptr2 = headA;
            else ptr2 = ptr2->next;
        }

        return ptr1;
    }
};
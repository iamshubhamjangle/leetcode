/*
Merge_k_Sorted_Lists.cpp

You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]

Input: lists = []
Output: []

https://leetcode.com/problems/merge-k-sorted-lists/
Method 1: TC: O(NKlog(NK)) SC: O(NK)
    - Insert all nodes to array, sort it.
    - Put it back to new ListNode*

Method 2: TC: O(logNK) SC: O(NK)
    - Use min heap with K size maintained.
    - Keep adding element to minheap and pop() them to new ListNode*

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



// class comparator with operator overloaded
class cpm {
public:
    bool operator () (ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

// Method 2: TC: O(logNK) SC: O(NK)
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Method 2: TC: O(logNK) SC: O(NK)
        priority_queue<ListNode*, vector<ListNode*>, cpm> pq;
        ListNode* dummy = new ListNode(-1);     // output ans
        ListNode* tail  = dummy;                // to add element to output

        for(int i=0; i<lists.size(); i++) {     // push the first nodes of all k LinkedList to pq
            if(lists[i] != NULL)
                pq.push(lists[i]);
        }

        while(pq.size()) {
            ListNode* temp = pq.top();  // get smallest node
            tail->next= temp;           // add it to tail
            tail = temp;                // tail will point to last
            pq.pop();                   // remove the element from pq
            if(temp -> next != NULL) pq.push(temp->next);
        }

        return dummy -> next;
    }
};
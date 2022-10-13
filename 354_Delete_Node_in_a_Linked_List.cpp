/*
Delete_Node_in_a_Linked_List.cpp

https://leetcode.com/problems/delete-node-in-a-linked-list/
TC: O(1) SC: O(1)
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
    void deleteNode(ListNode* node) {
        ListNode* dup = node->next;
        node->val = node->next->val;
        node->next = node->next->next;
        delete dup;
    }
    
//     void deleteNode(ListNode* node) {
//         // If current node is tail node
//         if(node->next == NULL) {
//             delete node;
//             return;
//         }
        
//         swap(node->val, node->next->val);
        
//         ListNode* temp2 = node->next;
//         node->next = temp2 -> next;
//         delete temp2;
//     }
// };
};
/*
Remove_duplicates_from_an_unsorted_linked_list.cpp

https://www.codingninjas.com/codestudio/problems/remove-duplicates-from-unsorted-linked-list_1069331?leftPanelTab=0
Method: Unorderedset. TC: O(N) SC: O(N)
*/

// Method: Unorderedset. TC: O(N) SC: O(N)
Node *removeDuplicates(Node *head) {
    if(head == NULL || head->next == NULL)
        return head;
    
    unordered_set<int> us;
    
    Node* dummy = new Node(INT_MIN);
    dummy->next = head;
    
    Node* curr = dummy;
    while(curr != NULL and curr->next != NULL) {
        if(us.find(curr->next->data) != us.end()) {
            curr->next = curr->next->next;
        } else {
            us.insert(curr->next->data);
            curr = curr->next;
        }    
    }    
    
    return dummy->next;
}
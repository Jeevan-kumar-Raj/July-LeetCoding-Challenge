Day-6 Remove Linked List Elements.cpp

/*
Remove all elements from a linked list of integers that have value val.

Example:

Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5


*/

// Time:  O(n)
// Space: O(1)
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        for (auto *indirect = &head; *indirect != nullptr; ) {
            if ((*indirect)->val == val) {
                *indirect = (*indirect)->next;
                continue;
            }
            indirect = &((*indirect)->next) ; 
        }
        return head;
    }
};
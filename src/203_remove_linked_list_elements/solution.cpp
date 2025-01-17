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
    ListNode* removeElements(ListNode* head, int val) {
    ListNode *previous = nullptr;
    ListNode *current = head;
    while (current != nullptr) {
        if (current->val == val) {
            ListNode *next = current->next;
            delete current;
            current = next;
            if (previous != nullptr) {
                previous->next = current;
            } else {
                head = current;
            }
        } else {
            previous = current;
            current = current->next;
        }
    }
    return head;
    }
};

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
    void reorderList(ListNode* head) {
        ListNode *dummyHead = head;
        std::stack<ListNode*>stk;
        int size {};
        while(dummyHead!=nullptr) {
            stk.push(dummyHead);
            dummyHead = dummyHead->next;
            size++;
        }
        int currentSize{};
        dummyHead = head;
        ListNode *dummyNode;
        while(currentSize != size) {
            if (currentSize % 2 == 0) {
                dummyNode = dummyHead->next;
                dummyHead->next = stk.top();
                stk.pop();
            }
            else {
                dummyHead->next = dummyNode;
            }
            currentSize++;
            dummyHead = dummyHead->next;   
        }
        dummyHead->next = nullptr;
    }
};

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

 int getListSize(ListNode *head) {
    int size{};
    while(head != nullptr) {
        size++;
        head = head->next;
    }
    return size;
 }
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* answer = head;
        ListNode* previous;
        ListNode *nodeToChangeNext;
        int size = getListSize(head);
        if (k == 0 || size == 0) return head;
        k = k % size;
        int position {};
        bool passed {};
        for (int i {}; i < k; i++) {
            head = answer;
            while (head != nullptr) {
                previous = head;
                if (position == size - 2) {
                    std::cout << head->val << std::endl;
                    nodeToChangeNext = head;
                    passed = true;
                }
                head = head->next;
                position++;
                if (head == nullptr) {
                    if (passed) 
                      nodeToChangeNext->next = nullptr; 
                    answer = new ListNode(previous->val, answer);
                    position = 0;
                }
            }
        }
        return answer;
    }
};

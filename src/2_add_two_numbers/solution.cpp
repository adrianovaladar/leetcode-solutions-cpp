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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *answer = new ListNode();
        ListNode *dummy = answer;
        int carry {};
        while(l1!= nullptr || l2 != nullptr || carry != 0) {
            int value {};
            if (l1 != nullptr) {
                value += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                value += l2->val;
                l2 = l2->next;
            }
            if (carry != 0) {
                value +=carry;
                carry = 0;
            }
            while (value >= 10) {
                carry = value / 10;
                value %= 10;
            }            
            dummy->next = new ListNode(value);
            dummy = dummy->next;
        }
    return answer->next;
    }
};

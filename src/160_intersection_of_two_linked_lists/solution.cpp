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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        std::map<ListNode *,int> occurrences;
        while(headA != nullptr) {
            occurrences[headA]++;
            headA = headA->next;
        }
         while(headB != nullptr) {
            if (occurrences.find(headB) != occurrences.end())
                return headB;
            occurrences[headB]++;
            headB = headB->next;

        }
        return nullptr;
    }
};

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
    ListNode* sortList(ListNode* head) {
        if (head == nullptr) return nullptr;
        vector<ListNode*>answer;
        while(head != nullptr) {
            answer.emplace_back(head);
            head = head->next;
        }
        sort(answer.begin(), answer.end(), [](ListNode *a, ListNode *b) {return a->val <b->val;});
        for(int i {}; i < answer.size(); i++) {
            if (i == answer.size()-1)
                answer.at(i)->next = nullptr;
            else
                answer.at(i)->next = answer.at(i+1);
        }
        return answer.at(0);

    }
};

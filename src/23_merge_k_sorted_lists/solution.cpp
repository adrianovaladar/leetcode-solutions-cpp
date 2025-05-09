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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
        std::priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> minHeap(cmp);        
        for (const auto list : lists) {
            if (list != nullptr) {
                minHeap.push(list);
            }
        }
        ListNode *answer = new ListNode(0);
        ListNode *dummyAnswer = answer;
        while (!minHeap.empty()) {
            auto list = minHeap.top();
            minHeap.pop();
            dummyAnswer->next = list;
            dummyAnswer = dummyAnswer->next;
            list = list->next;
            if (list != nullptr)
                minHeap.push(list);
        }
        
        return answer->next;
    }
};

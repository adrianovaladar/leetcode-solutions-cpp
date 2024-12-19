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
    bool hasCycle(ListNode *head) {
        std::set<ListNode*> setNodes;
        while (head != nullptr) {
            if (setNodes.find(head) != setNodes.end()) return true;
            setNodes.insert(head);
            head = head->next;
        }
        return false;
    }
};

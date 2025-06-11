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
    bool isPalindrome(ListNode* head) {
        std::vector<int> nums;
        while (head != nullptr) {
            nums.emplace_back(head->val); 
            head = head->next;
        }
        int left {};
        int right = nums.size() - 1;
        while (left < right) {
            if (nums[left] != nums[right]) return false;
            --right;
            ++left;
        }
        return true;
    }
};

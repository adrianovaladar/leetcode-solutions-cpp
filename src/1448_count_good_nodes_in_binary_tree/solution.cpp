/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void goodNodes(TreeNode* root, int maxValueSeen, int &answer) {
        if (root == nullptr) return;
        if (root->val >= maxValueSeen) answer++;
        if (root->val > maxValueSeen) maxValueSeen = root->val;
        goodNodes(root->left, maxValueSeen, answer);
        goodNodes(root->right, maxValueSeen, answer);
    }
    
public:
    int goodNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        int answer{}; // root is always a good node
        goodNodes(root, root->val, answer);
        return answer;
    }
};

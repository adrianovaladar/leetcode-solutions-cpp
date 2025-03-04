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
    void dfs(TreeNode* root, int level, std::vector<int> &answer) {
        if (root == nullptr) return;
        if(level == answer.size()) answer.emplace_back(root->val);
        dfs(root->right, level + 1, answer);
        dfs(root->left, level + 1, answer);
    }

public:
    vector<int> rightSideView(TreeNode* root) {
        std::vector<int> answer;
        dfs(root, 0, answer);
        return answer;
    }
};

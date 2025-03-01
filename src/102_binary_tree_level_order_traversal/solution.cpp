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
public:
    std::vector<std::vector<int>> answer;
    int level {};
    vector<vector<int>> levelOrder(TreeNode* root) {
        dfs(root, 0);
        return answer;
    }

    void dfs(TreeNode* node, int level) {
        if (!node) return;
        if (level == answer.size()) {
            answer.push_back({});
        }
        answer[level].push_back(node->val);
        dfs(node->left, level + 1);
        dfs(node->right, level + 1);
    }
};

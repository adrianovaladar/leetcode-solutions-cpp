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
    std::vector<int> answer;
    void dfs(TreeNode *root) {
        if (root == nullptr) return;
        dfs(root->left);
        answer.emplace_back(root->val);
        dfs(root->right);
    }

public:
    vector<int> inorderTraversal(TreeNode* root) {
        dfs(root);
        return answer;
    }
};
